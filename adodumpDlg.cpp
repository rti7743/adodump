// adodumpDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "adodump.h"
#include "adodumpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// アプリケーションのバージョン情報で使われている CAboutDlg ダイアログ

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ダイアログ データ
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// メッセージ ハンドラがありません。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdodumpDlg ダイアログ

CAdodumpDlg::CAdodumpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdodumpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdodumpDlg)
	m_Filename = _T("");
	m_OutDir = _T("");
	m_Password = _T("");
	//}}AFX_DATA_INIT
	// メモ: LoadIcon は Win32 の DestroyIcon のサブシーケンスを要求しません。
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdodumpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdodumpDlg)
	DDX_Text(pDX, IDC_EDIT_FILENAME, m_Filename);
	DDX_Text(pDX, IDC_EDIT_DIR, m_OutDir);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_Password);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAdodumpDlg, CDialog)
	//{{AFX_MSG_MAP(CAdodumpDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_STATIC_JOB, OnStaticJob)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdodumpDlg メッセージ ハンドラ

BOOL CAdodumpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "バージョン情報..." メニュー項目をシステム メニューへ追加します。

	// IDM_ABOUTBOX はコマンド メニューの範囲でなければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログ用のアイコンを設定します。フレームワークはアプリケーションのメイン
	// ウィンドウがダイアログでない時は自動的に設定しません。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンを設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンを設定
	
	// TODO: 特別な初期化を行う時はこの場所に追加してください。
	
	return TRUE;  // TRUE を返すとコントロールに設定したフォーカスは失われません。
}

void CAdodumpDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// もしダイアログボックスに最小化ボタンを追加するならば、アイコンを描画する
// コードを以下に記述する必要があります。MFC アプリケーションは document/view
// モデルを使っているので、この処理はフレームワークにより自動的に処理されます。

void CAdodumpDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画用のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// クライアントの矩形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンを描画します。
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// システムは、ユーザーが最小化ウィンドウをドラッグしている間、
// カーソルを表示するためにここを呼び出します。
HCURSOR CAdodumpDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



//ぴたぴた、おまじない
#pragma warning( disable : 4146 )
//ADODB を利用するときに使用します.
#import "C:\Program Files\Common Files\System\ado\msado15.dll" \
     rename("EOF","EndOfFile")
//ADOX を利用するときに使用します
#import "C:\Program Files\Common Files\system\ado\msadox.dll" \
	 rename("EOF","EndOfFile")

#pragma warning( default : 4146 )
#include <comdef.h>
#include <atlbase.h>


CString PrintComError(_com_error &e)
{
	_bstr_t bstrSource(e.Source());
	_bstr_t bstrDescription(e.Description());

	// Print Com errors.
	CString str;

	str.Format("Error\n\tCode = %08lx\n\tCode meaning = %s\n\tSource = %s\n\tDescription = %s\n",
	e.Error() , e.ErrorMessage() , (LPCSTR) bstrSource , (LPCSTR) bstrDescription );
	
	return str;
}

///////////////////////////////////////////////////////////
//                                                       //
//      PrintProviderError Function                      //
//                                                       //
///////////////////////////////////////////////////////////

CString PrintProviderError(ADODB::_ConnectionPtr pConnection)
{
    // Print Provider Errors from Connection object.
    // pErr is a record object in the Connection's Error collection.
	ADODB::ErrorPtr    pErr  = NULL;
	CString ret;

    if( (pConnection->Errors->Count) > 0)
    {
        long nCount = pConnection->Errors->Count;
        // Collection ranges from 0 to nCount -1.
        for(long i = 0;i < nCount;i++)
        {
            pErr = pConnection->Errors->GetItem(i);
			CString a;
            a.Format("\t Error number: %x\t%s", pErr->Number,
                pErr->Description);
			ret += a;
        }
    }
	return ret;
}



void CvsDump(const CString & inFilename , const CString & inOutDir , const CString & inExtended )
{
	HRESULT hr;
	int i;
	CString * tables = NULL;
	CString line;

	ADODB::_ConnectionPtr  connect;   // Connectオブジェクト
	ADODB::_RecordsetPtr   recordset;
	try
	{

		// ADO::Connection オブジェクトの生成
		hr = connect.CreateInstance(_uuidof(ADODB::Connection));
		if ( FAILED(hr))
		{
			AfxMessageBox("ADODB::Connectionがつくれにゃーの");
			return ;
		}
		//ADO::Catalog の作成
		ADOX::_CatalogPtr catalog = NULL;
		hr = catalog.CreateInstance(_uuidof(ADOX::Catalog));
		if ( FAILED(hr) )
		{
			AfxMessageBox("ADOX::Catalogがつくれにゃーの");
			return ;
		}

		// データベースへの接続
		CString strConnect = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + inFilename + ";" + inExtended;
		hr = connect->Open( bstr_t(strConnect), "", "", ADODB::adConnectUnspecified);
		if (FAILED(hr))
		{
			AfxMessageBox(strConnect + "\nに接続できにゃーの");
			return ;
		}

		//ADO::Catalog を利用して テーブル一覧を取得します。
		//ADO::Catalog よ、オラに力を貸してくれ!!
		catalog->PutActiveConnection(_variant_t((IDispatch *) connect));
		int tableMax = catalog->Tables->Count;
		tables = new CString[tableMax];

		int tablesCount = 0;
		for(i = 0; i < tableMax ; i++)
		{
			if (catalog->Tables->Item[(long)i]->Type == _bstr_t(L"TABLE"))
			{
				//よし、テーブルげっと.
				 CString str = (LPCSTR)catalog->Tables->Item[(long)i]->Name;
				 tables[tablesCount++] = str;
			}
		}

		//すべてのテーブルに対して、 SQL を発行していくYO!
		for(i = 0; i < tablesCount ; i ++)
		{
			//保存するファイルを開く.
			CString csvfilename =  inOutDir + "\\" + tables[i] + ".csv";
			FILE * fp = fopen( csvfilename , "w+b");
			if (!fp)
			{
				AfxMessageBox(csvfilename + "\nが、開けにゃーの");
				continue;
			}

			//SQLのようなもの を構築.
			CString sql = "SELECT * FROM `" + tables[i] + "`";

			//SQLの　すごい 実行
			recordset = connect->Execute(bstr_t(sql) , NULL , ADODB::adOptionUnspecified);
			
			_variant_t va;

			//フィールド名を取得する.
			ADODB::FieldsPtr fldLoop = recordset->GetFields();
			for ( i = 0; i < (int)fldLoop->GetCount(); i++)
			{
				va = fldLoop->Item[(long)i]->Name;
				if (! (( va.vt == VT_NULL ) || ( va.vt == VT_EMPTY )) )
				{
					//フィールド名を手に入れた!!
					CString str = (char *)(_bstr_t)( va );
					line += "," + str ;
				}

			}
			fprintf(fp , "%s\r\n" , ((const char*)line) + 1 );	// +1は先頭の , を消すため

			//行
			while(! recordset->EndOfFile)
			{
				line = "";
				//列
				fldLoop = recordset->GetFields();
				for ( i = 0; i < (int)fldLoop->GetCount(); i++)
				{
					va = fldLoop->Item[(long)i]->Value;
					if (! (( va.vt == VT_NULL ) || ( va.vt == VT_EMPTY )) )
					{
						//値を手に入れた!!
						CString str = (char *)(_bstr_t)( va );
						line += "," + str ;
					}
				}
				fprintf(fp , "%s\r\n" , ((const char*)line) + 1 );	// +1は先頭の , を消すため
				// 行の処理
				recordset->MoveNext();
			}
			fclose(fp);
		}
		//SQLの終了ー
		recordset->Close();

		AfxMessageBox("dump.");
	}
	catch( _com_error &e )
	{
		CString errorMessage;
		errorMessage.Format("e.ErrorMessage---------\r\n%s\r\n"
							"PrintComError-------------\r\n%s\r\n"
							"PrintProviderError------------\r\n%s\r\n",
							CString(e.ErrorMessage() ) ,
							PrintComError(e),
							PrintProviderError(connect)  
										);
		AfxMessageBox(errorMessage);
	}

	delete [] tables;
}

void CAdodumpDlg::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください

	this->UpdateData(TRUE);
	if ( this->m_Filename.GetLength() <= 0)
	{
		AfxMessageBox("ファイル名をいれろボケ、IP抜くぞゴラァ");
		return ;
	}
	if ( this->m_OutDir.GetLength() <= 0)
	{
		AfxMessageBox("変換先をいれろボケ、IP抜くぞゴラァ");
		return ;
	}

	CString extended = "";
	if ( strstr(this->m_Filename , ".xls") )
	{
		extended += "Extended Properties=Excel 8.0;";
	}
	else if ( strstr(this->m_Filename , ".mdb") )
	{
		extended += "";
	}

	//パスワードがあるなら、パスワードを入れてみる.
	if ( this->m_Password.GetLength() > 0)
	{
		extended += "Jet OLEDB:Database Password=" + this->m_Password + ";";
	}


	CvsDump( this->m_Filename , this->m_OutDir,  extended);
}


#include <shlobj.h>
#include <commdlg.h>


void CAdodumpDlg::OnButton1() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
    OPENFILENAME ofn = { 0 };
	char retFilenameBuffer[MAX_PATH] = {0};

    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = this->m_hWnd;
    ofn.lpstrFilter = "Excel(.xls)\0*.xls\0Acess(.mdb)\0*.mdb\0\0";
    ofn.lpstrFile = retFilenameBuffer;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_FILEMUSTEXIST;
    ofn.lpstrTitle = "王様「xls / mdb を選択するがよい!!」";
	ofn.lpstrInitialDir = "";

    if (!GetOpenFileName(&ofn)) 
	{
		return ;
	}

	this->m_Filename = retFilenameBuffer;
	this->UpdateData(FALSE);
}

void CAdodumpDlg::OnButton2() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char retPathBuffer[MAX_PATH] = {0};

	bool ret = false;
	IMalloc *m;
	if(SUCCEEDED(SHGetMalloc(&m)))
	{
		BROWSEINFO b;

		b.hwndOwner = this->m_hWnd;
		b.pidlRoot = NULL;
		b.pszDisplayName = retPathBuffer;
		b.lpszTitle = "老人「.cvsを保存するディレクトリをしてするのぢゃ」" ;
		b.ulFlags = BIF_RETURNONLYFSDIRS; //フォルダのみ
		b.lpfn = NULL;
		b.lParam = 0;
		b.iImage = 0;
		LPITEMIDLIST id = SHBrowseForFolder(&b); //ダイアログの表示
		if(id)
		{
			SHGetPathFromIDList(id, retPathBuffer); //パス名を得る

			if (retPathBuffer[lstrlen(retPathBuffer)-1]!='\\') 
			{
				strcat(retPathBuffer,"\\"); //最後は \\ 
			}
			m->Free(id);
		}
		m->Release();
	}
	this->m_OutDir = retPathBuffer;

	this->UpdateData(FALSE);

}

void CAdodumpDlg::OnStaticJob() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	CWnd * win;
	win = this->GetDlgItem(IDC_STATIC_JOB);
	win->ShowWindow( SW_HIDE);

	win = this->GetDlgItem(IDC_STATIC_PASSWORD);
	win->ShowWindow( SW_SHOW);

	win = this->GetDlgItem(IDC_EDIT_PASSWORD);
	win->ShowWindow( SW_SHOW);
}
