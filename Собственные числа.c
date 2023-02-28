#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct complex{
    double Re, Im;
};
void print_complex(struct complex x){
    if (x.Im==0)
        printf ("%lf \n",x.Re);
    else if (x.Re==0)
        printf("i*%lf \n",x.Im);
    else
        printf("%lf + %lfi \n",x.Re,x.Im);
    return;
}
void eig_val_2(double a11,double a12,double a21,double a22,struct complex *l1,struct complex *l2){
    double d;
    d=(a11-a22)*(a11-a22)+4*a21*a12;
    if (d>=0){
        l1->Re=(a11+a22+sqrt(d))/2;
        l1->Im=0;
        l2->Re=(a11+a22-sqrt(d))/2;
        l2->Im=0;
    }
    else{
        l1->Re=(a11+a22)/2;
        l2->Re=(a11+a22)/2;
        l1->Im=sqrt(-d)/2;
        l2->Im=-sqrt(-d)/2;
    }
    print_complex(*l1);
    print_complex(*l2);
    return;
}

int main(){
    double a11,a12,a21,a22;
    struct complex l1,l2;
    scanf("%lf",&a11);
    scanf("%lf",&a12);
    scanf("%lf",&a21);
    scanf("%lf",&a22);
    eig_val_2(a11,a12,a21,a22,&l1,&l2);
    return 0;
}
