#include<cstdio>

using namespace std;

const int MAXN = 1005;

bool check();

int n,m;
int aN,bN;
int c0,c1,c2;
struct coordinate {
    int x,y;
} A[MAXN],B[MAXN];

int main() {
    int x,y;
    char type;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %c",&x,&y,&type);
        if (type == 'A') {
            A[aN].x = x;
            A[aN].y = y;
            aN++;
        } else {
            B[bN].x = x;
            B[bN].y = y;
            bN++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&c0,&c1,&c2);
        printf("%s",check()?"Yes\n":"No\n");
    }
    return 0;
}

bool check() {
    int countA = 0;
    int countB = 0;

    for (int i=0; i<aN; i++) {
        if (c0 + c1*A[i].x + c2*A[i].y > 0) {
            countA++;
        } else {
            countA--;
        }
    }
    if (!(countA == aN || countA == -aN)) return false;

    for (int i=0; i<bN; i++) {
        if (c0 + c1*B[i].x + c2*B[i].y > 0) {
            countB++;
        } else {
            countB--;
        }
    }
    if (!(countB == bN || countB == -bN)) return false;
    return true;
}