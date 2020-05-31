#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<fstream>

 using namespace std;

 
class patient 
{
	protected  :
fstream file; 
static int z, p,q;
string  fe;
static char ch[10][10];
	char fn[18],gen,mc[110];
	char fever[100][20];
	
		int cell,i,j,l,count;
		
public : 	
	
	

	void get();
	void slice();
	void simple();
	

	
	
};
int patient :: z=0;
int patient :: p=0;
int patient :: q=0;
char patient :: ch[10][10];

void patient :: get()
{
	cout<<"\n \t\t\t\t\t\t   PATIENT DETAILS  ";
	cout<<"\n Full name\n";
	cin.get(fn,18);
	cin.ignore();
	cout<<"\nGender(M/F)\n";
	cin>>gen;
	cout<<"\nCell\n";
	cin>>cell;
	cin.ignore();
	cout<<"\nMedical conditions(Ex: cold,fever.)\n ";
	cin.get(mc,100);
	slice();

}

void patient::slice()
{

for(i=0;mc[i]!='.';i++)
{
if(mc[i]==',')
{
z++;
l=0;
continue;
}
if(mc[i]==' ')
{


z++;
l=0;
continue;
}
ch[z][l]=mc[i];
l++;

}



}
void patient:: simple()
{

while(file.good())
{
file.open("fever.txt",ios::in);
getline(file,fe);
}
for(i=0;fe[i]!='.';i++)
{

if(fe[i]==' ')
{
p++;
q=0;
continue;
}
fever[p][q]=fe[i];
q++;

} 

}

class pro: public patient 
{
public :static int c,n;
void treat()
{
count=0;

c=0;
n=0;
simple();

for(i=0;i<=z;i++)
{
for(j=0;j<=p;j++)
{



if(strcmp(fever[j],ch[i])==0)
{
cout<<fever[j];
count++;
break;
}
}
}
cout<<count;

}
};
int pro::c=0;
int pro::n=0;
class sele : public pro
{
int max ;
public:
 sele()
{
max=n;
if(c>max)
{
cout<<"chiken pox ";
}


else
{
cout<<"fevrer";
}
}
};

int main()
{
patient obj;
pro ob;
system("clear");
cout<<" \n \t\t\t\t\t\t  Welcome to Virtual Hospital \n\n";
obj.get();
ob.treat();
sele o;


//obj.simple();

}



		 
