#include "IDW.h"

IDW::IDW(const string& file)
{
    // 读取 GeoJSON 文件
    this->readGeoJSON(file);
}

// 读取 GeoJSON 文件
void IDW::readGeoJSON(const string& file)
{
    // 输入文件流
    ifstream in(file);
    // JSON 对象
    nlohmann::json j;
    // 读取 JSON 文件
    in >> j;
    // 读取 JSON 地理特征集合
    for (auto& feature : j["features"])
    {
        // 构造 LineString 对象
        LineString lineString;
        // 读取 LineString 属性
        lineString.id = feature["properties"]["ID"];
        lineString.elev = feature["properties"]["ELEV"];
        for (auto& coord : feature["geometry"]["coordinates"])
        {
            lineString.points.push_back(QPointF(coord[0], coord[1]));
        }
        this->lineStrings.push_back(lineString);
    }
    // 关闭文件
    in.close();
}

// 计算两点之间的欧式距离
double IDW::distance(const QPointF& p1, const QPointF& p2)
{
    return sqrt(pow(p1.x() - p2.x(), 2) + pow(p1.y() - p2.y(), 2));
}

// 执行反距离加权插值（IDW）算法
// 反距离加权法（也称为距离反比法）认为被估单元块的属性与其周围一定距离内已知点的属性有关，并且认为这种关系与已知点到被估单元块中心点的距离的 n 次幂成反比
// z0 = (Σwi * zi) / (Σwi)
// 其中，z0 为未知点的高程值，zi 为已知点的高程值，wi 为已知点的权重，wi = 1 / Di^n，Di 为已知点到未知点的距离，n 为幂指数，它显著影响内插的结果，它的选择标准是最小平均绝对误差，OliverMA 等人的研究结果表明，幂 p 越高，内插结果越平滑，常选用 p = 2
// 延伸应用
// 其实距离反比法不仅仅可以应用在标量的插值，在矢量场的也有很强的可用性，例如在二维或者三维速度场中，可以将速度场分解成 2 个或者 3 个方向的标量，然后再将插值后的数据进行整合，便可以得到矢量场的插值结果
// 样本点的选取
// 要使用反距离加权法，首先要确定待插点选取的样本点。确定样本点的方法有线性搜索和面积搜索 2 种方式
// 线性搜索就是给定待插点的(结构网格下)在横向或纵向邻近样本点的总数，该方法较为适用于已知散点值分布不均匀的情况
// 面积搜索通常有矩形、圆形和椭圆形搜索等。矩形和椭圆形搜索需要给定长边和短边的长度，而圆形搜索只需要给定半径(是椭圆搜索的一个特例)。落在指定面积内所有已经散点值将被看作是样本点
// 为适应已知散点数据的疏密变化，矩形、椭圆形和圆形搜索的边长和半径可以设置为可变的
double IDW::interpolate(const QPointF& point, int m)
{
    // 存储最近的 m 个点的距离以及高程值
    vector<pair<double, double>> nearest;
    // ----------------------------------- 找到最近的 m 个点 -----------------------------------
    // 遍历所有线段
    for (const auto& lineString : this->lineStrings)
    {
        // 遍历线段上的所有点
        for (const auto& p : lineString.points)
        {
            // 计算距离
            double dist = distance(point, p);
            // 如果最近的 m 个点的距离不足 m 个或者距离小于最近的 m 个点的距离
            if (nearest.size() < m || dist < nearest.back().first)
            {
                // 将该点加入最近的 m 个点
                nearest.push_back({ dist, lineString.elev });
                // 对最近的 m 个点进行排序，使每次遍历时，最远的点永远都排在最后
                sort(nearest.begin(), nearest.end());
                // 如果最近的 m 个点的数量超过 m 个
                if (nearest.size() > m)
                {
                    // 将最远的点移除
                    nearest.pop_back();
                }
            }
        }
    }
    // ----------------------------------- 计算未知点的高程值 -----------------------------------
    // 权重和
    double sumWeights = 0;
    // 高程值加权和
    double sumValues = 0;
    // 遍历最近的 m 个点
    for (const auto& [dist, elev] : nearest)
    {
        // 使用距离的平方作为权重
        double weight = 1 / pow(dist, 2);
        // 更新权重和
        sumWeights += weight;
        // 更新高程值加权和
        sumValues += weight * elev;
    }
    // 返回未知点的高程值
    return sumValues / sumWeights;
}