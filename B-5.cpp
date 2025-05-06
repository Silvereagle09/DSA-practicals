#include <iostream>
using namespace std;

class node{
	public:
		string data;
		node* left;
		node* right;
	
	node(string val)
	{
		data=val;
		left=right=NULL;
	}
};

class tree
{
	public:
		node* root;
		tree()
		{
			root=NULL;
		}
		
		node* create(string level)
		{
			string value;
			cout<<"Enter "<<level<<"(enter -1 for no "<<level <<" ): ";
			getline(cin,value);
			
			if(value=="-1")
			{
				return NULL;
			}
			
			node* newnode=new node(value);
			
			cout<<"Adding left child (Chapters) to "<<newnode->data<<endl;
			newnide->left=create("child of " + newnode->data);
		}
		
};

int main()
{
	return 0;
}
