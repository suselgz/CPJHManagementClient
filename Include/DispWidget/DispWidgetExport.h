// 通过宏来控制是导入还是导出
#ifdef DISP_WIDGET_EXPORT
#define DLL_DISP_WIDGET_API __declspec(dllexport)
#else
#define DLL_DISP_WIDGET_API __declspec(dllimport)
#endif