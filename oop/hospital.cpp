#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<fstream>
#define underline "\033[4m"
#define uoff "\033[0m"
#include <unistd.h>
 using namespace std;

 
class patient 
{
	public :
				fstream file,file1,file2,file3; 
				static int z, p,q,m,n,jo,k,as,a;
				string  fe,can,treat,jt,aa;
				static char ch[500][10];
			  static    char fn[18],gen,mc[500],bp[4],bg[4];
			  			 	
			 	
			 	
			 	char fever[500][10],cancer[500][10],joint[700][10],asthma[400][10];
			static	long int cell,age;
			int i,j,l,count,num;
														
public : 	
	
	

	void get();
	void slice();
	void simple();
};
int patient :: z=0;
int patient :: p=0;
int patient :: jo=0;
int patient :: k=0;
int patient :: a=0;
int patient :: as=0;
int patient :: q=0;
int patient :: m=0;
int patient :: n=0;
long int patient :: cell=0;
long int patient :: age=0;
char patient :: ch[500][10];
char patient :: fn[18];
char patient :: gen;
char patient :: mc[500];
char patient :: bp[4];
char patient :: bg[4];

void patient :: get()
{
	cout<<"\n \t\t\t\t\t\t   PATIENT DETAILS  ";
	cout<<"\nFull Name : \n";
	cin.get(fn,18);
	
	
	cin.ignore();
ge:	cout<<"\nGender(M/F) :\n";
	cin>>gen;
	gen=toupper(gen);
	
if(gen !='M' && gen!='F')
{
cout<<"Make a valid choice M:male and F : female ";
goto ge;
}
 
	cel :cout<<"\nCell :\n";
	cin>>cell;
	num=cell/1000000000;
	if(!(num>0 && num<=9 ))
	{
	cout<<"please_enter_valid_10_digits";
	goto cel;
	
	}


	ag:cout<<"\nAge : \n";
	cin>>age;
	if(!(age>0 && age<120))
	{
	cout<<"Please enter appropriate age ";
	goto ag;
	
	}
	cin.ignore();
	cout<<"\nBlood pressure(Low/High):\n";
	cin.get(bp,5);
	cin.ignore();
	cout<<"\nBlood group :\n ";
	cin>>bg;
	cin.ignore();
	cout<<"\nMedical conditions(Enter many symptoms to find your diseases accurately )\n ";
	cout<<"\n Note:End symptoms with a full stop \n\n";
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
file.close();



while(file1.good())
{
file1.open("cancer.txt",ios::in);
getline(file1,can);
}


for(i=0;can[i]!='.';i++)
{
if(can[i]==' ')
{
m++;
n=0;
continue;
}
cancer[m][n]=can[i];
n++;

} 
file1.close();
while(file2.good())
{
file2.open("joint.txt",ios::in);
getline(file2,jt);
}
for(i=0;jt[i]!='.';i++)
{
if(jt[i]==' ')
{
jo++;
k=0;
continue;
}
joint[jo][k]=jt[i];
k++;

}

 file2.close();//cout<<cancer[1];
while(file3.good())
{
file3.open("asthma.txt",ios::in);
getline(file3,aa);
}
for(i=0;aa[i]!='.';i++)
{
if(aa[i]==' ')
{
a++;
as=0;
continue;
}
asthma[a][as]=aa[i];
as++;

} 
file3.close();
}
class pro: public patient 
{
public : static int fc,cc,jc,ast;
void approx()
{
simple();
for(i=0;i<=z;i++)
{
for(j=0;j<=p;j++)
{
if((strcmp(fever[j],ch[i])==0))
{
fc++;
break;
}
}
}
for(i=0;i<=z;i++)
{
for(j=0;j<=m;j++)
{
if(strcmp(cancer[j],ch[i])==0)
{
cc++;
break;
}
}
}
for(i=0;i<=z;i++)
{
for(j=0;j<=jo;j++)
{
if(strcmp(joint[j],ch[i])==0)
{
jc++;
break;
}
}
}
for(i=0;i<=z;i++)
{
for(j=0;j<=a;j++)
{
if(strcmp(asthma[j],ch[i])==0)
{
cout<<asthma[j];

ast++;
break;
}
}
}
}
};
int pro::fc=0;
int pro::cc=0;
int pro::jc=0;
int pro::ast=0;
class report : public pro
{
public:
void display();
};
void report :: display()
{
cout<<underline<<"\n\t\t\t\t\t\t\t REPORT "<<"\n\n PERSONAL DETAILS :"<<uoff;
cout<<"\n\n\tNAME : "<<fn<<"\t\t\tGENDER : "<<gen<<"\n\n\tAGE :"<<age<<"\t\t\t\tMOBILE : "<<cell;
cout<<"\n\n\tBlood pressure :"<<bp<<"\t\t\tBlood group : "<<bg;
cout<<underline<<"\n\nMEDICAL EXAMINATIONS *	"<<uoff;
if(cc>fc && cc>jc && cc>ast)
{
cout<<"\n\n\n\tDisease : Cancer "<<"\n\n\tConsult : Dr.Gangadhar kumar.";
while(file1.good())
{
file1.open("ctreat.txt");
getline(file1,treat);
}
cout<<underline<<"\n\nTreament "<<uoff;
cout<<"\n\n"<<treat;
}
else if(fc>jc && fc>ast)
{
cout<<"\n\n\n\tDisease : Fever "<<"\n\n\tConsult : Dr.Gaveesh Patil.";
while(file1.good())
{

file1.open("ftreat.txt");
getline(file1,treat);
}
cout<<underline<<"\n\nTreament "<<uoff;
cout<<"\n\n"<<treat;
}
else if(jc> ast )
{
cout<<"\n\n\n\t Issue : Joint Pain "<<"\n\n\tConsult : Dr.Nagaraj sharma. ";
while(file1.good())
{

file1.open("jtreat.txt");
getline(file1,treat,':');
}

cout<<underline<<"\n\nTreament "<<uoff;
cout<<"\n\n"<<treat;
}
else if(ast>jc)
{
cout<<"\n\n\n\t Issue : Asthma "<<"\n\n\tConsult : Dr.Santosh modi.";
while(file1.good())
{

file1.open("atreat.txt");
getline(file1,treat,':');
}

cout<<underline<<"\n\nTreament "<<uoff;
cout<<"\n\n"<<treat;
}

else 
{
cout<<"Please enter correct details or more symptoms ";

}

cout<<"\n\n\t\t\t\t\t\t\t* Conditions determined on your symptoms \n\n ";

}
int main()
{
int choice;
char print;
patient *u,obj;
u=&obj;
report o;
pro ob;


while(1)
{
system("clear");
cout<<" \n \t\t\t\t\t\t  Welcome to Virtual Hospital \n\n";
cout<<" \n\n\t 1.Doctors\t\t\t\t 2.Treatments or speciality \n\n\t 3. Book an appointment(Conslutant)\t\t 4.Exit ";
cout<<"\n\n\tPlease eneter your choice to continue ";
cin>>choice;
cin.ignore();
switch(choice)
{
case 1 :cout<<"\n\n\n Doctors list : \n\n 1.Dr Santosh modi \n\t Pulmonologist- provides Asthma Treatment . \n\n 2.Nagaraj  sharma \n\t MBBS, MS - Orthopedics, MCh - Orthopedics.\n\n 3.Dr. Gaveesh patil \n\t pediatrician-provides Viral Fever Treatment \n\n 4.Dr.Gangadhar kumar \n\t oncologist - treats cancer .\n\n";
cout<<"Press any  key to continue ";
getchar();
break;
case 2 :cout<<underline<<"\nTreaments provided"<<uoff <<": \n\n 1.Asthma \n\n 2.Joint pain \n\n 3.Viral fever \n\n 4.Cancer \n\n"  ;
cout<<"Press any  key to continue ";
getchar();
break;
case 3 :
u->get();
u->simple();
ob.approx();
system("clear");
o.display();
cout<<"\n\n\t\t Do you want report  printout ?  Y/N ";
cin>>print;
if(print =='y' || print =='Y')
{
system("gnome-screenshot");
}

break;
case 4: cout<<"\n\n\n\t\t\t\tThank you to visit \n\n";
exit(0);
break;
default : cout<<"Invalid choice" ;
 
}
 
}

}

		 
