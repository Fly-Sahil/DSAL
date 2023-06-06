#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student
  {
	typedef struct stud
	{
		int roll;
		char name[10];
		char div;
		char add[10];
	}stud;
	stud rec;
	public:
	  void create();
	  void display();
	  int search();
	  void Delete();
  };
void student::create()
  {
	char ans;
	ofstream fout;
	fout.open("stud.dat",ios::out|ios::binary);
	do
	  {
		cout<<"\nEnter Roll No of Student    : ";
		cin>>rec.roll;
		cout<<"\nEnter a Name of Student     : ";
		cin>>rec.name;
		cout<<"\nEnter a Division of Student : ";
		cin>>rec.div;
		cout<<"\nEnter a Address of Student  : ";
		cin>>rec.add;
		fout.write((char *)&rec,sizeof(stud))<<flush;
		cout<<"\nDo You Want to Add More Records: ";
		cin>>ans;
	  }while(ans=='y'||ans=='Y');
	fout.close();
  }
void student::display()
  {
	ifstream fin;
	fin.open("stud.dat",ios::in|ios::binary);
	fin.seekg(0,ios::beg);
	cout<<"\nThe Content of File are:\n";
	cout<<"\n\tRoll\tName\tDiv\tAddress";
	while(fin.read((char *)&rec,sizeof(stud)))
	  {
		if(rec.roll!=-1)
       		  cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
	  }
	fin.close();
  }
int student::search()
  {
	int r,i=0;
	ifstream fin;
	fin.open("stud.dat",ios::in|ios::binary);
	fin.seekg(0,ios::beg);
	cout<<"\nEnter a Roll No: ";
	cin>>r;
	while(fin.read((char *)&rec,sizeof(stud)))
	  {
		if(rec.roll==r)
		  {
			cout<<"\nRecord Found...";
			cout<<"\n\tRoll\tName\tDiv\tAddress";
			cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
			return i;
		  }
		i++;
	  }
	fin.close();
	return 0;
  }
void student::Delete()
  {
	int pos;
	pos=search();
	fstream f;
	f.open("stud.dat",ios::in|ios::out|ios::binary);
	f.seekg(0,ios::beg);
	if(pos==0)
	  {
		cout<<"\nRecord Not Found";
		return;
	  }
	int offset=pos*sizeof(stud);
	f.seekp(offset);
	rec.roll=-1;
	strcpy(rec.name,"NULL");
	rec.div='N';
	strcpy(rec.add,"NULL");
	f.write((char *)&rec,sizeof(stud));
	f.seekg(0);
	f.close();
	cout<<"\nRecord Deleted";
  }
	
int main()
  {
	student obj;
	int ch,key;
	char ans;
	do
	  {
		cout<<"\n\t***** Student Information *****";
		cout<<"\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
		cout<<"\n\t..... Enter Your Choice: ";
		cin>>ch;
		switch(ch)
		  {
			case 1: obj.create();
				break;
			case 2:	obj.display();
				break;
			case 3: obj.Delete();
				break;
			case 4: key=obj.search();
				if(key==0)
				  cout<<"\n\tRecord Not Found...\n";
				break;
			case 5:
				break;
		  }
		cout<<"\n..... Do You Want to Continue in Main Menu: ";
		cin>>ans;
	  }while(ans=='y'||ans=='Y');
return 1;
  }

/*
        ***** Student Information *****
        1. Create
        2. Display
        3. Delete
        4. Search
        5. Exit
        ..... Enter Your Choice: 1

Enter Roll No of Student    : 77

Enter a Name of Student     : Sahil

Enter a Division of Student : A

Enter a Address of Student  : shreeramSociety

Do You Want to Add More Records: y

Enter Roll No of Student    : 55

Enter a Name of Student     : Rohan

Enter a Division of Student : B

Enter a Address of Student  : WarjeColony

Do You Want to Add More Records: y

Enter Roll No of Student    : 23

Enter a Name of Student     : Akshay

Enter a Division of Student : B

Enter a Address of Student  : Golbuilding

Do You Want to Add More Records: y

Enter Roll No of Student    : 66

Enter a Name of Student     : Vinay

Enter a Division of Student : C

Enter a Address of Student  : paladiumhomes

Do You Want to Add More Records: n

..... Do You Want to Continue in Main Menu: y

        ***** Student Information *****
        1. Create
        2. Display
        3. Delete
        4. Search
        5. Exit
        ..... Enter Your Choice: 2

The Content of File are:

        Roll    Name    Div     Address
        77      Sahil   A       shreeramSocie
        55      Rohan   B       WarjeColony
        23      Akshay  B       Golbuilding
        66      Vinay   C       paladiumhomes
..... Do You Want to Continue in Main Menu: y

        ***** Student Information *****
        1. Create
        2. Display
        3. Delete
        4. Search
        5. Exit
        ..... Enter Your Choice: 3

Enter a Roll No: 66

Record Found...
        Roll    Name    Div     Address
        66      Vinay   C       paladiumhomes
Record Deleted
..... Do You Want to Continue in Main Menu: y

        ***** Student Information *****
        1. Create
        2. Display
        3. Delete
        4. Search
        5. Exit
        ..... Enter Your Choice: 4

Enter a Roll No: 55

Record Found...
        Roll    Name    Div     Address
        55      Rohan   B       WarjeColony*/
