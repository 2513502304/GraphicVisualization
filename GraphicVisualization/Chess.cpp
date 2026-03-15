#include "Chess.h"

Chessman::Chessman(int x, int y, char color)
{
	this->x = x;
	this->y = y;
	if (color == 'W')
		this->color = QColor(Qt::GlobalColor::white);
	else if (color == 'G')
		this->color = QColor(Qt::GlobalColor::green);
	else if (color == 'R')
		this->color = QColor(Qt::GlobalColor::red);
	else if (color == 'B')
		this->color = QColor(Qt::GlobalColor::blue);
	else
		this->color = QColor(Qt::GlobalColor::black);
}

ChessBoard::ChessBoard(const string &file)
{
	// 读取棋盘
	this->readChessBoard(file);
}

// 读取棋盘
void ChessBoard::readChessBoard(const string &file)
{
	// 文件流
	ifstream in(file);
	// 当前行
	string line;
	// 读取行数和列数
	in >> this->row >> this->col >> ws;
	// 重塑棋盘大小
	this->board = vector<vector<Chessman>>(this->row, vector<Chessman>(this->col));
	// 读取棋盘
	for (int i = 0; i < row; i++)
	{
		// 读取一行
		getline(in, line, '\n');
		istringstream is(line);
		for (int j = 0; j < col; j++)
		{
			char color = is.get();
			this->board[i][j] = Chessman(i, j, color);
		}
	}
	// 关闭文件
	in.close();
}

// 深度优先搜索
void ChessBoard::dfs(int i, int j, int &area)
{
	// 四个方向的偏移量 —— 左、下、右、上
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	//! 第一个位置奠定了当前要找寻的颜色类型，无特定的条件进行限定，而后续所有要找寻的颜色类型都需要以此为准，否则不进行下一步
	// 标记当前位置为已访问
	this->visited[i][j] = true;
	// 增加当前区域的面积
	area++;
	// 遍历四个方向
	for (int k = 0; k < 4; k++)
	{
		// 新位置
		int ni = i + dx[k], nj = j + dy[k];
		//! 如果新位置在棋盘内，且未被访问过，且颜色相同，则继续搜索（保障了只有四个方向之一的某个颜色与当前要找寻的颜色类型相同时，才继续 dfs，否则不会对其进行访问，因此也不需要回溯）
		if (ni >= 0 && ni < this->row && nj >= 0 && nj < this->col && !visited[ni][nj] && this->board[ni][nj].color == this->board[i][j].color)
		{
			this->dfs(ni, nj, area);
		}
	}
}

// 求最大涂色区域
void ChessBoard::findMaxArea()
{
	// 初始化最大涂色区域面积
	this->maxAreaSize = 0;
	// 遍历棋盘
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			// 如果当前位置未被访问过，则开始新的搜索
			if (!this->visited[i][j])
			{
				// 初始化访问标记
				this->visited = vector<vector<bool>>(this->row, vector<bool>(this->col, false));
				// 深度优先搜索
				int area = 0;
				this->dfs(i, j, area);
				// 如果当前区域的面积大于最大面积，则更新最大区域和最大面积
				if (area > this->maxAreaSize)
				{
					// 更新最大涂色区域
					this->maxArea = this->visited;
					// 更新最大涂色区域面积
					this->maxAreaSize = area;
				}
			}
		}
	}
}
