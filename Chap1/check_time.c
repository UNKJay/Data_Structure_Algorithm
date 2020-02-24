#include<stdio.h>
#include<time.h>
#include<math.h>

double f1(int n, double a[], double x){
    double result=a[0];
    for (int i = 1; i <= n; i++)
        result+=(a[i]*pow(x,i));
    return result;    
}

double f2(int n, double a[], double x){
    double result=a[n];
    for (int i = n-1; i >= 0; i--)
        result= x*result+a[i];
    return result;    
}

#define MAXN 10
#define MAXK 1e7

int main(){

    clock_t start,stop;
    double duration;
    double a[MAXN];

    for (int i = 0; i < MAXN; i++)
        a[i]=(double)i;
    

    start=clock();
    for (int i = 0; i < MAXK; i++)
        f1(MAXN-1,a,1.1);
    stop=clock();
    duration= (double)(stop-start)/CLOCKS_PER_SEC/MAXK;
    printf("tickets1= %f\n", (double)(stop-start));
    printf("duration = %6.2e\n",duration);

    start=clock();
    for (int i = 0; i < MAXK; i++)
        f2(MAXN-1,a,1.1);
    stop=clock();
    duration= (double)(stop-start)/CLOCKS_PER_SEC/MAXK;
    printf("tickets2= %f\n", (double)(stop-start));
    printf("duration = %6.2e\n",duration);

    return 0;
}