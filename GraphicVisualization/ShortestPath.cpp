#include "ShortestPath.h"

ShortestPathPointToPoint::ShortestPathPointToPoint(const string &placeFile, const string &pathFile)
{
    // 读取路网
    this->readRoad(placeFile, pathFile);
}

// 读取路网
void ShortestPathPointToPoint::readRoad(const string &placeFile, const string &pathFile)
{
    // 字符编码转换器
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    {
        // 创建文件输入流
        ifstream in(placeFile);
        // 当前行
        string line;
        // 读取文件的每一行
        while (getline(in, line))
        {
            // 创建一个字符串流
            istringstream iss(line);
            // 创建一个字符串用于存储当前字段
            string field;
            // 创建一个字段的集合
            vector<string> fields;
            // 读取当前行的每一个字段
            while (getline(iss, field, ' '))
            {
                // 将当前字段添加到字段的集合中
                fields.push_back(field);
            }
            // 如果字段的数量不等于 5，那么输出错误信息并跳过当前行
            if (fields.size() != 5)
            {
                cerr << "无效的行: " << line << endl;
                continue;
            }
            // 创建一个场所对象
            Place place;
            // 设置场所对象的属性
            place.id = stoi(fields[0]);
            place.point.setX(stod(fields[1]));
            place.point.setY(stod(fields[2]));
            place.name = converter.from_bytes(fields[3]);
            place.category = converter.from_bytes(fields[4]);
            // 将场所对象添加到场所的集合中
            this->places.push_back(place);
        }
        // 关闭文件输入流
        in.close();
    }
    {
        // 创建文件输入流
        ifstream in(pathFile);
        // 存储当前行
        string line;
        // 读取文件的每一行
        while (getline(in, line))
        {
            // 创建一个字符串流
            istringstream iss(line);
            // 创建一个字符串用于存储当前字段
            string field;
            // 创建一个字段的集合
            vector<string> fields;
            // 读取当前行的每一个字段
            while (getline(iss, field, ' '))
            {
                // 将当前字段添加到字段的集合中
                fields.push_back(field);
            }
            // 如果字段的数量不等于 3，那么输出错误信息并跳过当前行
            if (fields.size() != 3)
            {
                cerr << "无效的行: " << line << endl;
                continue;
            }
            // 创建一个路径对象
            Path path;
            // 设置路径对象的起点和终点
            for (const Place &place : this->places)
            {
                if (stoi(fields[0]) == place.id)
                {
                    path.from = place;
                }
                if (stoi(fields[1]) == place.id)
                {
                    path.to = place;
                }
            }
            // 设置路径对象的长度
            path.length = stod(fields[2]);
            // 将路径对象添加到路径的集合中
            this->paths.push_back(path);
        }
        // 关闭文件输入流
        in.close();
    }
}

// 最短路径算法（Dijkstra）
vector<Place> ShortestPathPointToPoint::shortestPath(Place startPlace, Place endPlace)
{
    // 获取场景的数量
    int totalPlaces = places.size();
    // 初始化所有场景的最短路径为无穷大
    vector<double> shortestDistances(totalPlaces, INT_MAX);
    // 初始化所有场景为未访问
    vector<bool> isVisited(totalPlaces, false);
    // 用于记录最短路径中的上一个场景
    vector<int> previousPlace(totalPlaces, -1);
    // 定义优先队列的比较函数（与 set 或 map 排序不同，set 或 map 比较函数的定义为若第一个参数应该排在第二个参数之前，则返回 true，而 priority_queue 的比较函数的定义则相反（默认最大堆，降序排列），若第一个参数应该排在第二个参数之后，则返回 true）
    auto compareDistances = [=](const pair<int, double> &a, const pair<int, double> &b)
    {
        return a.second > b.second;
    };
    // 定义优先队列，用于存储待访问的场景和它们的最短路径
    priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(compareDistances)> placesQueue(compareDistances);
    // 将起点的最短路径设置为 0
    shortestDistances[startPlace.id] = 0;
    // 将起点添加到优先队列中
    placesQueue.push(make_pair(startPlace.id, 0));
    while (!placesQueue.empty())
    {
        // 从优先队列中取出最短路径最小的场景
        int currentPlace = placesQueue.top().first;
        placesQueue.pop();
        // 标记该场景已访问
        isVisited[currentPlace] = true;
        // 如果已经找到终点，就可以结束循环
        if (currentPlace == endPlace.id)
        {
            break;
        }
        // ----------------------------------- Dijkstra 算法核心，遍历当前节点的所有邻居，并尝试更新它们的最短路径 -----------------------------------
        // 遍历当前场景的所有路径
        for (auto &path : paths)
        {
            // 如果路径的起点或终点是当前场景，并且另一端还没有被访问过
            if (path.from.id == currentPlace && !isVisited[path.to.id])
            {
                // 计算当前场景到另一端（from.id -> to.id）的最短路径
                double newDistance = shortestDistances[currentPlace] + path.length;
                // 若当前计算的新距离小于原来的最短路径到当前场景的距离（shortestDistances begin with inf）
                if (newDistance < shortestDistances[path.to.id])
                {
                    // 更新最短路径
                    shortestDistances[path.to.id] = newDistance;
                    // 将终点和最短路径添加到优先队列中
                    placesQueue.push(make_pair(path.to.id, newDistance));
                    // 同时记录到达终点的最短路径中的上一个场景为当前场景
                    previousPlace[path.to.id] = currentPlace;
                }
            }
            else if (path.to.id == currentPlace && !isVisited[path.from.id])
            {
                // 计算当前场景到另一端（from.id -> to.id）的最短路径
                double newDistance = shortestDistances[currentPlace] + path.length;
                // 若当前计算的新距离小于原来的最短路径到当前场景的距离（shortestDistances begin with inf）
                if (newDistance < shortestDistances[path.from.id])
                {
                    // 更新最短路径
                    shortestDistances[path.from.id] = newDistance;
                    // 将终点和最短路径添加到优先队列中
                    placesQueue.push(make_pair(path.from.id, newDistance));
                    // 同时记录到达终点的最短路径中的上一个场景为当前场景
                    previousPlace[path.from.id] = currentPlace;
                }
            }
        }
    }
    // 从终点开始，通过 previousPlace 数组回溯最短路径
    vector<Place> shortestPath;
    // 从终点开始回溯，直到回溯到起点（起点的值为 -1，且不会被更新）
    for (int at = endPlace.id; at != -1; at = previousPlace[at])
    {
        shortestPath.push_back(places[at]);
    }
    // 由于是从终点开始回溯的，所以需要将最短路径反转
    reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}

// 计算最短路径
double ShortestPathPointToPoint::calcMinDistance(const vector<Place> &places)
{
    // 如果地点的数量少于 2，那么没有路径，所以返回 0
    if (places.size() < 2)
    {
        return 0.0;
    }
    // 初始化最短距离为 0
    double minDistance = 0.0;
    // 遍历所有的地点，除了最后一个
    for (int i = 0; i < places.size() - 1; i++)
    {
        // 遍历所有的路径
        for (int j = 0; j < this->paths.size(); j++)
        {
            // 如果当前地点是路径的起点，且下一个地点是路径的终点
            if (places[i].id == this->paths[j].from.id && places[i + 1].id == this->paths[j].to.id)
            {
                // 将路径的长度添加到最短距离
                minDistance += this->paths[j].length;
                // 跳出内部循环，继续下一个地点
                break;
            }
            // 如果当前地点是路径的终点，且下一个地点是路径的起点
            else if (places[i].id == this->paths[j].to.id && places[i + 1].id == this->paths[j].from.id)
            {
                // 将路径的长度添加到最短距离
                minDistance += this->paths[j].length;
                // 跳出内部循环，继续下一个地点
                break;
            }
        }
    }
    // 返回最短距离
    return minDistance;
}