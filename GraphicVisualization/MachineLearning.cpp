#include "MachineLearning.h"

MachineLearning::MachineLearning(QObject *parent)
	: QObject(parent)
{
}

MachineLearning::~MachineLearning()
{
}

DecisionTreeProxy::DecisionTreeProxy()
{
}

DecisionTreeProxy::~DecisionTreeProxy()
{
}

// 初始化预测界面
void DecisionTreeProxy::initPredictWidget()
{
	// 创建一个新的 QWidget
	QWidget *widget = new QWidget(nullptr);
	// 设置 QWidget 的标题
	widget->setWindowTitle("Decision Tree");
	// 设置 QWidget 的样式
	widget->setStyleSheet(WidgetStyleSheet);
	// 创建一个新的水平布局管理器
	QHBoxLayout *layout = new QHBoxLayout(widget);
	// ComboBox 响应
	void (QComboBox::*currentIndexChanged)(int val) = &QComboBox::currentIndexChanged;
	// 遍历每个特征字段
	for (const string &field : this->tree.featureFields)
	{
		// 创建一个标签，并设置其文本为字段名称
		QLabel *label = new QLabel(QString::fromStdString(field), this->tableWidget.get());
		// 创建一个下拉框
		QComboBox *comboBox = new QComboBox(this->tableWidget.get());
		// 设置样式
		comboBox->setStyleSheet(ComboBoxStyleSheet);
		// 获取字段的数据
		vector<string> fieldData = this->tree.table[field];
		// 计算字段的唯一值
		set<string> uniqueValues(fieldData.begin(), fieldData.end());
		// 遍历每个唯一值
		for (const auto &value : uniqueValues)
		{
			// 将唯一值添加到下拉框中
			comboBox->addItems(QStringList() << QString::fromStdString(value));
			// 初始化预测样本
			this->tree.predictSample[field] = value;
		}
		// 将标签和下拉框添加到水平布局管理器中
		layout->addWidget(label);
		layout->addWidget(comboBox);
		// 绑定下拉框响应事件
		connect(comboBox, currentIndexChanged, [=](int val)
				{
				// 获取当前下拉框的值
				string value = comboBox->itemText(val).toStdString();
				// 更新预测样本
				this->tree.predictSample[field] = value; });
		// 设置当前下拉框的值
		comboBox->setCurrentIndex(0);
		// 为避免当前下拉框的值已为 0 而不会触发上述槽函数的 currentIndexChanged 信号，这里手动设置当前预测样本的值（This signal is sent whenever the currentIndex in the combobox changes either through user interaction or programmatically. The item's index is passed or -1 if the combobox becomes empty or the currentIndex was reset）
		this->tree.predictSample[field] = comboBox->itemText(0).toStdString();
	}
	// 添加预测按钮
	QPushButton *button = new QPushButton("Predict");
	// 设置样式
	button->setStyleSheet(PushButtonStyleSheet);
	// 将按钮添加到水平布局管理器中
	layout->addWidget(button);
	// 构建决策树
	this->node = this->tree.buildTree(DecisionTree::CRITERION::ENTROPYC45, this->tree.table, this->tree.targetFields, this->tree.featureFields, 5);
	// 发送绘制决策树信号
	emit this->drawDecisionTreeSignal(this->node);
	// 预测按钮响应事件
	connect(button, &QPushButton::clicked, [=]()
			{
			// 预测目标值
			string predictTarget = this->tree.predict(this->node, this->tree.predictSample);
			// 显示预测结果
			QMessageBox::information(nullptr, tr("Prediction"), QString("%1: %2").arg(QString::fromStdString(this->tree.targetFields)).arg(QString::fromStdString(predictTarget)), QMessageBox::Yes); });
	widget->setLayout(layout);
	widget->show();
}

// 设置目标字段
void DecisionTreeProxy::setTargetField(int column)
{
	// 获取目标字段
	string targetField = this->tableWidget->horizontalHeaderItem(column)->text().toStdString();
	QMessageBox::information(nullptr, tr("Target Field"), QString::fromStdString(targetField), QMessageBox::Yes);
	// 设置目标字段
	this->tree.targetFields = targetField;
	// 更新特征字段
	this->tree.featureFields.clear();
	// 遍历每个字段
	for (const auto &p : this->tree.table)
	{
		// 如果当前字段不是目标字段，则将其添加到特征字段中
		if (p.first != targetField)
		{
			this->tree.featureFields.push_back(p.first);
		}
	}
	// 初始化预测界面
	this->initPredictWidget();
}

// 初始化表头菜单
void DecisionTreeProxy::initHeaderMenu(QHeaderView *header)
{
	// 创建一个新的上下文菜单
	QMenu *menu = new QMenu(this->tableWidget.get());
	// 启用表头的上下文菜单
	header->setContextMenuPolicy(Qt::CustomContextMenu);
	// 当右键点击表头时，显示上下文菜单
	connect(header, &QHeaderView::customContextMenuRequested, [=](const QPoint &pos)
			{ menu->popup(QCursor::pos()); });
	// 选择目标字段菜单项
	QAction *action = new QAction("选择目标字段", menu);
	action->setIcon(QIcon(":/选择.png"));
	// 当菜单项被触发时，将当前列设置为目标字段
	connect(action, &QAction::triggered, [=]()
			{
			int column = header->logicalIndexAt(header->mapFromGlobal(QCursor::pos()));
			QMessageBox::information(nullptr, tr("Column"), QString::number(column), QMessageBox::Yes);
			this->setTargetField(column); });
	// 将菜单项添加到上下文菜单
	menu->addAction(action);
}

// 初始化表格
void DecisionTreeProxy::initTable()
{
	// 初始化表格
	this->tableWidget = make_shared<QTableWidget>();
	// 获取文件名称
	QString fileName = this->filePath.split("/").last();
	// 设置表格的标题
	this->tableWidget->setWindowTitle(fileName);
	// 设置表格的样式
	this->tableWidget->setStyleSheet(TableWidgetStyleSheet);
	// 表头字段
	QStringList sl;
	// 表大小
	QSize size = QSize(this->tree.table.begin()->second.size(), this->tree.table.size());
	// 设置表格的列数
	this->tableWidget->setColumnCount(size.height());
	// 设置表格的行数
	for (int i = 0; i < size.width(); i++)
	{
		// 添加一个新的行
		tableWidget->insertRow(i);
	}
	int col = 0;
	// 遍历表格的每一个字段
	for (const auto &p : this->tree.table)
	{
		int row = 0;
		string key = p.first;
		sl << QString::fromStdString(key);
		vector<string> fields = p.second;
		// 遍历每一个字段的值
		for (auto &field : fields)
		{
			// 创建一个新的 QTableWidgetItem
			QTableWidgetItem *item = new QTableWidgetItem();
			item->setText(QString::fromStdString(field));
			// 将 QTableWidgetItem 添加到 QTableWidget
			tableWidget->setItem(row++, col, item);
		}
		col++;
	}
	// 设置表头字段
	this->tableWidget->setHorizontalHeaderLabels(sl);
	// 初始化表头菜单
	this->initHeaderMenu(this->tableWidget->horizontalHeader());
}

// 初始化决策树
void DecisionTreeProxy::initDecisionTree()
{
	// 读取文件
	this->filePath = QFileDialog::getOpenFileName(nullptr, tr("Open File"), "", tr("CSV Files(*.csv)"));
	if (this->filePath.isEmpty())
	{
		QMessageBox::warning(nullptr, tr("Warning"), tr("No File Selected!"), QMessageBox::Yes);
		return;
	}
	// 创建决策树
	this->tree = DecisionTree(this->filePath.toStdString());
	// 初始化属性字段窗口
	this->initTable();
	// 初始化属性字段窗口大小
	this->tableWidget->setFixedSize(QSize(800, 600));
	// 显示属性字段窗口
	this->tableWidget->show();
}