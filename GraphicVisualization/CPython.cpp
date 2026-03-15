#include "CPython.h"

namespace CPython
{
    // 初始化 Python 解释器，仅调用一次
    void initPython()
    {
        // Qt C++ 调用 Python 时设置
        Py_SetPythonHome(L"D:/Python");
        // 初始化 Python 解释器，并创建主模块对象和内置模块对象
        Py_Initialize();
        if (!Py_IsInitialized())
        {
            cout << "Python init failed" << endl;
            PyErr_Print();
            return;
        }
        // 初始化 Python 系统文件路径，添加当前 .py 文件路径，保证可以访问到 .py 文件
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append('./')");
    }

    // 清理 Python 解释器，仅调用一次
    void clearPython()
    {
        Py_Finalize();
    }

    namespace IDW
    {
        // 使用 Matplotlib 显示 2D/3D 等高线地图
        void showContourMap(const string &file, const string &elevField)
        {
            // 将 Python 脚本文件作为 Module 导入
            PyObject *pyModule = PyImport_ImportModule("PyIDW");
            if (!PyModule_Check(pyModule) || !pyModule)
            {
                cout << "Module not found" << endl;
                PyErr_Print();
                return;
            }
            // 获取函数对象
            PyObject *funcContourMap = PyObject_GetAttrString(pyModule, "showContourMap");
            if (!PyCallable_Check(funcContourMap) || !funcContourMap)
            {
                cout << "Function not found" << endl;
                PyErr_Print();
                return;
            }
            // 将 C++ 字符串参数包裹为元组类型
            PyObject *args = Py_BuildValue("(ss)", file.c_str(), elevField.c_str());
            // 调用函数
            PyObject_CallObject(funcContourMap, args);
        }
    }

    namespace TIN
    {

    }
}