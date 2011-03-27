// adodumpDlg.h : ヘッダー ファイル
//

#if !defined(AFX_ADODUMPDLG_H__1E761F32_8775_4030_ABB8_2487003001C1__INCLUDED_)
#define AFX_ADODUMPDLG_H__1E761F32_8775_4030_ABB8_2487003001C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAdodumpDlg ダイアログ

class CAdodumpDlg : public CDialog
{
// 構築
public:
	CAdodumpDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CAdodumpDlg)
	enum { IDD = IDD_ADODUMP_DIALOG };
	CString	m_Filename;
	CString	m_OutDir;
	CString	m_Password;
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CAdodumpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CAdodumpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnStaticJob();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ADODUMPDLG_H__1E761F32_8775_4030_ABB8_2487003001C1__INCLUDED_)
