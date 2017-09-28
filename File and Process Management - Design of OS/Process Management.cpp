#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int file(void);
int proc(void);


int main()
{
Start:    system("clear");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t*** Menu ***"<<endl
        <<"\n\t\t\t\t\t\t1. File info and directory traversing"<<endl
        <<"\n\t\t\t\t\t\t2. Process info"<<endl
        <<"\n\t\t\t\t\t\t3. Exit"<<endl
        <<"\n\t\t\t\t\t\tEnter your choice: ";
    int ch;
    cin>>ch;
    if(ch==1)
    {
        system("clear");
        file();
    }
    else if(ch==2)
    {
        system("clear");    
        proc();
    }
    else if(ch==3)
    {
        system("clear");
        exit(0);
    }
    else
    {
        system("clear");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\tIncorrect input\n\n\t\t\t\t\t\t\tReloading...\n";
        sleep(2);
        main();
    }
        return 0;
}


int file(void)
{
	int i=0;
	DIR *proc_dir;
	struct stat buf;
	struct dirent *cur_proc;
	char temp[1024],str[1024],def_str[1024]="/",temp2[2]="/";
Y:	system("clear");
	proc_dir=opendir(def_str);
Z:	cur_proc=readdir(proc_dir);
    cout<<"\n\n\n\n\n\t\t\tType \"help\" to see the instructions about using this program\n\n\n\n";
	cout<<"Directories and files in the current path (initially in root):\n\n "<<endl;
	while(1)
	{
		if(cur_proc==NULL)
			break;
		cout<<setw(20)<<cur_proc->d_name<<"\t";
		i++;
		if(i%5==0)
			cout<<endl<<endl;
		cur_proc=readdir(proc_dir);
	}
	
	cout<<endl<<"\n\nEnter Command: ";
	//gets(str);
	cin>>str;
	system("clear");
	if((str[0]=='c')&&(str[1]=='d'))
	{
		strcpy(str,(str+2));/*
		if(strcmp(def_str,temp2)==0)
			strcat(def_str,str);
		else
		{
			strcat(def_str,temp2);
			strcat(def_str,str);
		}*/
		if(strcmp(def_str,temp2)!=0)
		    strcat(def_str,temp2);
		strcat(def_str,str);
		
		proc_dir=0;
		cur_proc=0;
		proc_dir=opendir(def_str);
		goto Z;
	}
	else if(strcmp(str,"exit")==0)
	{
		exit(0);
	}
	else if(strcmp(str,"back")==0)
	{
	    main();
	}
	else if(strcmp(str,"help")==0)
	{
	    cout<<"\n\n\n\n\n\t\t\t\t*** HELP ***\n"<<endl;
		cout<<"\t1. Type \"cd\" followed by directory name to change path\n"<<endl;
		cout<<"\t2. Type the directory or file name to display its information\n"<<endl;
		cout<<"\t3. Type \"history\" to see your traversal history\n"<<endl;
		cout<<"\t4. Type \"back\" to go back to main menu\n"<<endl;
		cout<<"\t5. Type \"exit\" to end execution of the program\n"<<endl;		
		//cout<<"Press enter to continue...";
		//getchar();
	A:	cout<<endl<<"Press B followed by enter to continue: ";
		char a;
		cin>>a;
		if(a=='b' || a=='B')
		    goto Y;
		else
		    goto A;		

		//system("clear");
		//goto Y;
	}
	else if(strcmp(str,"history")==0)
	{
	    cout<<"\n\n\n\n\n";
   		cout<<"The traversed path since the program start is: "<<endl<<endl;
		cout<<"\t\t\t"<<def_str<<endl;
		//cout<<"Press enter to continue...";
		//getchar();
		//system("clear");
		//goto Y;
	B:	cout<<endl<<"Press B followed by enter to continue: ";
		char a;
		cin>>a;
		if(a=='b' || a=='B')
		    goto Y;
		else
		    goto B;		

	}
	else
	{
		strcpy(temp,def_str);
		if(strcmp(def_str,temp2)!=0)
		{
			strcat(temp,temp2);
			strcat(temp,str);
		}
		else
			strcat(temp,str);
		if(stat(temp,&buf)==-1)
		{
		    //cout<<"Retry in 5 seconds";		    
		    perror("\n\n\n\n\n\t\t\t\t\t\t\tRetry after 3 seconds\n\n\t\t\t\t\t\tError");
		    sleep(3);
		    file();
			//cout<<"Unable to access file/directory"<<endl;
		}
		else
		{
		    cout<<"\n\n\n\n\n\t\t\t\t\t\t*** INODE INFORMATION ***"<<endl;
			cout<<"\n\t\t\tInode number: "<<buf.st_ino<<endl;
			cout<<"\n\t\t\tSize: "<<buf.st_size<<" bytes"<<endl;
			cout<<"\n\t\t\tType: ";
			//cout<<"\t\t\t";
			switch (buf.st_mode & S_IFMT) 
			{
				case S_IFBLK:  cout<<"Block Device";break;
				case S_IFCHR:  cout<<"Character Device";break;
				case S_IFDIR:  cout<<"Directory";	break;
				case S_IFIFO:  cout<<"FIFO/pipe";	break;
				case S_IFLNK:  cout<<"Symbolic Link";		break;
				case S_IFREG:  cout<<"Regular File";	break;
				case S_IFSOCK: cout<<"Socket";		break;
			}
			cout<<endl;
			cout<<"\n\t\t\tLink Count: "<<buf.st_nlink<<endl;
			cout<<"\n\t\t\tBlocks Allocated: "<<buf.st_blocks<<endl;
			cout<<"\n\t\t\tI/O Block Size: "<<buf.st_blksize<<endl;
			cout<<"\n\t\t\tLast Change Time: "<<ctime(&buf.st_ctime);
			cout<<"\n\t\t\tLast Accessed Time: "<<ctime(&buf.st_atime);
			cout<<"\n\t\t\tLast Modified Time: "<<ctime(&buf.st_mtime);
			cur_proc=0;
			proc_dir=0;
			//cout<<endl<<"Press enter to continue...";
			//getchar();
			//system("clear");
			//goto Y;
		C:	cout<<endl<<"\n\nPress B followed by enter to continue: ";
		char a;
		cin>>a;
		if(a=='b' || a=='B')
		    goto Y;
		else
		    goto C;		

		}
	}
	return 0;
}


void current_processes(void)
{   
	DIR *proc_dir;
	int i=0,pro;
	struct dirent *cur_proc;

	proc_dir=0;
	cur_proc=0;
	proc_dir=opendir("/proc");
	cur_proc=readdir(proc_dir);
	cout<<"\n\n\n\n\n\t\t\tType \"help\" to see the instructions about using this program\n\n\n\n";
	cout<<"Currently running processes(PIDs):\n"<<endl;
	while(1)
	{
		cur_proc=readdir(proc_dir);
		if(cur_proc==NULL)
			break;
		pro=atoi(cur_proc->d_name);
		if(pro!=0)
		{
			cout<<setw(10)<<cur_proc->d_name<<"\t";
			i++;
			if(i%8==0)
				cout<<endl;
		}
	}
}

void region_table(void)
{
    cout<<endl<<"\t\t*** REGION TABLE ***\t\t\t\t\t*** PAGE TABLES ***\n\n";
    cout<<setw(20)<<"Region"<<setw(20)<<"Virtual Address"<<setw(20)<<"Text"<<setw(20)<<"Data"<<setw(20)<<"Stack"<<endl;
    cout<<setw(20)<<"Text"<<setw(20)<<"4096"<<setw(20)<<"856K"<<setw(20)<<"747K"<<setw(20)<<"556K"<<endl;
    cout<<setw(20)<<"Data"<<setw(20)<<"8192"<<setw(20)<<"917K"<<setw(20)<<"950K"<<setw(20)<<"997K"<<endl;
    cout<<setw(20)<<"Stack"<<setw(20)<<"16384"<<setw(20)<<"."<<setw(20)<<"."<<setw(20)<<"."<<endl;
    
//    cout<<"Page Tables"<<endl;
//    cout<<setw(20)<<"Text"<<setw(20)<<"Data"<<setw(20)<<"Stack"<<endl;        
//    cout<<setw(20)<<"856K"<<setw(20)<<"747K"<<setw(20)<<"556K"<<endl;        
//    cout<<setw(20)<<"917K"<<setw(20)<<"950K"<<setw(20)<<"997K"<<endl;
//    cout<<setw(20)<<"."<<setw(20)<<"."<<setw(20)<<"."<<endl;
    cout<<setw(60)<<"."<<setw(20)<<"."<<setw(20)<<"."<<endl;
    cout<<setw(60)<<"."<<setw(20)<<"."<<setw(20)<<"."<<endl;
    cout<<setw(60)<<"444K"<<setw(20)<<"333K"<<setw(20)<<"632K"<<endl<<endl<<endl;
    
    cout<<"\t\t\t\t\t\t*** Triples ***\n"<<endl;
    cout<<setw(10)<<" "<<setw(30)<<"Address of page table"<<setw(20)<<"Virtual Address"<<setw(20)<<"No. of pages"<<endl;    
    cout<<setw(10)<<"Kernel"<<setw(30)<<"42K"<<setw(20)<<"0"<<setw(20)<<"1"<<endl;
    cout<<setw(10)<<"Kernel"<<setw(30)<<"242K"<<setw(20)<<"1K"<<setw(20)<<"1"<<endl;
    cout<<setw(10)<<"Kernel"<<setw(30)<<"149K"<<setw(20)<<"2K"<<setw(20)<<"2"<<endl;
    cout<<setw(10)<<"User"<<setw(30)<<"67K"<<setw(20)<<"4K"<<setw(20)<<"4"<<endl;
    cout<<setw(10)<<"User"<<setw(30)<<"357K"<<setw(20)<<"8K"<<setw(20)<<"8"<<endl;
    cout<<setw(10)<<"User"<<setw(30)<<"268K"<<setw(20)<<"16K"<<setw(20)<<"16"<<endl;
}

int proc(void)
{
	char temp[1024],str[1024]="",def_str[1024]="/";
X:	system("clear");
	current_processes();
	cout<<endl<<"\n\nEnter command: ";
//	cout<<"(write help to see how to use the program):";
//	scanf("%[^\n]",str);
	cin>>str;
	//gets(str);
	//cout<<"\n\nhello"<<str<<endl<<endl;
	//sleep(2);
	system("clear");
	if(strcmp(str,"exit")==0)
	{
		exit(0);
	}
	else if(strcmp(str,"back")==0)
	{
	    main();
	}
	else if(strcmp(str,"cpuinfo")==0)
	{
	    cout<<"\n\n\n\n\n\t\t\t\t\t\t*** CPU Information ***\n\n";
		system("cat /proc/cpuinfo");
		//cout<<endl<<"Press Enter to continue..."<<endl;
		//getchar();
		//sleep(5);
		//goto X;
	A:	cout<<endl<<"Press B followed by enter to continue: ";
		char a;
		cin>>a;
		if(a=='b' || a=='B')
		    goto X;
		else
		    goto A;		

	}
	else if((str[0]=='e')&&(str[1]=='n')&&(str[2]=='d'))
	{
		strcpy(str,(str+3));
		if(kill((pid_t)atoi(str),SIGKILL)==-1)
		{
		    perror("\n\n\n\n\n\t\t\t\t\t\t\tRetry after 3 seconds\n\n\t\t\t\t\t\tError");
		    sleep(3);
		    proc();
		    //perror("Error");
//			cout<<"Failed to end, not permitted!"<<endl;
        }
		else
			cout<<"\n\n\n\n\n\t\t\t\t\t\tProcess with PID "<<str<<" successfully killed"<<endl;
		//cout<<endl<<"Press Enter to continue...";
		//getchar();
	 D:	cout<<endl<<"\nPress B followed by enter to continue: ";
		char a;
		cin>>a;
		if(a=='b' || a=='B')
		    goto X;
		else
		    goto D;
	}
	else if(strcmp(str,"help")==0)
	{
	    cout<<"\n\n\n\n\n\t\t\t\t*** HELP ***\n"<<endl;
		cout<<"\t1. Type \"cpuinfo\" to get the information about processor cores currently in use\n"<<endl;
		cout<<"\t2. Type \"PID\" of any process to display its information\n"<<endl;
		cout<<"\t3. Type \"end\" followed by PID of the process to kill the process\n"<<endl;
		cout<<"\t4. Type \"back\" to go back to main menu\n"<<endl;		
		cout<<"\t5. Type \"exit\" to end execution of the program\n"<<endl;
		//cout<<"Press Enter to continue...";
		//getchar();
    B:	cout<<endl<<"Press B followed by enter to continue: ";
		char a;
		cin>>a;
		if(a=='b' || a=='B')
		    goto X;
		else
		    goto B;		
	}
	else
	{
	    system("clear");
		strcpy(def_str,"/proc/");
		strcat(def_str,str);
		if(opendir(def_str)==NULL)
		{
	        cout<<"\n\n\n\n\n\t\t\t\t\t\t\tRetry after 3 seconds\n\n\t\t\t\t\t\tError: Process with PID "<<str<<" doesnot exist\n";
		    sleep(3);
		    proc();
		}
	    else
	    {
		    cout<<"Scheduling information: \n"<<endl;
		    strcpy(temp,"cat ");
		    strcat(temp,def_str);
		    strcat(temp,"/sched");
		    system(temp);
		    cout<<endl<<"Limits information: \n"<<endl;
		    strcpy(temp,"cat ");
		    strcat(temp,def_str);
		    strcat(temp,"/limits");
		    system(temp);
		    cout<<"\nLogin User ID: \n\t";
    //		cout<<" is Login user ID";
		    strcpy(temp,"cat ");
		    strcat(temp,def_str);
		    strcat(temp,"/loginuid");

		    system(temp);
    //		cout<<endl<<" is Session ID";
		    cout<<"\n\nSession ID: \n\t";
		    strcpy(temp,"cat ");
		    strcat(temp,def_str);
		    strcat(temp,"/sessionid");
		    system(temp);
		    cout<<endl;
		    region_table();
		}
	C:	cout<<endl<<"Press B followed by enter to continue: ";
		char a;
		cin>>a;
		if(a=='b' || a=='B')
		    goto X;
		else
		    goto C;
	}
	return 0;
}

