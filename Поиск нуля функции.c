#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f (double x){
    return sin(0.5*x+1);
}
double solver1_2 (double (*f)(double x),double a, double b,double eps,double *delta,int *n){
    double x1;
    if (fabs(f(a))<eps){
        return a;
        *n=0;
        *delta=b-a;
    }
    if (fabs(f(b))<eps){
        return b;
        *n=0;
        *delta=b-a;
    }
    x1=(a+b)/2;
    *n=0;
    while (fabs(f(x1))>eps){
        (*n)=(*n)+1;
        if(f(x1)>0)
            b=x1;
        else
            a=x1;
        x1=(a+b)/2;
        if (*n>10000)
            return -1;
    }
    *delta=b-a;
    return (a+b)/2;
}
int main(){
    double y,a,b,eps;
    int n;
    double delta;
    scanf("%lf",&a);
    scanf("%lf",&b);
    scanf("%lf",&eps);
    y=solver1_2(f,a,b,eps,&delta,&n);
    printf("%.15lf %.15lf %d",y,delta,n);
    return 0;
}
