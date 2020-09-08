#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
    int n;
    int min = 10000;
    int num[1005];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    for (int i = 1; i < n; i++)
    {
        min = (num[i]-num[i-1] < min)?(num[i]-num[i-1]):min;
    }
    printf("%d\n",min);
    return 0;
}