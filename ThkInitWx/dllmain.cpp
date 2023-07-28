// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
//
//BOOL APIENTRY DllMain( HMODULE hModule,
//                       DWORD  ul_reason_for_call,
//                       LPVOID lpReserved
//                     )
//{
//    switch (ul_reason_for_call)
//    {
//    case DLL_PROCESS_ATTACH:
//    case DLL_THREAD_ATTACH:
//    case DLL_THREAD_DETACH:
//    case DLL_PROCESS_DETACH:
//        break;
//    }
//    return TRUE;
//}
//

#include "wx/wxprec.h"
#include "wx/app.h"
#include "wx/dynlib.h"

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/thread.h>
#include <wx/msgdlg.h>

#include <wx/dir.h>
#include <wx/filename.h>
#include <wx/stdpaths.h>
#include <wx/file.h>
#include <wx/textfile.h>
#include <wx/log.h>
#include <wx/wfstream.h>
#include <wx/xml/xml.h>
////
//struct __INIT_DAWN__ {
//	__INIT_DAWN__() {
//		wxInitialize();
//	}
//	~__INIT_DAWN__() {
//		wxUninitialize();
//	}
//}__INIT_DAWN__x; // initialization

bool g_bInitByme = false;

class ThkwxDllApp :
	public wxApp
{
public:
	ThkwxDllApp();
	~ThkwxDllApp();

public:
	virtual bool OnInit();
	virtual int OnExit();

};
DECLARE_APP(ThkwxDllApp)

wxIMPLEMENT_APP_NO_MAIN(ThkwxDllApp);

ThkwxDllApp::ThkwxDllApp()
{

}
ThkwxDllApp::~ThkwxDllApp()
{

}

bool ThkwxDllApp::OnInit()
{
	return true;
}

int ThkwxDllApp::OnExit()
{
	return 0;
}

extern "C" __declspec(dllexport) bool InitwxEnc()
{
	g_bInitByme = false;
	if (wxTheApp == nullptr)
	{
		g_bInitByme = wxInitialize();
	}
	return g_bInitByme;
}

extern "C" __declspec(dllexport) void FreewxEnc()
{
	if (wxTheApp != nullptr && g_bInitByme)
		wxUninitialize();
	g_bInitByme = false;
}

extern "C" __declspec(dllexport) bool FreewxEncWithArg(int argc,char* argv[])
{
	g_bInitByme = false;
	if (wxTheApp == nullptr)
	{
		g_bInitByme = wxInitialize(argc, argv);
	}
	return g_bInitByme;
}

#ifdef PROE_VER

#include "ProUtil.h"
#include "ProSizeConst.h"
#include "ProToolkitDll.h"
ProToolkitDllHandle libhandle=nullptr;
wxDialog* dlg = nullptr;
extern "C" int user_initialize(int argc, char* argv[], char* ver, char* build, wchar_t* errbuf)
{
	ProPath text_path;
	TdcToolkitApplTextPathGet(text_path);
	ProPath app_path;
	TdcToolkitApplExecPathGet(app_path);
	wxFileName strFile = wxFileName(app_path);
	
	//if (wxTheApp == nullptr)
	//{
	//	g_bInitByme = wxInitialize(argc, argv);
	//}

	//test
	ProError err_ret;
	ProPath err_str;
	wchar_t pnm[] = L"testwxdllcrd1";
#ifdef _DEBUG
	char pth[] = "testwxdllcrd.dll";
#else
	char pth[] = "testwxdllcr.dll";
#endif
	wxString strPath = strFile.GetPath(true)+wxString(pth);
	char pth2[] = "D:\\devworks\\prj-test\\ThkTestWxDll\\bin\\";
	char* appdir = new char[strPath.size() + 1];  // +1 for the null terminator
	std::strcpy(appdir, strPath.c_str());
	ProError	err = TdcToolkitDllLoad(pnm, appdir,
		pth2,
		PRO_B_TRUE,
		&libhandle, &err_ret, err_str);
	delete[] appdir;
	dlg = new wxDialog(nullptr, wxID_ANY, wxT("测试对话框"));
	dlg->Show();
	//
	return 0;

}

extern "C" void user_terminate()
{
	if (libhandle != nullptr)
		TdcToolkitDllUnload(libhandle);
	libhandle = nullptr;

	if (dlg != nullptr)
		delete dlg;
	dlg = nullptr;
	//if (wxTheApp != nullptr && g_bInitByme)
	//	wxUninitialize();
	//g_bInitByme = false;
}
//#else



#endif

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		if (wxTheApp == nullptr)
		{
			g_bInitByme = wxInitialize();
		}
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		if (wxTheApp != nullptr && g_bInitByme)
			wxUninitialize();
		g_bInitByme = false;
		break;
	}
	return TRUE;
}

extern "C"  __declspec(dllexport) int ThkCrModInit(int nVer, void* pData)
{
	ProPath text_path;
	TdcToolkitApplTextPathGet(text_path);
	ProPath app_path;
	TdcToolkitApplExecPathGet(app_path);
	wxFileName strFile = wxFileName(app_path);

	//if (wxTheApp == nullptr)
	//{
	//	g_bInitByme = wxInitialize(argc, argv);
	//}

	//test
	ProError err_ret;
	ProPath err_str;
	wchar_t pnm[] = L"testwxdllcrd1";
#ifdef _DEBUG
	char pth[] = "testwxdllcrd.dll";
#else
	char pth[] = "testwxdllcr.dll";
#endif
	wxString strPath = strFile.GetPath(true) + wxString(pth);
	char pth2[] = "D:\\devworks\\prj-test\\ThkTestWxDll\\bin\\";
	char* appdir = new char[strPath.size() + 1];  // +1 for the null terminator
	std::strcpy(appdir, strPath.c_str());
	ProError	err = TdcToolkitDllLoad(pnm, appdir,
		pth2,
		PRO_B_TRUE,
		&libhandle, &err_ret, err_str);
	if (err != PRO_TK_NO_ERROR)
		libhandle = nullptr;
	delete[] appdir;
	dlg = new wxDialog(nullptr, wxID_ANY, wxT("测试对话框"));
	dlg->Show();

	return 0;
}

extern "C" __declspec(dllexport) int ThkCrModExit(void)
{
	if (libhandle != nullptr)
		TdcToolkitDllUnload(libhandle);
	libhandle = nullptr;

	if (dlg != nullptr)
		delete dlg;
	dlg = nullptr;

	return 0;
}

extern "C"  __declspec(dllexport) char* GetThkModName()
{
	const char str[] = "ThkTestWxDll";
	char* ptr = const_cast<char*>(str);
	return ptr;
}

extern "C" __declspec(dllexport) int GetThkModVer()
{
	return PROE_VER;
}

extern "C" __declspec(dllexport) char* GetThkModInfo()
{
	const char str[] = "THK WX测试模块";
	char* ptr = const_cast<char*>(str);
	return ptr;
}

extern "C" __declspec(dllexport) char* GetThkCmdList()
{
	const char str[] = "NULL";
	char* ptr = const_cast<char*>(str);
	return ptr;
}
