#include <iostream>
using namespace std;

const int n=10;

string landmarks[n]={"college", "Gate", "Canteen", "Library", "Reading hall", "Office", "Parking", "Basement", "Student section", "Terrace" };

class queue
{
	int arr[n];
	int front,rear;
	public:
		queue()	{	front=rear=-1;	}
		
		bool isFull() { return rear==n-1;	}
		bool isEmpty() { return front==-1;	}
		
		void enqueue(int x)
		{
			if (isFull()) 
			{
				cout<<"Queue is full!";
				return;
			}
			if (isEmpty()) 
				front=rear=0;
			else
				rear++;
			arr[rear]=x;
		}
		
		int dequeue()
		{
			if (isEmpty()){
				cout<<"Queue is empty!";
				return -1;
			}
			int temp;
			temp=arr[front];
			if (front==rear)
				front=rear=-1;
			else
				front++;
			
			return temp;
		}
};

class graph
{
	int adjlist[n][n];
	int adjmatrix[n][n];
	int visited[n];
	int size[n];
	
	public:
		graph()
		{
			for (int i=0; i<n; i++)
			{
				visited[i]=0;
				size[i]=0;
				for (int j=0; j<n; j++)
				{
					adjlist[i][j]=-1;
					adjmatrix[i][j]=0;
				}
			}
		}
		
		void readgraph()
		{
			int e,v;
			cout<<"Enter number of landmarks: ";
			cin>>v;
			cout<<"Enter number of connections: ";
			cin>>e;
			cout<<"Landmark indices:\n";
			for (int i=0; i<v; i++)
			{
				cout<<i<<" : "<<landmarks[i]<<endl;
			}
			
			int x,y;
			for (int i=0; i<e; i++)
			{
				cout<<"Enter the connected landmarks (x y): ";
				cin>>x>>y;
				adjmatrix[x][y]=adjmatrix[y][x]=1;
				adjlist[x][size[x]++]=y;
				adjlist[y][size[y]++]=x;
			}
		}
		
		void dfs(int x)
		{
			visited[x]=1;
			cout<<landmarks[x]<<" ";
			for (int i=0; i<n; i++)
			{
				if (adjmatrix[x][i]==1 && visited[i]==0)
				{
					dfs(i);
				}
			}
		}
		
		void bfs(int start)
		{
			for (int i=0; i<n; i++)
			{
				visited[i]=0;
			}
			queue q;
			q.enqueue(start);
			visited[start]=1;
			while(!q.isEmpty())
			{
				int current=q.dequeue();
				cout<<landmarks[current]<<" ";
				
				for (int i=0; i<n; i++)
				{
					int neighbor=adjlist[current][i];
					if (!visited[neighbor])
					{
						visited[neighbor]=1;
						q.enqueue(neighbor);
					}
				}
			}
			
		}
	
};

int main()
{
	graph g;
	int z;
	g.readgraph();
	cout<<"\nEnter where to start dfs from: ";
	cin>>z;
	g.dfs(z);
	cout<<"\nEnter where to start bfs from: ";
	cin>>z;
	g.bfs(z);
	return 0;
}
