//C-15
#include <iostream>
using namespace std;

class graph
{
	string data;
	int cost;
	int mat[5][5];
	int visited[5];
	int dist[5];
	int b[5][5];
	int from[5];
	
	public:
		graph()
		{
			for (int i=0; i<5; i++)
			{
				for (int j=0; j<5; j++)
				{
					mat[i][j]=100;
					mat[j][i]=100; //initialize the matrix
					b[i][j]=0;
				}
			}
		}
		
		void readgraph()
		{
			int x,y,n,cost;
			cout<<"How many connected edges are there? ";
			cin>>n;
			for (int i=0; i<n; i++)
			{
				cout<<"Enter the position of connected edges: ";
				cin>>x>>y;
				cout<<"Enter the cost of entered edge: ";
				cin>>cost;
				mat[x][y]=cost;
				mat[y][x]=cost;
			}
			cout<<"Adjacency matrix created successfully!"<<endl;
			//Our adjacency matrix has been created here
		}
		
		void printgraph()
		{
			for (int i=0; i<5; i++)
			{
				for (int j=0; j<5; j++)
				{
					cout<<mat[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		
		void prims()
		{
			int v; //new vertex
			int u; //old vertex
			int n=5;
			int edges= n-1;
			int sum=0;
			dist[0]=0;
			visited[0]=1;
			for (int i=1; i<n; i++)
			{
				visited[i]=0;
				dist[i]=mat[0][i];
				from[i]=0;
			}
				
			while (edges > 0)
			{
				int min=100;
				for (int i=1; i<n; i++)
				{
					if (visited[i]==0)
					{
						if (dist[i]<min)
						{
							min=dist[i];
							v=i;
						}
					}
				}
				u=from[v];
				b[u][v]=min;
				b[v][u]=min;
				edges--;
				
				sum=sum+min;
				
				visited[v]=1;
				for (int i=1; i < n; i++)
				{
					if (visited[i]==0)
					{
						if (dist[i] > mat[v][i])
						{
							dist[i]=mat[v][i];
							from[i]=v;
						}
					}
				}
			}
			cout<<"Minimum cost is: "<<sum<<endl;
		}
};

int main()
{
	graph g;
	g.readgraph();
	g.printgraph();
	g.prims();
	return 0;
}
