#include <stdio.h>
#include <math.h>

double norm (int n, double a[n]){
    int i;
    double res=0;
    for (i=0;i<n;i++)
        res=res+a[i]*a[i];
    return res;
}
void GS_orth(int n,int k, double mat[k][n], double orth_mat[k][n]){
    int i,j,l;
    double sc,norma,d;
    for (i=0;i<k;i++){
        for (l=0;l<n;l++)
            orth_mat[i][l]=mat[i][l];
        for (j=0;j<i;j++){
            sc=scalar(n,mat[i],orth_mat[j]);
            norma=norm(n,orth_mat[j]);
            if (norma!=0)
                d=sc/norma;
            else
                d=0;
            for (l=0;l<n;l++)
                orth_mat[i][l]=orth_mat[i][l]-d*orth_mat[j][l];
        }
    }
    for (i=0;i<k;i++){
        for (j=0;j<n;j++)
            printf("%lf ",orth_mat[i][j]);
        printf("\n");
    }
    return;
}
int main(){
    int n,k,i,j;
    scanf("%d",&n);
    scanf("%d",&k);
    double mat[k][n];
    double orth_mat[k][n];
    for (i=0;i<k;i++)
        for (j=0;j<n;j++)
            scanf("%lf",&mat[i][j]);
    GS_orth(n,k,mat,orth_mat);
    return 0;
}

