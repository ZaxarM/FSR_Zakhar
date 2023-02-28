#include <stdio.h>
#include <stdlib.h>
int k=0;

void DFS (int V,int adj_mat[V][V],int col[V],int vert,int c_col){
    int i;
    if (col[vert])
        return;
    col[vert]=-1;
    k++;
    for (i=0;i<V;i++)
        if (vert!=i&&adj_mat[vert][i]==1){
            if (col[i]==0){
                DFS(V,adj_mat,col,i,c_col);
            }
    }
    col[vert]=c_col;
    return;
}
int find_adj_comp(int V, int adj_mat[V][V]){
    int col[V];
    int i,j,cnt;
    for (i=0;i<V;i++)
        col[i]=0;
    int flag =1;
    i=0;
    while(flag){
        cnt++;
        DFS(V,adj_mat,col,i,cnt);
        flag=0;
        i=0;
        while(i<V&&!flag)
            flag=!col[i++];
        i--;
    }
    printf("u%d\n",cnt);
    for(i=0;i<V;i++)
        printf("%d ",col[i]);
    int comp[cnt];
    for (i=0;i<cnt;i++)
        comp[i]=0;
    for (i=1;i<=cnt;i++)
        for (j=0;j<V;j++)
            if (col[j]==i)
                comp[i-1]++;
    for (i=0;i<cnt;i++){
        printf("%d\n",comp[i]);
        for (j=0;j<V;j++)
            if (col[j]==i+1)
                printf("%d ",j+1);
    }
    return cnt;
    
    
    
}

