#include<stdio.h>
void dfs(int);
int n,i,j,a[10][10],vis[10],count;

void main()
{
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
        vis[i]=0;
    }
    printf("dfs traversal \n");
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
            dfs(i);
    }
    for(i=0;i<n;i++)
    {
        if(vis[i])
        {
            count++;
        }
        if(count==n)
            printf("\n Graph is not connected\n");
        else
            printf("\n Graph is connected\n");
    }


}
void dfs(int v)
    {
        vis[v]=1;
        printf("%d",v);
        for(j=1;j<=n;j++)
        {
            if(a[v][j]==a&&vis[j]==0)
            {
                dfs(j);
            }
        }
    }
