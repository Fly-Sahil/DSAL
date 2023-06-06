#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    int count;
    char name[20];
    struct node *child[20];
}*root;

class Book
{
    public:

        void create();
        void display(node *r1);

        Book()
        {
            root=NULL;
        }
};

void Book::create() {
    int i, j, k;
    int tchapter, tsection, tsubsection;

    root = new node();

    cout << "\nEnter Name of the Book: " << endl;
    cin >> root->name;
    cout << "\nEnter number of Chapters in Book: " << root->name << endl;
    cin >> tchapter;
    root->count = tchapter;

    for (i = 0; i < tchapter; i++)
    {
        root->child[i] = new node();

        cout << "\nEnter Name of Chapter " << i + 1 << " in Book " << root->name << endl;
        cin >> root->child[i]->name;
        cout << "\nEnter Number of Sections in Chapter: " << root->child[i]->name << endl;
        cin >> tsection;
        root->child[i]->count = tsection;

        for (j = 0; j < tsection; j++)
        {
            root->child[i]->child[j] = new node();

            cout << "\nEnter Name of Section " << j + 1 << "in Chapter: " << root->child[i]->name << endl;
            cin >> root->child[i]->child[j]->name;
            cout << "\nEnter Number of Subsection in Section: " << root->child[i]->child[j]->name<<endl;
            cin >> tsubsection;
            root->child[i]->child[j]->count = tsubsection;

            for (k = 0; k < tsubsection; k++)
            {
                root->child[i]->child[j]->child[k]=new node();

                cout << "\nEnter Name of Subsection " << k + 1 << " in Section: " << root->child[i]->child[j]->name<< endl;
                cin >> root->child[i]->child[j]->child[k]->name;
            }
        }
    }
}
void Book::display(node *root)
{
    if (root == NULL) {
        return;
    }

    cout << "---------------" << endl;
    cout << "Book Tree" << endl;
    cout << "---------------" << endl;
    cout << "Book Title: " << root->name << endl;

    int tchapter = root->count;
    for (int i = 0; i < tchapter; i++)
    {
        cout << "\nChapter " << i+1 << ": " << root->child[i]->name << endl;
        int tsection = root->child[i]->count;

        for (int j = 0; j < tsection; j++)
        {
            cout << "\tSection " << j+1 << ": " << root->child[i]->child[j]->name << endl;
            int tsubsection = root->child[i]->child[j]->count;

            for (int k = 0; k < tsubsection; k++)
            {
                cout << "\t\tSubsection " << k+1 << ": " << root->child[i]->child[j]->child[k]->name << endl;
            }
        }
    }
}




int main()
{
    int a,choice;
    Book book;
    a=0;
    while(a==0)
    {
        cout<<"Welcome to Tree";
        cout<<"\n1.Create \n2.Display \n3.Exit\n";
        cin>>choice;

        switch (choice)
        {
            case 1:
                book.create();
                break;
            case 2:
                book.display(root);
                break;
            case 3:
                a=1;
        }
    }
}  

/*
Welcome to Tree
1.Create
2.Display
3.Exit
1

Enter Name of the Book:
ToughTimes

Enter number of Chapters in Book: ToughTimes
2

Enter Name of Chapter 1 in Book ToughTimes
Beginning

Enter Number of Sections in Chapter: Beginning
2

Enter Name of Section 1in Chapter: Beginning
firsthalf

Enter Number of Subsection in Section: firsthalf
2

Enter Name of Subsection 1 in Section: firsthalf
subsec1

Enter Name of Subsection 2 in Section: firsthalf
subsec2

Enter Name of Section 2in Chapter: Beginning
secondhalf

Enter Number of Subsection in Section: secondhalf
2

Enter Name of Subsection 1 in Section: secondhalf
subsec1

Enter Name of Subsection 2 in Section: secondhalf
subsec2

Enter Name of Chapter 2 in Book ToughTimes
Ending

Enter Number of Sections in Chapter: Ending
2

Enter Name of Section 1in Chapter: Ending
Itsstarted

Enter Number of Subsection in Section: Itsstarted
2

Enter Name of Subsection 1 in Section: Itsstarted
subsec1

Enter Name of Subsection 2 in Section: Itsstarted
subsec2

Enter Name of Section 2in Chapter: Ending
itsending

Enter Number of Subsection in Section: itsending
2

Enter Name of Subsection 1 in Section: itsending
subsec1

Enter Name of Subsection 2 in Section: itsending
subsec2
Welcome to Tree
1.Create
2.Display
3.Exit
2
---------------
Book Tree
---------------
Book Title: ToughTimes

Chapter 1: Beginning
        Section 1: firsthalf
                Subsection 1: subsec1
                Subsection 2: subsec2
        Section 2: secondhalf
                Subsection 1: subsec1
                Subsection 2: subsec2

Chapter 2: Ending
        Section 1: Itsstarted
                Subsection 1: subsec1
                Subsection 2: subsec2
        Section 2: itsending
                Subsection 1: subsec1
                Subsection 2: subsec2 */
