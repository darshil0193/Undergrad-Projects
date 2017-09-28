#include<iostream.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>

char *X,*Y,*Z,*key,*cipherbit,*string,*ans;
int len;


void input(void)       //Used to get input from the user
{
	int flag=0;
	string=new char[100];  //String size can be maximum of 99 characters
	cout<<"\nEnter the String: ";    //Recieving the string from user
	cin>>string;
	cout<<"\nEnter the 64bit key in hexadecimal format: ";
	//Recieving the	Hexadecimal 64bit key from user
	key=new char[17];  //contains 17 characters (16 for key 1 for \0)
	cin>>key;
	if(strlen(key)!=16) //If key is not 16 character
			    //length than it is not required 64 bit key
		{
		cout<<"\nInvalid input of hexadecimal number"
		    <<"\nPress a key to re-enter";
		getch();
		input();    //If incorrect get input again
		}
	for(int i=0;key[i]!='\0';i++)//Check whether input is valid hex or not
	{
		key[i]=toupper(key[i]);
		if(key[i]<'0')
			flag=1;
		else if(key[i]>'9' && key[i]<'A')
			flag=1;
		else if(key[i]>'F')
			flag=1;
	}
	if(flag==1)    //If invalid
		{
		cout<<"\nInvalid input of hexadecimal number"
		    <<"\nPress a key to re-enter";
		getch();
		input();   //Get input again
		}
	else
		{
		cout<<"\nThe key is: "; //Display key if it is correct
		cout<<"0x"<<key<<endl;
		}
}

void convert(char n,int pos) //Converting Hex key to binary key in 3
			     //different (X,Y,Z) shift registers
{
	char *temp;
	temp=new char[5];
	switch (n)
	{
	case '0':temp[0]='0';temp[1]='0';temp[2]='0';temp[3]='0';break;
	case '1':temp[0]='0';temp[1]='0';temp[2]='0';temp[3]='1';break;
	case '2':temp[0]='0';temp[1]='0';temp[2]='1';temp[3]='0';break;
	case '3':temp[0]='0';temp[1]='0';temp[2]='1';temp[3]='1';break;
	case '4':temp[0]='0';temp[1]='1';temp[2]='0';temp[3]='0';break;
	case '5':temp[0]='0';temp[1]='1';temp[2]='0';temp[3]='1';break;
	case '6':temp[0]='0';temp[1]='1';temp[2]='1';temp[3]='0';break;
	case '7':temp[0]='0';temp[1]='1';temp[2]='1';temp[3]='1';break;
	case '8':temp[0]='1';temp[1]='0';temp[2]='0';temp[3]='0';break;
	case '9':temp[0]='1';temp[1]='0';temp[2]='0';temp[3]='1';break;
	case 'A':temp[0]='1';temp[1]='0';temp[2]='1';temp[3]='0';break;
	case 'B':temp[0]='1';temp[1]='0';temp[2]='1';temp[3]='1';break;
	case 'C':temp[0]='1';temp[1]='1';temp[2]='0';temp[3]='0';break;
	case 'D':temp[0]='1';temp[1]='1';temp[2]='0';temp[3]='1';break;
	case 'E':temp[0]='1';temp[1]='1';temp[2]='1';temp[3]='0';break;
	case 'F':temp[0]='1';temp[1]='1';temp[2]='1';temp[3]='1';break;
	default:cout<<"";break;
	}
	temp[4]='\0';
	if(pos==0 || pos==1 || pos==2 || pos==3)
	{
		X[pos*4+0]=temp[0];
		X[pos*4+1]=temp[1];
		X[pos*4+2]=temp[2];
		X[pos*4+3]=temp[3];
		X[pos*4+4]='\0';
	}
	if(pos==4)
	{
		X[16]=temp[0];
		X[17]=temp[1];
		X[18]=temp[2];
		X[19]='\0';
		Y[0]=temp[3];
		Y[1]='\0';
	}
	if(pos==5 || pos==6 || pos==7 || pos==8 || pos==9)
	{
		Y[pos*4-19]=temp[0];
		Y[pos*4-18]=temp[1];
		Y[pos*4-17]=temp[2];
		Y[pos*4-16]=temp[3];
		Y[pos*4-15]='\0';
	}
	if(pos==10)
	{
		Y[21]=temp[0];
		Y[22]='\0';
		Z[0]=temp[1];
		Z[1]=temp[2];
		Z[2]=temp[3];
		Z[3]='\0';
	}
	if(pos==11 || pos==12 || pos==13 || pos==14 || pos==15)
	{
		Z[pos*4-41]=temp[0];
		Z[pos*4-40]=temp[1];
		Z[pos*4-39]=temp[2];
		Z[pos*4-38]=temp[3];
		Z[pos*4-37]='\0';
	}
}

void divide(void)     //HEX to Binary
{
	char *tmp;
	tmp=new char[7*strlen(string)];
	X=new char[20];
	Y=new char[23];
	Z=new char[24];
	strcpy(X,"");//Empty all 3 registers initially so as to remove garbage
	strcpy(Y,"");
	strcpy(Z,"");
	for(int i=0;key[i]!='\0';i++)
	{
		convert(key[i],i); //Converting whole key bit-wise
	}

	int x;
	cout<<"\nThe actual binary string is: "<<endl;//Display binary string
	for(i=0;string[i]!='\0';i++)
	{
		x=(int)(string[i]);
		itoa(x,tmp,2);
		cout<<tmp<<" ";
	}
}

char maj(char x, char y, char z) //Calculate majority of 3 bits
{
	int m;
	if(x==y)
		return x;
	else if(x==z)
		return x;
	else
		return z;
}

void shift(int n,int t) //Shifting the bits of registers
{
	cipherbit=new char[4];
	if(n==1)
	{
		for(int i=18;i>=0;i--) //Shifting X if X steps
		{
			X[i+1]=X[i];
		}
	X[0]=t;
	}

	if(n==2)
	{
		for(int i=21;i>=0;i--) //Shifting Y if Y steps
		{
			Y[i+1]=Y[i];
		}
	Y[0]=t;
	}

	if(n==3)
	{
		for(int i=22;i>=0;i--) //Shifting Z if Z steps
		{
			Z[i+1]=Z[i];
		}
	Z[0]=t;
	}
}

void stepx(void)   //Function for stepping X
{
	int t;
	char *temp1,*temp2,*temp3,*temp4;
	temp1=new char[2];temp2=new char[2];temp3=new char[2];temp4=new char[2];
	temp1[0]=X[13];temp1[1]='\0';
	temp2[0]=X[16];temp2[1]='\0';
	temp3[0]=X[17];temp3[1]='\0';
	temp4[0]=X[18];temp4[1]='\0';
	//XOR bits 13,16,17,18 of register X
	t=((atoi(temp1)^atoi(temp2))^atoi(temp3))^atoi(temp4);
	shift(1,t);
	cipherbit[0]=X[18];//Obtain the bit required from X to create cipher
}

void stepy(void)   //Function for stepping Y
{
	int t;
	char *temp1,*temp2;
	temp1=new char[2];temp2=new char[2];
	temp1[0]=Y[20];temp1[1]='\0';
	temp2[0]=Y[21];temp2[1]='\0';
	//XOR bits 20,21 of register Y
	t=atoi(temp1)^atoi(temp2);
	shift(2,t);
	cipherbit[1]=Y[21]; //Obtain the bit required from Y to create cipher
}

void stepz(void)   //Function for stepping Y
{
	int t;
	char *temp1,*temp2,*temp3,*temp4;
	temp1=new char[2];temp2=new char[2];temp3=new char[2];temp4=new char[2];
	temp1[0]=X[7];temp1[1]='\0';
	temp2[0]=X[20];temp2[1]='\0';
	temp3[0]=X[21];temp3[1]='\0';
	temp4[0]=X[22];temp4[1]='\0';
	//XOR bits 7,20,21,22 of register Y
	t=((atoi(temp1)^atoi(temp2))^atoi(temp3))^atoi(temp4);
	shift(3,t);
	cipherbit[2]=Z[22]; //Obtain the bit required from Y to create cipher
}

void implement(void)
{
	char M;
	//M=new char[1];
	//int m;
	M=maj(X[8],Y[10],Z[10]); //Getting majority
	if(X[8]==M)
		stepx();
	else
		cipherbit[0]=X[18];
	if(Y[10]==M)
		stepy();
	else
		cipherbit[1]=Y[21];
	if(Z[10]==M)
		stepz();
	else
		cipherbit[2]=Z[22];
	char *temp1,*temp2,*temp3;
	temp1=new char[2];
	temp2=new char[2];
	temp3=new char[2];
	temp1[0]=cipherbit[0];temp1[1]='\0';
	temp2[0]=cipherbit[1];temp2[1]='\0';
	temp3[0]=cipherbit[2];temp3[1]='\0';
	int CIPHER;
	//Create final CIPHER bit using the obtained cipherbits from X,Y,Z
	CIPHER=(atoi(temp1)^atoi(temp2))^atoi(temp3);
	char *temp;
	itoa(CIPHER,temp,10);
	strcat(ans,temp); //Concatanating the obtained bits to ans
}

void main()
{
	clrscr();
	input();         //Get input
	divide();        //Convert HEX key to Binary
	ans=new char[7*strlen(string)];
	for(int i=0;i<7*strlen(string);i++)
	implement(); //Recieve CIPHER bits for binary string length times
	cout<<"\nThe encrypted binary string is: "<<endl;
	cout<<ans;  //The encrypted string obtained after
		    //implementing the algorithm for each bit
	getch();
}