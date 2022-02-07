
--------------------------------------------------------------------------------------------------
                                /*Dijkstra's Algorithm*/

#define INFINITY 9999 
#include <stdio.h>
#include <conio.h>
#define MAX 10

void dijkstra(int G[MAX][MAX],int n, int startnode);
---------------------------------------------------------------------------------------------------
MAIN CLASS 
---------------------------------------------------------------------------------------------------
int main()
{
	int G[MAX][MAX],i,j,n,noofedges,u,v,w;
	
	printf("\nEnter no. of vertices : ");
	scanf("%d",&n);
	printf("\n No. of edges : ");
	scanf("%d",&noofedges);
	printf("\nEnter edges (u,v,weight)  : ");
	for(i=0;i<noofedges;i++)
	   {
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=G[v][u]=w;
	   }
	printf("\nEnter the starting node : ");
	scanf("%d",&u);
	dijkstra(G,n,u);
	return(0);
}
---------------------------------------------------------------------------------------------------
Function Name = dijiksta
Input = int G[MAX][MAX],int n, int startnode
Output = Print the path and distance of each node
---------------------------------------------------------------------------------------------------
void dijkstra(int G[MAX][MAX],int n, int startnode)
{
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;
	/*pred[] stores the predecessor of each node
	count gives the number of nodes seen so far*/

	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
//initialize
	for(i=0;i<n;i++)
	   {
		distance[i]=cost[startnode][i];
		pred[i]=startnode;visited[i]=0;
	   }
	distance[startnode]=0;visited[startnode]=1;
	count=1;
	while(count<n-1)
	   {
		mindistance=INFINITY ;
// nextnode is the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i] < mindistance && !visited[i])
			    {
				mindistance=distance[i];
				nextnode=i;
			    }
//check if a better path exist through nextnode
		visited[nextnode]=1;
		for(i=0;i<n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i]<distance[i])
				    {
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				    }
		count++;
 }

//print the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=startnode)
		   {
			printf("\n Distance of %d = %d ",i,distance[i]);
			printf("\nPath = %d ",i);
			j=i;
			do
			   {
				j=pred[j];
				printf("<- %d ",j);
			   }while(j!=startnode);
		   }

}

---------------------------------------------------------------------------------------------------
OUTPUT
---------------------------------------------------------------------------------------------------
Enter no. of vertices : 3

No. of edges : 4

Enter edges (u,v,weight)  : 1
2
3
4
2
3
4
1
3
1
2
4

Enter the starting node : 1

 Distance of 0 = 10003
Path = 0 <- 2 <- 1
 Distance of 2 = 4
Path = 2 <- 1
--------------------------------
Process exited after 31.75 seconds with return value 0
Press any key to continue . . .
