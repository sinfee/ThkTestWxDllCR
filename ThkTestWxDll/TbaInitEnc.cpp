#include "pch.h"
#include "wx/dynlib.h"
#include "TbaImpDef.h"
#include "TbaInitEnc.h"

typedef bool (*InitEnvImp)();
typedef bool (*InitEnvWithArgImp)(int, char**);
typedef void (*FreeEnvImp)();

wxDynamicLibrary g_wxMyDll;

TbaInitEnc::TbaInitEnc()
{
	m_strEnvDll = wxT("ThkInitWx.dll");
	g_wxMyDll.Load(m_strEnvDll);
}

TbaInitEnc::~TbaInitEnc()
{
	g_wxMyDll.Unload();
}

bool TbaInitEnc::InitEnc()
{
	if(!g_wxMyDll.IsLoaded())
		return false;
	InitEnvImp pInit = (InitEnvImp)g_wxMyDll.GetSymbol(wxT("InitwxEnc"));
	if (pInit == nullptr)
		return false;
	return pInit();
}

bool TbaInitEnc::InitEnc(int argc, char* argv[])
{
	if (!g_wxMyDll.IsLoaded())
		return false;
	InitEnvWithArgImp pInit = (InitEnvWithArgImp)g_wxMyDll.GetSymbol(wxT("FreewxEncWithArg"));
	if (pInit == nullptr)
		return false;
	return pInit(argc,argv);

}

void TbaInitEnc::FreeEnc()
{
	if (!g_wxMyDll.IsLoaded())
		return ;
	FreeEnvImp pFree = (FreeEnvImp)g_wxMyDll.GetSymbol(wxT("FreewxEnc"));
	if (pFree == nullptr)
		return ;
	pFree();
}
