#include "AttributeDialog.h"
#include "ui_AttributeDialog.h"

AttributeDialog::AttributeDialog(QWidget *parent) : QDialog(parent),
                                                    ui(new Ui::AttributeDialog)
{
    ui->setupUi(this);
    // 设置字体与背景颜色
    this->setStyleSheet("font: 9pt 幼圆;" +
                        QString("background-color: rgb(%1, %2, %3);").arg(QDialog::window()->palette().color(QPalette::Window).red()).arg(QDialog::window()->palette().color(QPalette::Window).green()).arg(QDialog::window()->palette().color(QPalette::Window).blue()));
    // 设置最小窗口大小
    this->setMinimumSize(QSize(624, 424));
    // 设置默认界面
    ui->stackedWidget->setCurrentIndex(0);
    // 添加下拉栏按键
    ui->colorComboBox->addItem("颜色");
    ui->colorComboBox->addItem("大小");
    ui->pointSizeComboBox->addItem("颜色");
    ui->pointSizeComboBox->addItem("大小");
    ui->lineSizeComboBox->addItem("颜色");
    ui->lineSizeComboBox->addItem("大小");
    ui->rectangleSizeComboBox->addItem("颜色");
    ui->rectangleSizeComboBox->addItem("大小");
    ui->circleSizeComboBox->addItem("颜色");
    ui->circleSizeComboBox->addItem("大小");
    ui->sectorSizeComboBox->addItem("颜色");
    ui->sectorSizeComboBox->addItem("大小");
    ui->curveSizeComboBox->addItem("颜色");
    ui->curveSizeComboBox->addItem("大小");
    ui->fontComboBox->addItem("颜色");
    ui->fontComboBox->addItem("大小");
    void (QComboBox::*currentIndexChanged)(int val) = &QComboBox::currentIndexChanged;
    // 下拉栏选择改变，切换对话框界面
    connect(ui->colorComboBox, currentIndexChanged, [=](int val)
            {
        if (val == 0)
        {
            //切换至颜色界面
            ui->stackedWidget->setCurrentIndex(0);
        }
        else if (val == 1 && state == this->DrawPointState)
        {
            //切换至点大小界面
            ui->stackedWidget->setCurrentIndex(1);
            ui->pointSizeComboBox->setCurrentIndex(1);
        }
        else if (val == 1 && state == this->DrawLineState)
        {
            //切换至线大小界面
            ui->stackedWidget->setCurrentIndex(2);
            ui->lineSizeComboBox->setCurrentIndex(1);
        }
        else if (val == 1 && state == this->DrawPolylineState)
        {
            //切换至折线大小界面
            ui->stackedWidget->setCurrentIndex(3);
        }
        else if (val == 1 && state == this->DrawRectangleState)
        {
            //切换至矩形大小界面
            ui->stackedWidget->setCurrentIndex(4);
            ui->rectangleSizeComboBox->setCurrentIndex(1);
        }
        else if (val == 1 && state == this->DrawCircleState)
        {
            //切换至圆大小界面
            ui->stackedWidget->setCurrentIndex(5);
            ui->circleSizeComboBox->setCurrentIndex(1);
        }
        else if (val == 1 && state == this->DrawSectorState)
        {
            //切换至扇形大小界面
            ui->stackedWidget->setCurrentIndex(6);
            ui->sectorSizeComboBox->setCurrentIndex(1);
        }
        else if (val == 1 && state == this->DrawPolygonState)
        {
            //切换至多边形大小界面
            ui->stackedWidget->setCurrentIndex(7);
        }
        else if (val == 1 && state == this->DrawCurveState)
        {
            //切换至贝塞尔曲线大小界面
            ui->stackedWidget->setCurrentIndex(8);
            ui->curveSizeComboBox->setCurrentIndex(1);
        }
        else if (val == 1 && state == this->DrawTextState)
        {
            //切换至字体界面
            ui->stackedWidget->setCurrentIndex(9);
            ui->fontComboBox->setCurrentIndex(1);
        }
        else if (val == 1 && state == this->DrawPixmapState)
        {
            //切换至图像界面
            ui->stackedWidget->setCurrentIndex(10);
            ui->curveSizeComboBox->setCurrentIndex(1);
        } });
    // 下拉栏选择改变，切换对话框界面
    connect(ui->pointSizeComboBox, currentIndexChanged, [=](int val)
            {
        if (val == 0)
        {
            //切换至颜色界面
            ui->stackedWidget->setCurrentIndex(0);
            ui->colorComboBox->setCurrentIndex(0);
        }
        else if (val == 1 && state == this->DrawPointState)
        {
            //切换至点大小界面
            ui->stackedWidget->setCurrentIndex(1);
        } });
    // 下拉栏选择改变，切换对话框界面
    connect(ui->lineSizeComboBox, currentIndexChanged, [=](int val)
            {
        if (val == 0)
        {
            //切换至颜色界面
            ui->stackedWidget->setCurrentIndex(0);
            ui->colorComboBox->setCurrentIndex(0);
        }
        else if (val == 1 && state == this->DrawLineState)
        {
            //切换至线大小界面
            ui->stackedWidget->setCurrentIndex(2);
        } });
    // 下拉栏选择改变，切换对话框界面
    connect(ui->rectangleSizeComboBox, currentIndexChanged, [=](int val)
            {
        if (val == 0)
        {
            //切换至颜色界面
            ui->stackedWidget->setCurrentIndex(0);
            ui->colorComboBox->setCurrentIndex(0);
        }
        else if (val == 1 && state == this->DrawRectangleState)
        {
            //切换至矩形大小界面
            ui->stackedWidget->setCurrentIndex(4);
        } });
    // 下拉栏选择改变，切换对话框界面
    connect(ui->circleSizeComboBox, currentIndexChanged, [=](int val)
            {
        if (val == 0)
        {
            //切换至颜色界面
            ui->stackedWidget->setCurrentIndex(0);
            ui->colorComboBox->setCurrentIndex(0);
        }
        else if (val == 1 && state == this->DrawCircleState)
        {
            //切换至圆大小界面
            ui->stackedWidget->setCurrentIndex(5);
        } });
    // 下拉栏选择改变，切换对话框界面
    connect(ui->sectorSizeComboBox, currentIndexChanged, [=](int val)
            {
        if (val == 0)
        {
            //切换至颜色界面
            ui->stackedWidget->setCurrentIndex(0);
            ui->colorComboBox->setCurrentIndex(0);
        }
        else if (val == 1 && state == this->DrawSectorState)
        {
            //切换至扇形大小界面
            ui->stackedWidget->setCurrentIndex(6);
        } });
    // 下拉栏选择改变，切换对话框界面
    connect(ui->curveSizeComboBox, currentIndexChanged, [=](int val)
            {
        if (val == 0)
        {
            //切换至颜色界面
            ui->stackedWidget->setCurrentIndex(0);
            ui->colorComboBox->setCurrentIndex(0);
        }
        else if (val == 1 && state == this->DrawCurveState)
        {
            //切换至曲线大小界面
            ui->stackedWidget->setCurrentIndex(8);
        } });
    // 下拉栏选择改变，切换对话框界面
    connect(ui->fontComboBox, currentIndexChanged, [=](int val)
            {
        if (val == 0)
        {
            //切换至颜色界面
            ui->stackedWidget->setCurrentIndex(0);
            ui->colorComboBox->setCurrentIndex(0);
        }
        else if (val == 1 && state == this->DrawTextState)
        {
            //切换至字体界面
            ui->stackedWidget->setCurrentIndex(9);
        } });
}

AttributeDialog::~AttributeDialog()
{
    delete ui;
}

void AttributeDialog::setState(DrawState state)
{
    this->state = state;
}
