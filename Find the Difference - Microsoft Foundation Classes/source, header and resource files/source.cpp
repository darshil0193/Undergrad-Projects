#include <afxwin.h>
#include "resource.h"
#include "header.h"

int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,mark=0,x,y,img1=1,img2=0,img3=0,tot_mark=0,count=0,d_f_1=0,d_f_2=0,d_f_3=0,d_f_4=0,d_f_5=0;
char mark_str[50][3];
char cur_mark[100];
char marks[]="Your current marks are: ";
CMainWin::CMainWin(LPCSTR Classname)
{
	Create(Classname,"Find the Differences",SW_MAXIMIZE|WS_SYSMENU/*,rect*/);

	bmp1.LoadBitmap(MAKEINTRESOURCE(MY_BIT1234));//first image
	bmp2.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP1));//second image
	bmp3.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP2));//third image
}

BOOL CApp::InitInstance()
{
	CBrush bkbrush;
	bkbrush.CreateStockObject(WHITE_BRUSH);//white background brush
	LPCSTR Classname=AfxRegisterWndClass(0,LoadCursor(MAKEINTRESOURCE(MY_CURSOR1234)),bkbrush,LoadIcon(MAKEINTRESOURCE(MY_ICON1234)));//loading custom icon and cursor
	m_pMainWnd = new CMainWin(Classname);
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	InvalidateRect(NULL,0,1);

	return true;
}

afx_msg void CMainWin::OnPaint()
{
	
	CPaintDC dc2(this);
	CPen P;
	P.CreatePen(PS_SOLID,1,RGB(0,0,0));
	dc2.SelectObject(&P);
	CGdiObject B;
	B.CreateStockObject(HOLLOW_BRUSH);//null brush
	dc2.SelectObject(&B);
	if((flag1==0)&&(flag2==0)&&(flag3==0)&&(flag4==0)&&(flag5==0)&&(mark==0))//if new image is to be loaded
	{
		CClientDC dc(this);
		CDC memDC;

		memDC.CreateCompatibleDC(&dc);
		if((img1==1)&&(img2==0)&&(img3==0))//whether image to be loaded is first
		{
			memDC.SelectObject(&bmp1);
			dc.BitBlt(0,0,750,500,&memDC,0,0,SRCCOPY);
		}
		else if((img1==0)&&(img2==1)&&(img3==0))//whether next is clicked first time
		{
			memDC.SelectObject(&bmp2);
			dc.BitBlt(0,0,700,500,&memDC,0,0,SRCCOPY);
		}
		else if((img1==0)&&(img2==0)&&(img3==1))//whether next is clicked second time
		{
			memDC.SelectObject(&bmp3);
			dc.BitBlt(0,0,700,500,&memDC,0,0,SRCCOPY);
		}
		else if((img1==0&&img2==0&&img3==0))//whether next is clicked third time
		{
			MessageBox("Thank you for playing this game! Have a very nice time!");
			exit(0);
		}
		dc.Rectangle(700,225,750,270);//Creating next
		dc.TextOut(705,235,"NEXT",4);
	}
	if(flag1==1)//if a specific difference is found
	{
		if(img1==1&&img2==0&&img3==0)//is it image 1?
		{
			dc2.Ellipse(70,430,100,460);
			dc2.Ellipse(435,430,465,460);
		}
		if(img1==0&&img2==1&&img3==0)//or image 2?
		{
			dc2.Ellipse(0,465,30,495);
			dc2.Ellipse(350,465,380,495);
		}
		if(img1==0&&img2==0&&img3==1)//or image 3?
		{
			dc2.Ellipse(55,445,85,475);
			dc2.Ellipse(555,445,585,475);
		}
	}
	if(flag2==1)//same as above for next difference
	{
		if(img1==1&&img2==0&&img3==0)
		{
			dc2.Ellipse(245,395,275,425);
			dc2.Ellipse(615,395,645,425);
		}
		if(img1==0&&img2==1&&img3==0)
		{
			dc2.Ellipse(270,330,300,360);
			dc2.Ellipse(620,330,650,360);
		}
		if(img1==0&&img2==0&&img3==1)
		{
			dc2.Ellipse(265,260,295,290);
			dc2.Ellipse(400,260,430,290);
		}
	}
	if((flag3==1))
	{
		if(img1==1&&img2==0&&img3==0)
		{
			dc2.Ellipse(205,325,235,355);
			dc2.Ellipse(590,340,620,370);
		}
		if(img1==0&&img2==1&&img3==0)
		{
			dc2.Ellipse(215,225,245,255);
			dc2.Ellipse(565,225,595,255);
		}
		if(img1==0&&img2==0&&img3==1)
		{
			dc2.Ellipse(180,265,210,295);
			dc2.Ellipse(490,265,520,295);
		}
	}
	if((flag4==1))
	{
		if(img1==1&&img2==0&&img3==0)
		{
			dc2.Ellipse(145,190,175,220);
			dc2.Ellipse(500,190,530,220);
		}
		if(img1==0&&img2==1&&img3==0)
		{
			dc2.Ellipse(190,75,220,105);
			dc2.Ellipse(540,75,570,105);
		}
		if(img1==0&&img2==0&&img3==1)
		{
			dc2.Ellipse(50,230,80,260);
			dc2.Ellipse(625,230,655,260);
		}
	}
	if((flag5==1))
	{
		if(img1==1&&img2==0&&img3==0)
		{
			dc2.Ellipse(125,30,155,60);
			dc2.Ellipse(510,30,540,60);
		}
		if(img1==0&&img2==1&&img3==0)
		{
			dc2.Ellipse(30,370,60,400);
			dc2.Ellipse(380,370,410,400);
		}
		if(img1==0&&img2==0&&img3==1)
		{
			dc2.Ellipse(165,140,195,170);
			dc2.Ellipse(450,140,480,170);
		}
	}
	if(mark==5)
	{
		MessageBox("Excellent!!!");
	}
}

afx_msg void CMainWin::OnLButtonDown(UINT flag, CPoint loc)
{
	x=loc.x;
	y=loc.y;
	
	if(img1==1&&img2==0&&img3==0)//for first image
	{
		if(((x>70&&x<100&&y>430&&y<465)||(x>435&&x<470&&y>430&&y<465))&&(d_f_1==0))//difference 1 is found by user
		{
			flag1=1;//specific difference is found so flag for that difference is set
			d_f_1=1;//set flag to restrict entry again
			mark++;//increment mark
			InvalidateRect(NULL,0);//draw circles for this difference
		}
		if(((x>245&&y>395&&x<300&&y<470)||(x>615&&y>395&&x<670&&y<470))&&(d_f_2==0))//same as above
		{
			flag2=1;
			d_f_2=1;
			mark++;
			InvalidateRect(NULL,0);
		}
		if(((x>205&&y>325&&x<250&&y<370)||(x>590&&y>340&&x<610&&y<360))&&(d_f_3==0))
		{
			flag3=1;
			d_f_3=1;
			mark++;
			InvalidateRect(NULL,0);
		}
		if(((x>145&&y>190&&x<165&&y<250)||(x>500&&y>190&&x<535&&y<250))&&(d_f_4==0))
		{
			flag4=1;
			d_f_4=1;
			mark++;
			InvalidateRect(NULL,0);
		}
		if(((x>125&&y>30&&x<220&&y<85)||(x>510&&y>30&&x<570&&y<85))&&(d_f_5==0))
		{
			flag5=1;
			d_f_5=1;
			mark++;
			InvalidateRect(NULL,0);
		}
	}
	if(img1==0&&img2==1&&img3==0)//same as above for image 2
	{
		if(((x>0&&x<50&&y>465&&y<475)||(x>350&&x<400&&y>465&&y<475))&&(d_f_1==0))
		{
			flag1=1;
			d_f_1=1;
			mark++;
			InvalidateRect(NULL,0);
		}
		if(((x>270&&y>330&&x<315&&y<390)||(x>620&&y>330&&x<660&&y<390))&&(d_f_2==0))
		{
			flag2=1;
			d_f_2=1;
			mark++;
			InvalidateRect(NULL,0);
		}
		if(((x>215&&y>225&&x<250&&y<285)||(x>565&&y>225&&x<600&&y<285))&&(d_f_3==0))
		{
			flag3=1;
			d_f_3=1;
			mark++;
			InvalidateRect(NULL,0);
		}
		if(((x>190&&y>75&&x<215&&y<105)||(x>540&&y>75&&x<565&&y<105))&&(d_f_4==0))
		{
			flag4=1;
			d_f_4=1;
			mark++;
			InvalidateRect(NULL,0);
		}
		if(((x>30&&y>370&&x<85&&y<385)||(x>380&&y>370&&x<420&&y<385))&&(d_f_5==0))
		{
			flag5=1;
			d_f_5=1;
			mark++;
			InvalidateRect(NULL,0);
		}
	}
	if(img1==0&&img2==0&&img3==1)//same as above for image 3
	{
		if(((x>55&&x<150&&y>445&&y<490)||(x>555&&x<650&&y>445&&y<490))&&(d_f_1==0))
		{
			flag1=1;
			d_f_1=1;
			mark++;
			InvalidateRect(NULL,0);
		}
		if(((x>265&&y>260&&x<290&&y<280)||(x>400&&y>260&&x<425&&y<280))&&(d_f_2==0))
		{
			flag2=1;
			d_f_2=1;
			mark++;
			InvalidateRect(NULL,0);
		}
		if(((x>180&&y>265&&x<200&&y<280)||(x>490&&y>265&&x<510&&y<280))&&(d_f_3==0))
		{
			flag3=1;
			d_f_3=1;
			mark++;
			InvalidateRect(NULL,0);
		}
		if(((x>50&&y>230&&x<100&&y<285)||(x>625&&y>230&&x<680&&y<285))&&(d_f_4==0))
		{
			flag4=1;
			d_f_4=1;
			mark++;
			InvalidateRect(NULL,0);
		}
		if(((x>165&&y>140&&x<235&&y<160)||(x>450&&y>140&&x<530&&y<160))&&(d_f_5==0))
		{
			flag5=1;
			d_f_5=1;
			mark++;
			InvalidateRect(NULL,0);
		}
	}
	if((x>700)&&(y>225)&&(x<750)&&(y<270))//if next is clicked
	{
		flag1=0;//clear all flags for preparation of next image
		flag2=0;
		flag3=0;
		flag4=0;
		flag5=0;
		d_f_1=0;
		d_f_2=0;
		d_f_3=0;
		d_f_4=0;
		d_f_5=0;
		tot_mark+=mark;//update total marks and clear mark for next image
		mark=0;
		sprintf(mark_str[count],"%d",tot_mark);
		strcpy(cur_mark,marks);
		strcat(cur_mark,mark_str[count]);
		count++;
		MessageBox(cur_mark);//display total marks
		if(img1==1&&img2==0&&img3==0)//if image 1 was previous next is image 2
		{
			img1=0;
			img2=1;
			img3=0;
		}
		else if(img1==0&&img2==1&&img3==0)//image 3 after image 2
		{
			img1=0;
			img2=0;
			img3=1;
		}
		else if(img1==0&&img2==0&&img3==1)//end of game after image 3
		{
			img1=0;
			img2=0;
			img3=0;
		}
		InvalidateRect(NULL,1);
	}
}

BEGIN_MESSAGE_MAP(CMainWin,CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

CApp App;