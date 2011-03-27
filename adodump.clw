; CLW ファイルは MFC ClassWizard の情報を含んでいます。

[General Info]
Version=1
LastClass=CAdodumpDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "adodump.h"

ClassCount=3
Class1=CAdodumpApp
Class2=CAdodumpDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ADODUMP_DIALOG

[CLS:CAdodumpApp]
Type=0
HeaderFile=adodump.h
ImplementationFile=adodump.cpp
Filter=N

[CLS:CAdodumpDlg]
Type=0
HeaderFile=adodumpDlg.h
ImplementationFile=adodumpDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_STATIC_JOB

[CLS:CAboutDlg]
Type=0
HeaderFile=adodumpDlg.h
ImplementationFile=adodumpDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ADODUMP_DIALOG]
Type=1
Class=CAdodumpDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDC_EDIT_FILENAME,edit,1350631552
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_STATIC_JOB,static,1342308608
Control5=IDC_EDIT_DIR,edit,1350631552
Control6=IDC_BUTTON2,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC_PASSWORD,static,1073872896
Control10=IDC_EDIT_PASSWORD,edit,1082196096

