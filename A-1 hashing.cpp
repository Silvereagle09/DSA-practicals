#include <iostream>
using namespace std;

//Handling collision using linear probing and separate chaining
struct telephone
{
	int no;//for linear probing
	string name;
	bool isOccupied;
	telephone()
	{
		isOccupied=false;
	}
};

class node
{
	public://for separate chaining
		int no;
		string name;
		node* next;
		node()
		{
			next=NULL;
		}
};

class hashfunction
{
	public:
		telephone hashtable[10];
		node* hashtable1[10];
		
		hashfunction()
		{
			for (int i=0; i<10; i++)
			{
				hashtable[i].isOccupied=false;
				hashtable1[i]=NULL;
			}
		}
		
		void insert_sc(int number, string data)
		{
			node* p=new node;
			p->name=data;
			p->no=number;
			int loc=number%10;
			if (hashtable1[loc]==NULL)
			{
				hashtable1[loc]=p;
			}
			else
			{
				node* q=new node;
				q=hashtable1[loc];
				while(q!=NULL)
				{
					q=q->next;
				}
				q->next=p;
			}
			cout<<p->name<<" has been inserted."<<endl;
		}
		
		void insert_lp(int key, string data)
		{
			int loc=key%10;
			if (!hashtable[loc].isOccupied)
			{
				hashtable[loc].name=data;
				hashtable[loc].no=key;
				hashtable[loc].isOccupied=true;
			}
			loc=(loc+1)%10;
			cout<<key<<" has been inserted";
		}
		
		void search_sc(int key)
		{
			node* p=new node;
			int loc=key%10;
			hashtable1[loc]=p;
			if (p==NULL)
			{
				cout<<"Record not found!\n";
			}
			else
			{
				while(p!=NULL)
				{
					if (p->no==key)
					{
						cout<<"Record found!\n"<<"Name: "<<p->name<<"\tTelephone number: "<<p->no<<endl;
					}
					p=p->next;
				}
			}
		}
		
		void search_lp(int key)
		{
			int loc=key%10;
			if (!hashtable[loc].isOccupied)
			{
				cout<<"Record not found!";
			}
			else
			{
				for (int i=0; i<10; i++)
				{
					if (hashtable[loc].no==key)
					{
						cout<<"Record found\n"<<"Name: "<<hashtable[loc].name<<"\tTelephone number: "<<key;
						break;
					}
					loc=(loc+1)%10;
				}
			}			
		}
		
		void display_sc()
		{
			node* p=new node;
			for (int i=0; i<10; i++)
			{
				p=hashtable1[i];
				if (p==NULL)
				{
					cout<<"----------------------------------"<<endl;
				}
				else
				{
					while(p!=NULL)
					{
						cout<<"Name: "<<p->name<<"\tTelephone number: "<<p->no<<endl;
						p=p->next;
					}
				}
			}
		}
		
		void display_lp()
		{
			for (int i=0; i<10; i++)
			{
				if (hashtable[i].isOccupied)
				{
					cout << "Location " << i << ", Name: " << hashtable[i].name << ", Telephone number: " << hashtable[i].no << endl;
            	} 
				else 
				{
                cout << "----------------------------------" << endl;
            	}
			}
		}
		
		void menu()
		{
			int r;
			do{
			
				cout<<"\n\t\tMenu\n";
				cout<<"Telephone Directory\nHow you want to enter the records?\n1.Separate Chaining \n2.Linear Probing\n3.Exit\n";
				cin>>r;
				int n1;
				string n2;
				switch(r)
				{
					case 1:
						int ch;
						cout<<"\nSelect further operation: \n1.Insert \n2.Search \n3.Display \n4.Exit \n";
						cin>>ch;
						switch(ch)
						{
							case 1:
								cout<<"Enter a number and name associated with it: ";
								cin>>n1>>n2;
								insert_sc(n1, n2);
								break;
							case 2:
								cout<<"Enter a number to be searched: ";
								cin>>n1;
								search_sc(n1);
								break;
							case 3:
								cout<<"Displaying records: \n";
								display_sc();
								break;
							case 4:
								cout<<"Exiting...";
								break;
							default:
								cout<<"Invalid choice!";
								exit(0);
						}
						break;
						
					case 2:
						int choice;
						cout<<"\nSelect further operation: \n1.Insert \n2.Search \n3.Display \n4.Exit \n";
						cin>>choice;
						switch(choice)
						{
							case 1:
								cout<<"Enter a number and name associated with it: ";
								cin>>n1>>n2;
								insert_lp(n1, n2);
								break;
							case 2:
								cout<<"Enter a number to be searched: ";
								cin>>n1;
								search_lp(n1);
								break;
							case 3:
								cout<<"Displaying records: \n";
								display_lp();
								break;
							case 4:
								cout<<"Exiting...";
								break;
							default:
								cout<<"Invalid choice!";
								exit(0);
						}
						break;
						
					case 3:
						exit(0);
				}
			}while(r!=3);
		}
};

int main()
{
	hashfunction h;
	h.menu();
	return 0;
}








