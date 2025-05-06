#include <iostream>
#include<process.h>
using namespace std;

//bst
class node
{
	public:
		string word,meaning;
		node* left;
		node* right;
		node(string key, string mean)
		{
			word=key;
			meaning=mean;
			left=right=NULL;
		}
};

class dictionary
{
	public:
		node* root;
		
		dictionary()
		{
			root=NULL;
		}
		
		void create()
		{
			char ch='y';
			string w,m;
			while(ch=='Y' || ch=='y')
			{
				cout<<"Enter a word: ";
				cin>>w;
				cout<<"Enter it's meaning: ";
				cin.ignore();
				getline(cin, m);
				
				root=insert(root, w, m);
				
				cout<<"\nDo you want to enter more words?(y or n): ";
				cin>>ch;
			}
		}
		
		node* insert(node* root, string key, string mean)
		{
			if (root==NULL)
			{
				return new node(key, mean);
			}
			
			if(key<root->word)
			{
				root->left=insert(root->left, key, mean);
			}
			else if(key>root->word)
			{
				root->right=insert(root->right, key, mean);
			}
			
			return root;
		}
		
		void search(string key)
		{
			node* temp=root;
			int comparisons=0;
			while(temp!=NULL)
			{
				comparisons++;
				if (key==temp->word)
				{
					cout << "Word found: " << temp->word << " --> " << temp->meaning << endl;
	                cout << "Number of comparisons: " << comparisons << endl;
	                return;
	            }
	            
	            if(key<temp->word)
	            	temp=temp->left;
	            else if( key>temp->word)
	            	temp=temp->right;
	            	
			}
			cout<<"Word not word!";
			cout<<"Number of comparisons: "<< comparisons << endl;
		}
		
		void update(string key)
		{
			node* temp=root;
			
			while(temp!=NULL)
			{
				if (key==temp->word)
				{
					cout<<"Enter the updated meaning: ";
					cin>>temp->meaning;
					cout<<"Meaning of the word has been updated!";
					return;
				}
				
				if(key<temp->word)
					temp=temp->left;
				else if(key>temp->word)
					temp=temp->right;
			}
			cout<<"Word not found!";
		}
	
		void inorder(node* root)
		{
			//ascending order
			if (root==NULL)
				return;
			inorder(root->left);
			cout<<root->word<<" : "<<root->meaning<<endl;
			inorder(root->right);
		}
		
		void reverse_inorder(node* root)
		{
			//descending order
			if (root==NULL)
				return;
			reverse_inorder(root->right);
			cout<<root->word<<" : "<<root->meaning<<endl;
			reverse_inorder(root->left);
		}
		
		node* find_min(node* root)
		{
			while(root!=NULL)
			{
				root=root->left;
			}
			return root;
		}
		
		node* del(node* root, string keyword)
		{
			if (root==NULL)
				return NULL;
			
			if (keyword<root->word)
				root->left=del(root->left, keyword);
			else if(keyword>root->word)
				root->right=del(root->right, keyword);
			else
			{
				if (root->left==NULL)
				{
					node* temp=root->right;
					delete root;
					return temp;
				}
				else if (root->right==NULL)
				{
					node* temp=root->left;
					delete root;
					return temp;
				}
				
				//having 2 children
				node* temp=find_min(root->right);
				root->word=temp->word;
				root->meaning=temp->meaning;
				root->right=del(root->right, temp->word);
				
				return root;
			}
			
		}
		
		void menu()
		{
			int a;
			string data;
			do 
			{
				cout<<"\n\t Dictionary \n";
				cout<<"1.Insert a word \n2.Search \n3.Update \n4.Display in ascending order \n5.Display in descending order \n6.Delete \n7.Exit \n";
				cin>>a;
				switch(a)
				{
					case 1:
						create();
						break;
					case 2:
						cout<<"Enter word to be searched: ";
						cin.ignore();
						getline(cin,data);
						search(data);
						break;
					case 3:
						cout<<"Enter word whose meaning is to be updated: ";
						cin.ignore();
						getline(cin,data);
						update(data);
						break;
					case 4:
						inorder(root);
						break;
					case 5:
						reverse_inorder(root);
						break;
					case 6:
						cout<<"Enter a word to be deleted: ";
						cin>>data;
						del(root, data);
						break;
					case 7:
						cout<<"Exiting the program...";
						exit(0);
					default:
						cout<<"Invalid choice!!";
						exit(0);
				}	
			}while(a!=7);
		}
};

int main()
{
	dictionary d;
	d.menu();
	return 0;
}
