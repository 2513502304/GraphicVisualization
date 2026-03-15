#include "ConvexHull.h"

ConvexHull::ConvexHull(const vector<QPointF> &points)
{
	// 初始化凸包点
	this->points = points;
}

ConvexHull::ConvexHull(const string &file)
{
	// 读取点坐标
	this->readPoint(file);
}

// 读取点坐标
void ConvexHull::readPoint(const string &file)
{
	// 文件流
	ifstream in(file);
	// 当前行
	string line;
	// 读取点个数
	int count;
	in >> count >> ws;
	// 重塑凸包点大小
	this->points = vector<QPointF>(count);
	// 读取点
	for (int i = 0; i < count; i++)
	{
		getline(in, line, '\n');
		istringstream is(line);
		int x, y;
		is >> x >> y;
		this->points[i].setX(x);
		this->points[i].setY(y);
	}
	// 关闭文件
	in.close();
}

// 寻找边界点
void ConvexHull::findBoundaryPoints()
{
	// 初始化边界点
	this->leftPoint = this->points[0];
	this->rightPoint = this->points[0];
	this->topPoint = this->points[0];
	this->bottomPoint = this->points[0];
	// 遍历所有凸包
	for (int i = 0; i < this->points.size(); i++)
	{
		// 更新左边的点
		if (this->points[i].x() <= this->leftPoint.x())
		{
			this->leftPoint = this->points[i];
			this->leftPointIndex = i;
		}
		// 更新右边的点
		if (this->points[i].x() >= this->rightPoint.x())
		{
			this->rightPoint = this->points[i];
			this->rightPointIndex = i;
		}
		// 更新顶部的点
		if (this->points[i].y() <= this->topPoint.y())
		{
			this->topPoint = this->points[i];
			this->topPointIndex = i;
		}
		// 更新底部的点
		if (this->points[i].y() >= this->bottomPoint.y())
		{
			this->bottomPoint = this->points[i];
			this->bottomPointIndex = i;
		}
	}
}

// 检测有序点方向
// To find orientation of ordered triplet (p1, p2, p3)
// The function returns following values
//		0 --> p, q and r are collinear
//		1 --> Clockwise
//		2 --> Counterclockwise
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// 平面中点的有序三元组的方向可以是
//		反时针
//		顺时针
//		共线
// 如果 (p1, p2, p3) 共线，则 (p3, p2, p1) 也共线
// 如果 (p1, p2, p3) 方向为顺时针，则 (p3, p2, p1) 方向为逆时针，反之亦然
// 1. 使用叉积：
// 算法思想：
//		val = (p2 - p1) x (p3 - p2) = (x2 - x1, y2 - y1) x (x3 - x2, y3 - y2) = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2)
//		if val == 0, then the three points are collinear
//		if val > 0, then the orientation is clockwise
//		if val < 0, then the orientation is counterclockwise
// 2. 使用斜率
// 算法思想：
//		Slope of line segment (p1, p2): ? = (y2 - y1)/(x2 - x1)
//		Slope of line segment (p2, p3): ? = (y3 - y2)/(x3 - x2)
//		If ? > ? , the orientation is clockwise(right turn)
//		Using above values of ? and ? , we can conclude that, the orientation depends on sign of below expression : (y2 - y1)* (x3 - x2) - (y3 - y2) * (x2 - x1)
//		Above expression is negative when ? < ? , i.e., counterclockwise
ConvexHull::ORIENTATION ConvexHull::orientation(const QPointF &p1, const QPointF &p2, const QPointF &p3)
{
	// ----------------------------------- 叉积法 -----------------------------------
	auto crossProduct = [=](const QPointF &p1, const QPointF &p2, const QPointF &p3)
	{
		int val = (p2.y() - p1.y()) * (p3.x() - p2.x()) - (p2.x() - p1.x()) * (p3.y() - p2.y());
		if (val == 0)
		{
			return ConvexHull::ORIENTATION::COLLINEAR;
		}
		return (val > 0) ? ConvexHull::ORIENTATION::CLOCKWISE : ConvexHull::ORIENTATION::COUNTERCLOCKWISE;
	};
	// -----------------------------------  斜率法 -----------------------------------
	auto slope = [=](const QPointF &p1, const QPointF &p2, const QPointF &p3)
	{
		int slope1 = (p2.y() - p1.y()) / (p2.x() - p1.x());
		int slope2 = (p3.y() - p2.y()) / (p3.x() - p2.x());
		if (slope1 == slope2)
		{
			return ConvexHull::ORIENTATION::COLLINEAR;
		}
		return (slope1 > slope2) ? ConvexHull::ORIENTATION::CLOCKWISE : ConvexHull::ORIENTATION::COUNTERCLOCKWISE;
	};
	return crossProduct(p1, p2, p3);
	return slope(p1, p2, p3);
}

// 给定三个共线点 p、q、r，检查点 q 是否位于线段 pr 上
bool ConvexHull::onSegment(const QPointF &p, const QPointF &q, const QPointF &r)
{
	if (q.x() <= max(p.x(), r.x()) && q.x() >= min(p.x(), r.x()) && q.y() <= max(p.y(), r.y()) && q.y() >= min(p.y(), r.y()))
	{
		return true;
	}
	return false;
}

// 检测两个给定线段是否相交
// https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
// 输入线段 p1q1、p2q2
bool ConvexHull::isIntersect(const QPointF &p1, const QPointF &q1, const QPointF &p2, const QPointF &q2)
{
	// 找到一般和特殊情况的四种方向
	int o1 = this->orientation(p1, q1, p2);
	int o2 = this->orientation(p1, q1, q2);
	int o3 = this->orientation(p2, q2, p1);
	int o4 = this->orientation(p2, q2, q1);
	// 一般情况
	// (p1, q1, p2)、(p1, q1, q2) 具有不同的方向，并且 (p2, q2, p1)、(p2, q2, q1) 也具有不同的方向
	if (o1 != o2 && o3 != o4)
	{
		return true;
	}
	// 特殊情况
	// p1, q1 和 p2 共线，并且 p2 在 p1q1 上
	if (o1 == ConvexHull::ORIENTATION::COLLINEAR && this->onSegment(p1, p2, q1))
	{
		return true;
	}
	// p1, q1 和 q2 共线，并且 q2 在 p1q1 上
	if (o2 == ConvexHull::ORIENTATION::COLLINEAR && this->onSegment(p1, q2, q1))
	{
		return true;
	}
	// p2, q2 和 p1 共线，并且 p1 在 p2q2 上
	if (o3 == ConvexHull::ORIENTATION::COLLINEAR && this->onSegment(p2, p1, q2))
	{
		return true;
	}
	// p2, q2 和 q1 共线，并且 q1 在 p2q2 上
	if (o4 == ConvexHull::ORIENTATION::COLLINEAR && this->onSegment(p2, q1, q2))
	{
		return true;
	}
	return false;
}

// 凸包检测
// https://www.geeksforgeeks.org/convex-hull-using-jarvis-algorithm-or-wrapping/?ref=lbp
void ConvexHull::findConvexHull()
{
	// 至少需要三点才能形成多边形，存在凸包
	if (this->points.size() < 3)
		return;
	// 寻找边界点
	this->findBoundaryPoints();
	// 初始化检测的凸包对象结果
	this->convexhullResult = vector<QPointF>();
	// 找到最左边的点
	int leftPointIndex = this->leftPointIndex;
	// 从最左边的点开始，逆时针遍历所有点，直到回到起点，循环为 O(h)，h 为输出的点数
	int p = leftPointIndex, q;
	do
	{
		// 将当前点添加到结果中
		this->convexhullResult.push_back(this->points[p]);
		// 遍历所有点，搜索下一个点 q，使 (p, q, x) 对于所有点 x 都是逆时针方向，思想为跟踪上一次访问的 q 中逆时针方向的点，如果任何点 i 比 q 更加逆时针(内角越大)，则更新 q = i
		q = (p + 1) % this->points.size();
		for (int i = 0; i < this->points.size(); i++)
		{
			// 如果 i 比 q 更接近 p，则更新 q
			if (this->orientation(this->points[p], this->points[i], this->points[q]) == ConvexHull::ORIENTATION::COUNTERCLOCKWISE)
				q = i;
		}
		// 现在 q 是最接近 p 的点，将 q 设置为下一个 p，为下一次循环做准备
		p = q;
	} while (p != leftPointIndex);
}