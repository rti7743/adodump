// adodumpDlg.h : �w�b�_�[ �t�@�C��
//

#if !defined(AFX_ADODUMPDLG_H__1E761F32_8775_4030_ABB8_2487003001C1__INCLUDED_)
#define AFX_ADODUMPDLG_H__1E761F32_8775_4030_ABB8_2487003001C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAdodumpDlg �_�C�A���O

class CAdodumpDlg : public CDialog
{
// �\�z
public:
	CAdodumpDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAdodumpDlg)
	enum { IDD = IDD_ADODUMP_DIALOG };
	CString	m_Filename;
	CString	m_OutDir;
	CString	m_Password;
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CAdodumpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HICON m_hIcon;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
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
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ADODUMPDLG_H__1E761F32_8775_4030_ABB8_2487003001C1__INCLUDED_)
