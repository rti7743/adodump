// adodump.h : ADODUMP �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#if !defined(AFX_ADODUMP_H__80829F19_1EFD_4E80_9E9C_F4BE75612C7E__INCLUDED_)
#define AFX_ADODUMP_H__80829F19_1EFD_4E80_9E9C_F4BE75612C7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CAdodumpApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� adodump.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CAdodumpApp : public CWinApp
{
public:
	CAdodumpApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CAdodumpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CAdodumpApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ADODUMP_H__80829F19_1EFD_4E80_9E9C_F4BE75612C7E__INCLUDED_)
