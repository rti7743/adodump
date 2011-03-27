// adodumpDlg.cpp : �C���v�������e�[�V���� �t�@�C��
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
// �A�v���P�[�V�����̃o�[�W�������Ŏg���Ă��� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂�
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
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
		// ���b�Z�[�W �n���h��������܂���B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdodumpDlg �_�C�A���O

CAdodumpDlg::CAdodumpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdodumpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdodumpDlg)
	m_Filename = _T("");
	m_OutDir = _T("");
	m_Password = _T("");
	//}}AFX_DATA_INIT
	// ����: LoadIcon �� Win32 �� DestroyIcon �̃T�u�V�[�P���X��v�����܂���B
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
// CAdodumpDlg ���b�Z�[�W �n���h��

BOOL CAdodumpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "�o�[�W�������..." ���j���[���ڂ��V�X�e�� ���j���[�֒ǉ����܂��B

	// IDM_ABOUTBOX �̓R�}���h ���j���[�͈̔͂łȂ���΂Ȃ�܂���B
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

	// ���̃_�C�A���O�p�̃A�C�R����ݒ肵�܂��B�t���[�����[�N�̓A�v���P�[�V�����̃��C��
	// �E�B���h�E���_�C�A���O�łȂ����͎����I�ɐݒ肵�܂���B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R����ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R����ݒ�
	
	// TODO: ���ʂȏ��������s�����͂��̏ꏊ�ɒǉ����Ă��������B
	
	return TRUE;  // TRUE ��Ԃ��ƃR���g���[���ɐݒ肵���t�H�[�J�X�͎����܂���B
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

// �����_�C�A���O�{�b�N�X�ɍŏ����{�^����ǉ�����Ȃ�΁A�A�C�R����`�悷��
// �R�[�h���ȉ��ɋL�q����K�v������܂��BMFC �A�v���P�[�V������ document/view
// ���f�����g���Ă���̂ŁA���̏����̓t���[�����[�N�ɂ�莩���I�ɏ�������܂��B

void CAdodumpDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// �N���C�A���g�̋�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R����`�悵�܂��B
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// �V�X�e���́A���[�U�[���ŏ����E�B���h�E���h���b�O���Ă���ԁA
// �J�[�\����\�����邽�߂ɂ������Ăяo���܂��B
HCURSOR CAdodumpDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



//�҂��҂��A���܂��Ȃ�
#pragma warning( disable : 4146 )
//ADODB �𗘗p����Ƃ��Ɏg�p���܂�.
#import "C:\Program Files\Common Files\System\ado\msado15.dll" \
     rename("EOF","EndOfFile")
//ADOX �𗘗p����Ƃ��Ɏg�p���܂�
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

	ADODB::_ConnectionPtr  connect;   // Connect�I�u�W�F�N�g
	ADODB::_RecordsetPtr   recordset;
	try
	{

		// ADO::Connection �I�u�W�F�N�g�̐���
		hr = connect.CreateInstance(_uuidof(ADODB::Connection));
		if ( FAILED(hr))
		{
			AfxMessageBox("ADODB::Connection������ɂ�[��");
			return ;
		}
		//ADO::Catalog �̍쐬
		ADOX::_CatalogPtr catalog = NULL;
		hr = catalog.CreateInstance(_uuidof(ADOX::Catalog));
		if ( FAILED(hr) )
		{
			AfxMessageBox("ADOX::Catalog������ɂ�[��");
			return ;
		}

		// �f�[�^�x�[�X�ւ̐ڑ�
		CString strConnect = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + inFilename + ";" + inExtended;
		hr = connect->Open( bstr_t(strConnect), "", "", ADODB::adConnectUnspecified);
		if (FAILED(hr))
		{
			AfxMessageBox(strConnect + "\n�ɐڑ��ł��ɂ�[��");
			return ;
		}

		//ADO::Catalog �𗘗p���� �e�[�u���ꗗ���擾���܂��B
		//ADO::Catalog ��A�I���ɗ͂�݂��Ă���!!
		catalog->PutActiveConnection(_variant_t((IDispatch *) connect));
		int tableMax = catalog->Tables->Count;
		tables = new CString[tableMax];

		int tablesCount = 0;
		for(i = 0; i < tableMax ; i++)
		{
			if (catalog->Tables->Item[(long)i]->Type == _bstr_t(L"TABLE"))
			{
				//�悵�A�e�[�u��������.
				 CString str = (LPCSTR)catalog->Tables->Item[(long)i]->Name;
				 tables[tablesCount++] = str;
			}
		}

		//���ׂẴe�[�u���ɑ΂��āA SQL �𔭍s���Ă���YO!
		for(i = 0; i < tablesCount ; i ++)
		{
			//�ۑ�����t�@�C�����J��.
			CString csvfilename =  inOutDir + "\\" + tables[i] + ".csv";
			FILE * fp = fopen( csvfilename , "w+b");
			if (!fp)
			{
				AfxMessageBox(csvfilename + "\n���A�J���ɂ�[��");
				continue;
			}

			//SQL�̂悤�Ȃ��� ���\�z.
			CString sql = "SELECT * FROM `" + tables[i] + "`";

			//SQL�́@������ ���s
			recordset = connect->Execute(bstr_t(sql) , NULL , ADODB::adOptionUnspecified);
			
			_variant_t va;

			//�t�B�[���h�����擾����.
			ADODB::FieldsPtr fldLoop = recordset->GetFields();
			for ( i = 0; i < (int)fldLoop->GetCount(); i++)
			{
				va = fldLoop->Item[(long)i]->Name;
				if (! (( va.vt == VT_NULL ) || ( va.vt == VT_EMPTY )) )
				{
					//�t�B�[���h������ɓ��ꂽ!!
					CString str = (char *)(_bstr_t)( va );
					line += "," + str ;
				}

			}
			fprintf(fp , "%s\r\n" , ((const char*)line) + 1 );	// +1�͐擪�� , ����������

			//�s
			while(! recordset->EndOfFile)
			{
				line = "";
				//��
				fldLoop = recordset->GetFields();
				for ( i = 0; i < (int)fldLoop->GetCount(); i++)
				{
					va = fldLoop->Item[(long)i]->Value;
					if (! (( va.vt == VT_NULL ) || ( va.vt == VT_EMPTY )) )
					{
						//�l����ɓ��ꂽ!!
						CString str = (char *)(_bstr_t)( va );
						line += "," + str ;
					}
				}
				fprintf(fp , "%s\r\n" , ((const char*)line) + 1 );	// +1�͐擪�� , ����������
				// �s�̏���
				recordset->MoveNext();
			}
			fclose(fp);
		}
		//SQL�̏I���[
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
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������

	this->UpdateData(TRUE);
	if ( this->m_Filename.GetLength() <= 0)
	{
		AfxMessageBox("�t�@�C�����������{�P�AIP�������S���@");
		return ;
	}
	if ( this->m_OutDir.GetLength() <= 0)
	{
		AfxMessageBox("�ϊ���������{�P�AIP�������S���@");
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

	//�p�X���[�h������Ȃ�A�p�X���[�h�����Ă݂�.
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
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
    OPENFILENAME ofn = { 0 };
	char retFilenameBuffer[MAX_PATH] = {0};

    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = this->m_hWnd;
    ofn.lpstrFilter = "Excel(.xls)\0*.xls\0Acess(.mdb)\0*.mdb\0\0";
    ofn.lpstrFile = retFilenameBuffer;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_FILEMUSTEXIST;
    ofn.lpstrTitle = "���l�uxls / mdb ��I�����邪�悢!!�v";
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
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char retPathBuffer[MAX_PATH] = {0};

	bool ret = false;
	IMalloc *m;
	if(SUCCEEDED(SHGetMalloc(&m)))
	{
		BROWSEINFO b;

		b.hwndOwner = this->m_hWnd;
		b.pidlRoot = NULL;
		b.pszDisplayName = retPathBuffer;
		b.lpszTitle = "�V�l�u.cvs��ۑ�����f�B���N�g�������Ă���̂���v" ;
		b.ulFlags = BIF_RETURNONLYFSDIRS; //�t�H���_�̂�
		b.lpfn = NULL;
		b.lParam = 0;
		b.iImage = 0;
		LPITEMIDLIST id = SHBrowseForFolder(&b); //�_�C�A���O�̕\��
		if(id)
		{
			SHGetPathFromIDList(id, retPathBuffer); //�p�X���𓾂�

			if (retPathBuffer[lstrlen(retPathBuffer)-1]!='\\') 
			{
				strcat(retPathBuffer,"\\"); //�Ō�� \\ 
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
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	CWnd * win;
	win = this->GetDlgItem(IDC_STATIC_JOB);
	win->ShowWindow( SW_HIDE);

	win = this->GetDlgItem(IDC_STATIC_PASSWORD);
	win->ShowWindow( SW_SHOW);

	win = this->GetDlgItem(IDC_EDIT_PASSWORD);
	win->ShowWindow( SW_SHOW);
}
