bool isSafe(int node,int c,int n,bool graph[101][101],int color[])
{
    for(int i=0;i<n;i++)
    {
        if(i!=node && graph[i][node]==1 && color[i]==c)
        return false;
    }
    return true;
}
bool solve(int node,int m,int n,bool graph[101][101],int color[])
{
    if(node==n)return true;
    
    for(int i=1;i<=m;i++)
    {
        if(isSafe(node,i,n,graph,color))
        {
            color[node]=i;
            if(solve(node+1,m,n,graph,color))
            return true;
            color[node]=0;
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    
    int color[V]={0};
    if(solve(0,m,V,graph,color))return true;
    
    return false;
    
}