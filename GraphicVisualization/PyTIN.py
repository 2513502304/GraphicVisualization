from scipy.spatial import Delaunay
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# 洪山区 POI 数据，包含 POI 的序号、名称、经纬度
file = r'C:\Users\admin\source\repos\DataStructure\Data\TIN_data.csv'

df = pd.read_csv(file, index_col=0)

name = df['name']
lon = df['locationx']
lat = df['locationy']

# 将经度和纬度组合成一个二维数组
points = np.array([lon, lat]).T

# 创建 Delaunay 三角形
tri = Delaunay(points)

# 绘制三角网
figure = plt.figure()
axes = figure.add_subplot(111)
axes.triplot(points[:, 0], points[:, 1], tri.simplices)
axes.plot(points[:, 0], points[:, 1], 'o', color='red')
plt.show()
