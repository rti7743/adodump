// adodump.h : ADODUMP アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_ADODUMP_H__80829F19_1EFD_4E80_9E9C_F4BE75612C7E__INCLUDED_)
#define AFX_ADODUMP_H__80829F19_1EFD_4E80_9E9C_F4BE75612C7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CAdodumpApp:
// このクラスの動作の定義に関しては adodump.cpp ファイルを参照してください。
//

class CAdodumpApp : public CWinApp
{
public:
	CAdodumpApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CAdodumpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CAdodumpApp)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ADODUMP_H__80829F19_1EFD_4E80_9E9C_F4BE75612C7E__INCLUDED_)
