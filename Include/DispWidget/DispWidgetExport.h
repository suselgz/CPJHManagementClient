// ͨ�����������ǵ��뻹�ǵ���
#ifdef DISP_WIDGET_EXPORT
#define DLL_DISP_WIDGET_API __declspec(dllexport)
#else
#define DLL_DISP_WIDGET_API __declspec(dllimport)
#endif