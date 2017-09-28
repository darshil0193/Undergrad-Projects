#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<dos.h>
#include<conio.h>
#include<limits.h>
#include<graphics.h>
#include<stdio.h>
#include<process.h>

struct job          		//Structure for storing hetrogeneous type of data
  {
  int pid;           //Process ID
  float at;          //Arrival Time
  float bt;          //Burst Time
  int priority;      //Priority
  }*J,*temp;

int t=0;

void gantt(int a[],int size,int proc,int ch)
  {
  int gm,gd,errorcode,left,top,right,bottom;
  int *b;
  gd=DETECT;
  initgraph(&gd,&gm,"");   //initialize graphics mode
  errorcode=graphresult();  //read result of initialization
  if(errorcode!=grOk)   //an error occurred
    {
    cout<<"Graphics error: "<<grapherrormsg(errorcode);
    cout<<"Press any key to exit: ";
    getch();
    exit(1);             // return with error code
   }
  b=new int[proc];
  for(int i=0;i<proc;i++)
    {
    b[i]=J[i].pid;
    }
  cout<<endl;
  int c;

  c = 20;

  cleardevice();
  line(0,29,getmaxx(),29);
  line(20,0,20,getmaxy());
  for(i=1;i<proc+1;i++)
    {
    line(0,15*i+30,getmaxx(),15*i+30);
    }
  if(ch==3)
    {
    for(i=0;i<size;i++)
      {
      setbkcolor(8);
      left=c+1;
      top=15+a[i]*15;//top=15+(b[i])*15;
      bottom=top+15;
      right=c+20;
      delay(1000);
      setcolor(i+1);
     // for(int j=0;j<size;j++)
     // setfillstyle(j+J[i].bt,i+4);
      rectangle(left,top,right,bottom);
      char * tmp;
      tmp=itoa(a[i],tmp,10);
      outtextxy(left+5,top+5,tmp);
      //floodfill(left+10,top+10,i+1);   // draw a rectangle
      c=c+20;
      }
    }
  else
    {
    for (i=0;i<proc;i++)
      {
      setbkcolor(8);
      for(int j=0;j<size;j++)
	{
	if(a[j]==b[i])
	  {
	  setcolor(i+b[i]);
	  top=15+J[i].pid*15;//top=15+(b[i])*15;
	  bottom=top+15;
	  }
	else
	  continue;
	left=c+1;
	right=c+20;
	delay(1000);
	setcolor(i+1);
	setfillstyle(i+J[i].bt,i+4);
	rectangle(left,top,right,bottom);
	/*char * tmp;
	tmp=itoa(J[i].pid,tmp,10);
	outtextxy(left+5,top+5,tmp);*/
	floodfill(left+10,top+10,i+1);   // draw a rectangle
	c=c+20;
	}
      }
    }
  getch();
  closegraph();
  }

void welcome(void)
  {
  clrscr();
  int gm,gd,errorcode;//,left,top,right,bottom;
  //int *b;
  gd=DETECT;
  initgraph(&gd,&gm,"");   //initialize graphics mode
  errorcode=graphresult();  //read result of initialization
  if(errorcode!=grOk)   //an error occurred
    {
    cout<<"Graphics error: "<<grapherrormsg(errorcode);
    cout<<"Press any key to exit: ";
    getch();
    exit(1);             // return with error code
   }
   cleardevice();
  setbkcolor(6);
  //cleardevice();
  setcolor(15);
  char msg[25];
  settextstyle(SMALL_FONT, HORIZ_DIR,20);
  sprintf(msg,"Welcome");
  //int h,w ;
  settextjustify(CENTER_TEXT,CENTER_TEXT);
  outtextxy(getmaxx()/2,getmaxy()/2,msg);
  //w=textwidth(msg);h=textheight(msg);
  //cout<<w<<endl<<h;
  rectangle(getmaxx()/2-90,getmaxy()/2-15,getmaxx()/2+80,getmaxy()/2+25);
  delay(1000);
  settextstyle(SMALL_FONT, HORIZ_DIR,5);
  sprintf(msg,"Press any key to begin...");
  settextstyle(SMALL_FONT, HORIZ_DIR,5);
  settextjustify(LEFT_TEXT,CENTER_TEXT);
  outtextxy(1,getmaxy()-10,msg);
  int x,y;
  for(int i=0;i<400;i++)
    {
    setcolor(i%15);
    x=random(getmaxx());
    y=random(getmaxy());
    circle(x,y,1);
    delay(5);
    }
  getch();
  closegraph();
  }

void thank_you(void)
  {
  clrscr();
  int gm,gd,errorcode;//,left,top,right,bottom;
  //int *b;
  gd=DETECT;
  initgraph(&gd,&gm,"");   //initialize graphics mode
  errorcode=graphresult();  //read result of initialization
  if(errorcode!=grOk)   //an error occurred
    {
    cout<<"Graphics error: "<<grapherrormsg(errorcode);
    cout<<"Press any key to exit: ";
    getch();
    exit(1);             // return with error code
   }
  cleardevice();
  setbkcolor(6);

  char msg[20];
  setcolor(15);
  settextstyle(SMALL_FONT, HORIZ_DIR,20);
  sprintf(msg,"Thank You");
  //int h,w ;
  settextjustify(CENTER_TEXT,CENTER_TEXT);
  outtextxy(getmaxx()/2,60,msg);
  //int w,h;
  //w=textwidth(msg);h=textheight(msg);
  //cout<<w<<endl<<h;
  rectangle(getmaxx()/2-115,45,getmaxx()/2+110,85);
  delay(500);

  settextstyle(SMALL_FONT, HORIZ_DIR,9);
  sprintf(msg,"Guided By: ");
  //int h,w ;
  settextjustify(LEFT_TEXT,CENTER_TEXT);
  outtextxy(10,190,msg);
  //int w,h;
  //w=textwidth(msg);h=textheight(msg);
  //cout<<w<<endl<<h;
  //rectangle(getmaxx()/2-115,5,getmaxx()/2+110,45);
  delay(200);
  sprintf(msg,"Prof. K. P. Agrawal");
  //int h,w ;
  settextjustify(CENTER_TEXT,CENTER_TEXT);
  outtextxy(getmaxx()/2,getmaxy()/2,msg);
  delay(500);
  settextstyle(SMALL_FONT, HORIZ_DIR,7);
  sprintf(msg,"Prepared By:");
  settextstyle(SMALL_FONT, HORIZ_DIR,7);
  settextjustify(RIGHT_TEXT,CENTER_TEXT);
  outtextxy(600,getmaxy()-160,msg);
  delay(200);
  sprintf(msg,"11bce069");
  settextstyle(SMALL_FONT, HORIZ_DIR,7);
  settextjustify(RIGHT_TEXT,CENTER_TEXT);
  outtextxy(630,getmaxy()-120,msg);
  delay(200);
  sprintf(msg,"11bce070");
  settextstyle(SMALL_FONT, HORIZ_DIR,7);
  settextjustify(RIGHT_TEXT,CENTER_TEXT);
  outtextxy(630,getmaxy()-100,msg);
  delay(200);
  sprintf(msg,"11bce092");
  settextstyle(SMALL_FONT, HORIZ_DIR,7);
  settextjustify(RIGHT_TEXT,CENTER_TEXT);
  outtextxy(630,getmaxy()-80,msg);
  delay(200);
  sprintf(msg,"11bce097");
  settextstyle(SMALL_FONT, HORIZ_DIR,7);
  settextjustify(RIGHT_TEXT,CENTER_TEXT);
  outtextxy(630,getmaxy()-60,msg);
  delay(200);
  sprintf(msg,"11bce098");
  settextstyle(SMALL_FONT, HORIZ_DIR,7);
  settextjustify(RIGHT_TEXT,CENTER_TEXT);
  outtextxy(630,getmaxy()-40,msg);
  int x,y;
  for(int i=0;i<200;i++)
    {
    setcolor(i%15);
    x=random(getmaxx());
    y=random(getmaxy());
    circle(x,y,1);
    delay(10);
    }
  getch();
  closegraph();
  exit(0);
  }

int menu(void)       //MENU
  {
T:  clrscr();
  cout<<"1. FCFS\n"
      <<"2. SJF\n"
      <<"3. RR\n"
      <<"4. Priority\n"
      <<"5. Exit\n"
      <<"Enter your choice: ";
  int ch;
  cin>>ch;
  if(ch<=0 || ch>5)
    {
    cout<<"\nInvalid Entery"
	<<"\nPress a key to Re-enter";
    getch();
    goto T;
    }
  return(ch);
  }

int input(int ch)         //Taking Input
  {
  cout<<"\nEnter the number of processes: ";
  int n;
  cin>>n;
  J=new struct job[n];
  temp=new struct job[n];
  for(int i=0;i<n;i++)
    {
    J[i].pid=i+1;
    J[i].priority=1;
    cout<<"\nEnter details of process "<<i+1;
    cout<<"\nArrival Time: ";
    cin>>J[i].at;
    cout<<"CPU Burst: ";
    cin>>J[i].bt;
    if(ch==4)
      {
      cout<<"Priority: ";
      cin>>J[i].priority;
      }
    }
  return(n);
  }

void sort(int n)            //Sorting according to arrival time
  {
  float KEY[3];
  int j;
  for(int i=0;i<n;i++)
    {
    j=i-1;
    KEY[0]=J[i].pid;
    KEY[1]=J[i].at;
    KEY[2]=J[i].bt;
    while((j>=0) && (J[j].at>KEY[1]))
      {
      J[j+1].at=J[j].at;
      J[j+1].bt=J[j].bt;
      J[j+1].pid=J[j].pid;
      j--;
      }
    J[j+1].pid=KEY[0];
    J[j+1].at=KEY[1];
    J[j+1].bt=KEY[2];
    }
  }

void view(int n)           //View the row of the table
  {
  cout<<endl;
  cout.width(4);
  cout<<n+1<<"\t\t";
  cout.width(4);
  cout<<J[n].at<<"\t\t";
  cout.width(4);
  cout<<J[n].bt<<"\t\t";
  cout.width(4);
  cout<<J[n].priority;
  temp[t].pid=n+1;
  temp[t].at=J[n].at;
  temp[t].bt=J[n].bt;
  temp[t].priority=J[n].priority;
  t++;
  }

void calculate(int n,int ch)      //Calculation of avg_wt and avg_tat
  {
  float tat=0,wt=0;
  float *temp;
  int k=0,q=0,*sec;
  temp=new float[n];
  cout<<endl;
  for(int i=0;i<n;i++)
    {
    q+=J[i].bt;
    }
  sec=new int[q];
  cout<<"\nProcesses Execution Sequence:\n";
  for(i=0;i<n;i++)
    {
    for(int j=0;j<J[i].bt;j++)
      {
      cout<<i+1<<"\t";
      sec[k]=J[i].pid;//i+1;
      k++;
      }
    if(j==J[i].bt)
      {
      tat+=J[i].bt;
      temp[i]=tat;
      }
    cout<<endl;
    }
  tat=0;
  for(i=0;i<n;i++)
    {
    tat+=(temp[i]-J[i].at);
    }
  for(i=0;i<n-1;i++)
    {
    wt+=(temp[i]-J[i+1].at);
    }
  tat/=n;
  wt/=n;
  cout<<"\n\nAverage Turn Around Time: "<<tat;
  cout<<"\nAverage Waiting Time: "<<wt;
  getch();
  gantt(sec,q,n,ch);
  }

void FCFS(int n,int ch)         //FCFS
  {
  clrscr();
  cout<<"Process ID\tArrival Time\tBurst Time\tPriority"<<endl;
  for(int i=0;i<n;i++)
    view(i);
  calculate(n,ch);
  }

void SJF(int n,int ch)               //SJF
  {
  int time=0;
  int *status;
  status=new int[n];
  for(int i=0;i<n;i++)
    {
    status[i]=0;
    }
  int flag=1,pro_num=0;
  clrscr();
  cout<<"PID No\tArrival Time\tBurst Time\tPriority"<<endl;
  while(flag)
    {
    int shortest_time;
    for(i=0;i<n;i++)
      {
      shortest_time=INT_MAX;
      for(int j=0;j<n;j++)
	{
	if(J[j].bt<=shortest_time && J[j].at<=time && status[j]==0)
	  {
	  shortest_time=J[j].bt;
	  pro_num=j;
	  }
	}
      }
    view(pro_num);
    status[pro_num]=1;
    time+=J[pro_num].bt;
    int finish=0;
    for(int k=0;k<n;k++)
      {
      if(status[k]==1)
	{
	finish++;
	}
      }
    if(finish==n)
      {
      flag=0;
      }
    finish=0;
    }
  for(i=0;i<n;i++)
    {
    J[i]=temp[i];
    /*J[i].pid=temp[i].pid;
    J[i].at=temp[i].at;
    J[i].bt=temp[i].bt;*/
    }
  calculate(n,ch);
  }

void PRIORITY(int n,int ch)           //Non-Preemptive Priority scheduling
  {
  int time=0;
  int *status;
  status=new int[n];
  for(int i=0;i<n;i++)
    {
    status[i]=0;
    }
  int flag=1,pro_num=0;
  clrscr();
  cout<<"PID No.\tArrival Time\tBurst Time\tPriority"<<endl;
  while(flag)
    {
    int max_priority;
    for(i=0;i<n;i++)
      {
      max_priority=INT_MAX;
      for(int j=0;j<n;j++)
	{
	if(J[j].priority<=max_priority && J[j].at<=time && status[j]==0)
	  {
	  max_priority=J[j].priority;
	  pro_num=j;
	  }
	}
      }
    view(pro_num);
    status[pro_num]=1;
    time+=J[pro_num].bt;
    int finish=0;
    for(int k=0;k<n;k++)
      {
      if(status[k]==1)
	{
	finish++;
	}
      }
    if(finish==n)
      {
      flag=0;
      }
    finish=0;
    }
  for(i=0;i<n;i++)
    {
    J[i]=temp[i];
    /*
    J[i].pid=temp[i].pid;
    J[i].at=temp[i].at;
    J[i].bt=temp[i].bt; */
    }
  calculate(n,ch);
  }

void RR(int n,int tq,int ch)//round robin scheduling
  {
  int i,j,*finished,*check,total,timeline=0,sum=0,m=0;
  int *seq;
  float *tat,*wt,avwt=0,avtat=0;
  tat=new float[n];
  wt=new float[n];
  finished=new int[n];
  check=new int[n];
  for(i=0;i<n;i++)//initialize finished and check arrays
    {
    J[i].pid=i+1;
    sum+=J[i].bt;
    finished[i]=0;
    check[i]=0;
    wt[i]=0;
    tat[i]=0;
    }
  seq=new int[sum];
  i=0;
  while(1)
    {
    if(J[i].bt==0) //if process has completed execuiton
      {				 // increase the time
      timeline++;
      goto inr;
      }
    if(J[i].bt>tq)//if process is remaining & bt>tq
      {
      for(int k=0;k<tq;k++)
	{
	seq[m]=J[i].pid;
	m++;
	}
      timeline=timeline+tq;
      J[i].bt=J[i].bt-tq;
      }
    else //bt<tq
      {
      for(int k=0;k<J[i].bt;k++)
	{
	seq[m]=J[i].pid;
	m++;
	}
      timeline=timeline+J[i].bt;
      J[i].bt=0;
      tat[i]=timeline-J[i].at;
      finished[i]=1;
      }
    total=0;
    for(j=0;j<n;j++) //condition for termination of algorithm
      {
      total=total+finished[j];
      }
    if(total==n)
      break;

inr: //go to next process in queue
    if(J[(i+1)%n].at<timeline)
      {
      i++;
      i=i%n;
      if(check[i]==0)  //counter for wait time
	{
	wt[i]=timeline-J[i].at;
	check[i]=1;
	}
      }
    else
      {
      i++;
      i=i%n;
      goto inr;
      }
    if(finished[i]==1 && total!=n)
      goto inr;
    }
  wt[0]=0;
  for(i=0;i<n;i++)//calculating avg tat and avg wt
    {
    avtat=avtat+tat[i];
    avwt=avwt+wt[i];//-J[i].at;
    }
  avtat=avtat/n;
  avwt=avwt/n;
  cout<<"\navtat = "<<avtat;
  cout<<"\navwt = "<<avwt;
  cout<<"\nExecution Sequence is: \n";
  for(i=0;i<sum;i++)
    cout<<seq[i]<<"\t";
  getch();
  gantt(seq,sum,n,ch);
  }

void main()                                   //MAIN
  {
  int ch,n,tq;
  welcome();
T:  ch=menu();
  if(ch!=5)
  n=input(ch);
  switch(ch)
    {
    case 1:
	   sort(n);
	   FCFS(n,ch);
	   goto T;
	   //break;
    case 2:
	   SJF(n,ch);
	   goto T;
	   //break;
    case 3:
	   cout<<"\nEnter the time quantum: ";
	   cin>>tq;
	   sort(n);
	   RR(n,tq,ch);
	   goto T;
	   //break;
    case 4:
	   PRIORITY(n,ch);
	   goto T;
	   //break;
    case 5:
	   thank_you();
	   break;
    default:
	   cout<<"\nInvalid Entery"
	       <<"\nPress a key to Re-enter";
	   getch();
	   goto T;
    }
  //thank_you();
  }