#pragma once

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#	include "wx/wx.h"
#endif

#include "wx/app.h"
#include "wx/dynlib.h"
#include "wx/frame.h"
#include "wx/panel.h"
#include "wx/sizer.h"
#include "wx/stattext.h"
#include "wx/button.h"
#include "wx/thread.h"
#include "wx/msgdlg.h"

#include <wx/string.h>
#include <wx/vector.h>
#include <wx/variant.h>
#include <wx/arrstr.h>

#ifndef TbaString
#define TbaString wxString
#endif

#ifndef TbaVector
#define TbaVector wxVector
#endif

#ifndef TbaStringArray
#define TbaStringArray wxArrayString
#endif

//
//bool Split(wchar_t* wszString, const wchar_t* wchSplit /*= L";"*/)
//{
//	if (wszString == nullptr)
//		return false;
//	wxString strInfo = wxString(wszString);
//	strInfo.Trim();
//	wxString strSplit = wxString(wchSplit);
//	if (strSplit.IsEmpty())
//		strSplit = wxT(";");
//	m_arrStrings = wxStringTokenize(strInfo, strSplit);
//
//	return m_arrStrings.Count() != 0;
//
//}
