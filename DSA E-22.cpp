#include <iostream>
using namespace std;

class heap
{
	int marks[10];
	int n;
	int num;
	public:
		heap()
		{
			n = 0;
			marks[0] = 0;  // marks[0] stores the count
		}

		void insert(int marks[10], int x)
		{
			n = marks[0];
			marks[n + 1] = x;
			marks[0] = n + 1;
			upadjust_max(marks, n + 1);
		}

		void create() 
		{
			
			cout << "Enter number of students: ";
			cin >> num;

			cout << "Enter the marks:\n";
			for (int i = 0; i < num; i++) 
			{
				int val;
				cin >> val;
				insert(marks, val);  
			}

			cout << "Heap created successfully.\n";
		}

		void upadjust_max(int marks[], int i)
		{
			int temp;  
			while (i > 1 && marks[i] > marks[i / 2])
			{
				temp = marks[i];
				marks[i] = marks[i / 2];
				marks[i / 2] = temp;
				i = i / 2;
			}
		}
		
		void upadjust_min(int marks[], int i)
		{
			int temp;  
			while (i > 1 && marks[i] < marks[i / 2])
			{
				temp = marks[i];
				marks[i] = marks[i / 2];
				marks[i / 2] = temp;
				i = i / 2;
			}
		}

		void display()
		{
			cout << "Max Heap as array: ";
			for (int i = 1; i <= marks[0]; i++)
			{
				cout << marks[i] << " ";
			}
			cout << endl;
		}
		
		void menu()
		{
			int ch;
			do{
				cout<<"-----------------Student marks menu----------------- ";
				cout<<"\n1.Insert student marks \n2.Dsiplay marks \n3.Find maximum marks \n4.Find minimum marks \n5.Exit\n";
				cin>>ch;
				switch(ch)
				{
					case 1:
						create();
						break;
						
					case 2:
						display();
						break;
						
					case 3:
						cout<<"Maximum marks: "<<marks[1]<<endl;
						break;
						
					case 4:
						cout<<"Minimum marks: "<<cout<<marks[num-1]<<endl;
						break;
						
					case 5:
						cout<<"Exiting...";
						break;
						
					default:
						break;
				}
			} while( ch!=5);
		}
};

int main()
{
	heap h;
	h.menu();
	return 0;
}

