#include <stdio.h>
#include <iostream>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

using namespace std;

int main()
{
	int i=0;
	DIR *proc_dir;
	struct stat buf;
	struct dirent *cur_proc;
	char temp[1024],str[1024],def_str[1024]="/",temp2[2]="/";
	system("clear");
Y:	proc_dir=opendir(def_str);
Z:	cur_proc=readdir(proc_dir);
	cout<<"Directories and files in the current path(initially in root):"<<endl;i=0;
	while(1)
	{
		if(cur_proc==NULL)
			break;
		cout<<cur_proc->d_name<<"\t";
		i++;
		if(i%5==0)
			cout<<endl;
		cur_proc=readdir(proc_dir);
	}
	cout<<endl<<"Enter name";
	cout<<"(write help to see the instructions about using this program):";
	gets(str);
	system("clear");
	if((str[0]=='c')&&(str[1]=='d')&&(str[2]==' '))
	{
		strcpy(str,(str+3));
		if(strcmp(def_str,temp2)==0)
			strcat(def_str,str);
		else
		{
			strcat(def_str,temp2);
			strcat(def_str,str);
		}
		proc_dir=0;
		cur_proc=0;
		proc_dir=opendir(def_str);
		goto Z;
	}
	else if(strcmp(str,"exit")==0)
	{
		exit(0);
	}
	else if(strcmp(str,"help")==0)
	{
		cout<<"write cd followed by a white space followed by directory name to change path"<<endl;
		cout<<"Write simply the directory or file name to display its information"<<endl;
		cout<<"Write history to see your traversal path from the beginning of the execution of program"<<endl;
		cout<<"Press enter to continue...";
		getchar();
		system("clear");
		goto Y;
	}
	else if(strcmp(str,"history")==0)
	{
		cout<<def_str<<endl;
		cout<<"Press enter to continue...";
		getchar();
		system("clear");
		goto Y;
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
			cout<<"Error in opening the file"<<endl;
		}
		else
		{
			cout<<"Inode number: "<<buf.st_ino<<endl;
			cout<<"Size: "<<buf.st_size<<endl;
			cout<<"Type: ";
			switch (buf.st_mode & S_IFMT) 
			{
				case S_IFBLK:  cout<<"block device";break;
				case S_IFCHR:  cout<<"character device";break;
				case S_IFDIR:  cout<<"directory";	break;
				case S_IFIFO:  cout<<"FIFO/pipe";	break;
				case S_IFLNK:  cout<<"symlink";		break;
				case S_IFREG:  cout<<"regular file";	break;
				case S_IFSOCK: cout<<"socket";		break;
			}
			cout<<endl;
			cout<<"Link count: "<<buf.st_nlink<<endl;
			cout<<"Blocks allocated: "<<buf.st_blocks<<endl;
			cout<<"I/O block size: "<<buf.st_blksize<<endl;
			cout<<"Last change time: "<<ctime(&buf.st_ctime)<<endl;
			cout<<"Last accessed time: "<<ctime(&buf.st_atime)<<endl;
			cout<<"Last modified time: "<<ctime(&buf.st_mtime)<<endl;
			cur_proc=0;
			proc_dir=0;
			cout<<endl<<"Press enter to continue...";
			getchar();
			system("clear");
			goto Y;
		}
	}
}
