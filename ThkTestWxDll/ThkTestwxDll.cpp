#include "pch.h"
#include "TbaImpDef.h"
#include "ThkTestwxDll.h"
#include "TbaInitEnc.h"
#include "ProToolkitDll.h"

#if wxCHECK_CXX_STD(201103)
#pragma message ("----------wxCHECK_CXX_STD 201103!---------")
#elif defined(HAVE_ROUND) || wxCHECK_VISUALC_VERSION(12)
#pragma message ("----------HAVE_ROUND---------")
#else
#pragma message ("----------NOT HAVE_ROUND!---------")
#endif
//

//wxInitializer g_initWx;
TbaInitEnc* g_InitEnv = nullptr;

//wxIMPLEMENT_APP_NO_MAIN(ThkTestwxDll);
//bool g_bInitOK = false;
////
//struct __INIT_DAWN__ {
//	__INIT_DAWN__() {
//		wxInitialize();
//	}
//	~__INIT_DAWN__() {
//		wxUninitialize();
//	}
//}__INIT_DAWN__x; // initialization
//
//ThkTestwxDll::ThkTestwxDll()
//{
//
//}
//ThkTestwxDll::~ThkTestwxDll()
//{
//
//}
//
//bool ThkTestwxDll::OnInit()
//{
//	return true;
//}
//
//int ThkTestwxDll::OnExit()
//{
//	return 0;
//}

#ifdef THK_CREO_DLL

#include "ProUtil.h"
#include "ProSizeConst.h"
wxDialog* dlg = nullptr;
ProToolkitDllHandle libhandle;
bool g_bInitByme = false;
//
//extern "C" int user_initialize(int argc, char* argv[], char* ver, char* build, wchar_t* errbuf)
//{
//	ProPath text_path;
//	TdcToolkitApplTextPathGet(text_path);
//
//	if (wxTheApp == nullptr)
//	{
//		g_bInitByme = wxInitialize(argc, argv);
//	}
//	//if (g_InitEnv == nullptr)
//	//	g_InitEnv = new TbaInitEnc();
//	//if (g_InitEnv == nullptr)
//	//	return -1;
//	//bool bInitok = g_InitEnv->InitEnc(argc, argv);
//	//if (!bInitok)
//	//{
//	//	delete g_InitEnv;
//	//	g_InitEnv = nullptr;
//	//	return -2;
//	//}
////	wxEntryStart(argc, argv);
//	// wxInitialize(argc,argv);
//	//wxDISABLE_DEBUG_SUPPORT();
//	//wxInitialize(argc,argv);
//	//wxInitialize(argc,argv);
//
//	//ProError err_ret;
//	//ProPath err_str;
//
//	//ProError	err = ProToolkitDllLoad(L"testwxdllcrd1", "D:\\devworks\\prj-test\\ThkTestWxDll\\bin\\DbgLibWF5x64\\testwxdllcrd1.dll",
//	//		"D:\\devworks\\prj-test\\ThkTestWxDll\\bin\\DbgLibWF5x64",
//	//		PRO_B_TRUE,
//	//		&libhandle, &err_ret, err_str);
//	//if (g_initWx.IsOk())
//	{
//		dlg = new wxDialog(nullptr, wxID_ANY, wxT("²âÊÔ¶Ô»°¿ò"));
//		dlg->Show();
//	}
////	wxTheApp
//	return 0;
//}
//
//extern "C" void user_terminate()
//{
//	if (dlg != nullptr)
//		delete dlg;
//	dlg = nullptr;
//	if (wxTheApp != nullptr && g_bInitByme)
//		wxUninitialize();
//	g_bInitByme = false;
//
//	//if(libhandle != nullptr)
//	//	ProToolkitDllUnload(libhandle);
//	////if (dlg != nullptr)
//	////	delete dlg;
//	//	//wxUninitialize();
//	//	//wxUninitialize();
//	//	wxUninitialize();
//		// 
////	wxEntryCleanup();
//	//if (g_InitEnv != nullptr)
//	//{
//	//	g_InitEnv->FreeEnc();
//	//	delete g_InitEnv;
//	//	g_InitEnv = nullptr;
//	//}
//}
//

#endif

extern "C"  __declspec(dllexport) int ThkCrModInit(int nVer, void* pData)
{
	//if (wxTheApp == nullptr)
	//{
	//	g_bInitByme = wxInitialize(argc, argv);
	//}
	if (wxTheApp == nullptr)
	{
		g_bInitByme = wxInitialize(nVer, (char**)pData);
	}
	dlg = new wxDialog(nullptr, wxID_ANY, wxT("²âÊÔ¶Ô»°¿ò"));
	dlg->Show();
	return 0;
}
extern "C" __declspec(dllexport) int ThkCrModExit(void)
{
	if (dlg != nullptr)
		delete dlg;
	dlg = nullptr;
	if (wxTheApp != nullptr && g_bInitByme)
		wxUninitialize();
	g_bInitByme = false;

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
	const char str[] = "THK WX²âÊÔÄ£¿é";
	char* ptr = const_cast<char*>(str);
	return ptr;
}

extern "C" __declspec(dllexport) char* GetThkCmdList()
{
	const char str[] = "NULL";
	char* ptr = const_cast<char*>(str);
	return ptr;
}
