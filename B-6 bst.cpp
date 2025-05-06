#include <iostream>
#include <process.h>
#include <algorithm>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
		
		node(int val){
			data=val;
			left=right=NULL;
		}
};

class bst
{
	public:
		node* root;
		bst()
		{
			root=NULL;
		}
		
		node* insert(node* root, int val)
		{
			if (root==NULL)
			{
				return new node(val);
			}
			if (val > root->data)
			{
				root->right=insert(root->right, val);
			}
			if (val < root->data)
			{
				root->left=insert(root->left, val);
			}
			return root;
		}
		
		void create()
		{
			int n, val;
			cout<<"Enter how many nodes you want to enter: ";
			cin>>n;
			cout<<"Enter the data: ";
			for (int i=0; i<n; i++)
			{
				cin>>val;
				root=insert(root, val);
			}
		}
		
		void inorder(node *t)
		{
			if (t==NULL)
			{
				return;
			}
			inorder(t->left);
			cout<<t->data<<" ";
			inorder(t->right);
		}
		
		int height(node* t)
		{
			int hl,hr;
			if (t==NULL)
			{
				return -1;
			}
			hl = 1 + height(t->left);
			hr = 1 + height(t->right);
			
			return max(hl, hr);
		}
		
		node* min_data(node* t)
		{
			if (t==NULL)
			{
				return NULL;
			}
			while (t->left != NULL)
			{
				t = t->left;
			}
			
			return t;
		}
		
		node* search(node* t, int key)
		{
			if (t->data == key)
			{
				cout << "Value found! ";
				return t;
			}
			if (key > t->data )
				return search(t->right, key);
			else
				return search(t->left, key);	
		}
		
		void menu()
		{
			int ch,val;
			cout<< "***************** Binary Search Tree *****************";
			do{
				cout<<"\n\t Menu\n";
				cout<<"\n1.Create a bst \n2.Insert a new node \n3.Find number of nodes in the longest path from the root node \n4.Find the minimum data in bst \n";
				cout<<"5.Display in inorder\n6.Search for a node \n7.Exit \n";
				cin>>ch;
				
				switch(ch)
				{
					case 1:
						create();
						break;
						
					case 2:
						cout<<"Insert a value to be inserted: ";
						cin>>val;
						insert(root,val);
						break;
						
					case 3:
						cout<<"Number of nodes in the longest path from the root node: "<<height(root);
						break;
						
					case 4:
						cout<<"Minimum value in the tree: ";
						min_data(root);
						break;
						
					case 5:
						cout<<"Displaying data: ";
						inorder(root);
						break;
					
					case 6:
						cout<<"Enter value to be searched: ";
						cin>>val;
						search(root, val);
						break;
						
					case 7:
						cout<<"Exiting... ";
						break;
						
					default:
						exit(0);
				}
			}while(ch!=7);
		}
};

int main()
{
	bst b;
	b.menu();
	
	return 0;
	
}
