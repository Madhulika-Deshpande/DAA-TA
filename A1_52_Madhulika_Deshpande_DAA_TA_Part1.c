#include<stdio.h>
#define N 4
#define INF 9999
char cities[]={'A','B','C','D'};
int cost[N][N]={
    {0,10,15,20},
    {10,0,35,25},
    {15,35,0,30},
    {20,25,30,0}
};
int route[N+1];
char routes[100][N+1];
int totalDistance[100];
int count=0;
int mincost=INF;
int shortestRoute[100][N+1];
int shortest=0;
void tsp(int current,int visited[],int position,int total)
{
    if(position==N)
    {
        total+=cost[current][0];
        for(int i=0;i<N;i++)
        {
            routes[count][i]=route[i];
        }
         routes[count][N]=0;
         totalDistance[count]=total;
         count++;
    if(total<mincost)
    {
        mincost=total;
        shortest=0;
        for(int i=0;i<N;i++)
        {
            shortestRoute[shortest][i]=route[i];
        }
        shortestRoute[shortest][N]=0;
        shortest=1;
    }
    else if(total==mincost)
    {
        for(int i=0;i<N;i++)
        {
            shortestRoute[shortest][i]=route[i];
        }
        shortestRoute[shortest][N]=0;
        shortest++;
    }
    return;
}
   for(int i=0;i<N;i++)
   {
    if(!visited[i])
    {
        visited[i]=1;
        route[position]=i;
        tsp(i,visited,position+1,total+cost[current][i]);
        visited[i]=0;
    }
   }
}
int main()
{
    int visited[N]={0};
    visited[0]=1;
    route[0]=0;
    tsp(0,visited,1,0);
    printf("All possible routes:\n");
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%c->",cities[routes[i][j]]);
        }
        printf("%c\n",cities[0]);
    }
    printf("\nTotal distance for each route:\n");
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%c->",cities[routes[i][j]]);
        }
        printf("%c: %dkm \n",cities[0],totalDistance[i]);
    }
    printf("\nBest Route:");
    printf("\nShortest distance: %dkm\n",mincost);
    for(int i=0;i<shortest;i++)
    {
        printf("Route:");
        for(int j=0;j<=N;j++)
        {
            printf("%c",cities[shortestRoute[i][j]]);
            if(j<N)
            {
                printf("->");
            }
        }
        printf("\n");
    }
    return 0;
}
