#include<cstdio>
#include<algorithm>
using namespace std;

struct range {
    int left,right;
};

int main() {
    int n,a,b,sum = 0;
    scanf("%d",&n);
    range H[2005],W[2005];
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&H[i].left,&H[i].right);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&W[i].left,&W[i].right);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (W[j].left <= H[i].right && W[j].right >= H[i].left)
                sum += min(W[j].right,H[i].right) - max(W[j].left,H[i].left);
        }
    }
    
    printf("%d\n",sum);
    return 0;
}