class CMainWin : public CFrameWnd
{
public:
	CBitmap bmp1,bmp2,bmp3;
	CMainWin(LPCSTR Classname);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT flags, CPoint loc);
	DECLARE_MESSAGE_MAP()
};

class CApp : public CWinApp
{
public:
	BOOL InitInstance();
};