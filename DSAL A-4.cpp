#include <iostream>
#include <process.h>
using namespace std;

class set
{
    public:
        int arr[10];
        int size;
    
    public:
        
        set()
        {
            size=0;
            for (int i=0;i<10;i++)
            {
                arr[i]=0;
            }
        }
        
        void add(int key)
        {
            for (int i=0;i<size;i++)
            {
                if (arr[i]==key)
                {
                    cout<<"Element already present in the set "<<endl;
                    return;
                }
            }
            if (size<10)
            {
                arr[size++]=key;
                cout<<"Element added"<<endl;
            }
            else
            {
                cout<<"set is full"<<endl;
            }    
        }
        
        void remove(int key)
        {
            for (int i=0;i<size;i++)
            {
                if (arr[i]==key)
                {
                    for (int j=i;j<size-1;j++)
                    {
                        arr[j]=arr[j+1];
                    }
                    size--;
                    cout<<"Element removed "<<endl;
                    return;
                }
            }            
            cout<<"Element not found!"<<endl;
        }
        
        void display()
        {
            if (size==0)
            {
                cout<<"Set is empty!"<<endl;
                return;
            }    
            cout<<"Elements: ";
            for (int i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        
        void contain(int key)
        {
            for (int i=0;i<size;i++)
            {
                if (arr[i]==key)
                {
                    cout<<"Element found"<<endl;
                    return;
                }
            }
            cout<<"Element not found!!"<<endl;
        }
        


};

int main()
{
    set s;
    int ch;
    int data;
    do{
    	cout<<"**************Menu**************"<<endl;
    	cout<<"1.Add an element \n2.Delete an element \n3.Display \n4.Is the element in collection? \n5.Find union of two sets \n6.Exit \n";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1:
    			cout<<"Enter element to be added: "<<endl;
    			cin>>data;
    			s.add(data);
    			break;
    		case 2:
    			cout<<"Enter element to be deleted: "<<endl;
    			cin>>data;
    			s.remove(data);
    			break;
    		case 3:
    			s.display();
    			break;
    		case 4:
    			cout<<"Enter the element you want to check: ";
    			cin>>data;
    			s.contain(data);
    			break;
    		case 6:
    			cout<<"Exiting...";
    			exit(0);
    		default:
    			cout<<"Invalid choice!!"<<endl;
		}
    
	} while(ch!=6);
    return 0;
}

