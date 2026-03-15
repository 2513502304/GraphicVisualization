import matplotlib.pyplot as plt
import geopandas as gpd
from scipy.interpolate import griddata
import numpy as np


def mouseEvent(event):
    '''鼠标中键点击，获取屏幕当前位置的数据坐标，仅在 2D 绘图中生效，3D 绘图中存在视角和投影，获取的为视图坐标而非数据坐标'''
    if event.button == 2:
        with open('./Coordinates.txt', 'w') as f:
            f.write(str(event.xdata) + ' ' + str(event.ydata) + '\n')


def showContourMap(file_path: str, elevField: str) -> None:
    '''读取含有等高线的矢量文件，并绘制 2D、3D 等高线地图'''
    gdf = gpd.read_file(file_path)
    # 提取所有的坐标和高程值
    x = []
    y = []
    z = []
    for i, row in gdf.iterrows():
        if row.geometry.geom_type == 'LineString':
            for x_coord, y_coord in row.geometry.coords:
                x.append(x_coord)
                y.append(y_coord)
                z.append(row[elevField])
    # 创建网格，shape(100, 100)
    xi = np.linspace(min(x), max(x), 100)
    yi = np.linspace(min(y), max(y), 100)
    xi, yi = np.meshgrid(xi, yi)
    # 插值非结构化 D-D 数据
    zi = griddata((x, y), z, (xi, yi), method='cubic')
    # 绘制 2D、3D 等高线
    figure = plt.figure('2D Contour')
    # 绑定鼠标事件
    figure.canvas.mpl_connect('button_press_event', mouseEvent)
    plt.contour(xi, yi, zi, levels=14, linewidths=0.5, colors='k')
    plt.contourf(xi, yi, zi, levels=14, cmap='RdBu_r')
    plt.title('2D Contour', fontdict={'fontsize': '25', 'fontweight': '3'})
    plt.xlabel('Longitude')
    plt.ylabel('Latitude')
    plt.show(block=False)
    figure = plt.figure('3D Contour')
    axes = figure.add_subplot(projection='3d')
    axes.contourf3D(xi, yi, zi, 500, cmap='RdBu_r')
    axes.set_title('3D Contour')
    axes.set_xlabel('Longitude')
    axes.set_ylabel('Latitude')
    axes.set_zlabel('Elevation')
    plt.show()
