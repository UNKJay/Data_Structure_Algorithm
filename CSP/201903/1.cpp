#include<cstdio>

using namespace std;

const int MAX = 0x3fffffff;
const int MIN = -MAX;

int main() {
    bool flag = false;
    int n,min = MAX, max = MIN;
    double mid;
    scanf("%d",&n);
    int num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
        min = (num[i] < min)?num[i]:min;
        max = (num[i] > max)?num[i]:max;
    }
    if (n&1) {      //奇数
        mid = num[n/2];
    } else {        //偶数
        if ((num[n/2] + num[n/2 -1]) & 1) flag = true;
        mid = (num[n/2] + num[n/2 -1])/2.0;
    }
    if (flag)
        printf("%d %.1f %d\n",max,mid,min);
    else
        printf("%d %d %d\n",max,(int)mid,min);
    return 0;
}