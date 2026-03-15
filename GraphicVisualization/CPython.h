#pragma once
#pragma execution_character_set("utf-8")

#include <Python.h>
#include <iostream>
#include <string>

using namespace std;

namespace CPython
{
	// 初始化 Python 解释器
	void initPython();
	// 清理 Python 解释器
	void clearPython();
	namespace IDW
	{
		// 使用 Matplotlib 显示 2D/3D 等高线地图
		void showContourMap(const string &file, const string &elevField);
	}
	namespace TIN
	{

	}
}