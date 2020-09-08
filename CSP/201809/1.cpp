#include<cstdio>

using namespace std;

int main() {
    int n,init[1005],result[1005];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&init[i]);
    }
    for (int i = 1; i < n-1; i++)
    {
        result[i] = static_cast<int>((init[i-1] + init[i] + init[i+1])/3.0);
    }
    result[0] = static_cast<int>((init[0]+init[1])/2.0);
    result[n-1] = static_cast<int>((init[n-2]+init[n-1])/2.0);
    for (int i = 0; i < n-1; i++)
    {
        printf("%d ",result[i]);
    }
    printf("%d\n",result[n-1]);
    return 0;
}