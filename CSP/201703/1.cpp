#include<cstdio>

using namespace std;

int main() {
    int n,k,count = 0, total = 0;;
    int cake[1005];
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&cake[i]);
        total += cake[i];
        if (total >= k) {
            count++;
            total = 0;
        }
    }
    if (total > 0) count++;
    printf("%d\n",count);
    return 0;
}