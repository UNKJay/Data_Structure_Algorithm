#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
    int n,k,num = 1, index = 1;
    scanf("%d%d",&n,&k);
    int left = n;
    bool alive[1005];
    fill(alive,alive+n+1,true);

    while (left > 1) {
        if (!alive[index]) {
            index = index+1>n?1:index+1;
            continue;
        }
        if (num % 10 == k || num % k == 0) {
            alive[index] = false;
            left--;
            num++;
            index = (index+1>n?1:index+1);
        } else {
            num++;
            index = index+1>n?1:index+1;
        }
    }

    for (index = 1; index <= n; index++)
    {
        if (alive[index]) break;
    }
    printf("%d\n",index);
}