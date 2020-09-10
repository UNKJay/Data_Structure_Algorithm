#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXV = 100005;
const int MAXE = 200005;

struct Edge
{
    int u,v,cost;
} E[MAXE];

void Kruskal();
int findFather(int x);

int n,m;
int father[MAXV];

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].cost);
    }
    Kruskal();
    return 0;
}

void Kruskal() {
    int ans = 0;
    fill(father+1,father+n+1,-1);
    sort(E,E+m,[] (const Edge& a, const Edge& b) {return a.cost < b.cost;});

    for (int i = 0; i < m; i++)
    {
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);
        if (faU != faV) {
            ans = E[i].cost;
            father[faU] = faV;
        }
        if (findFather(1) == findFather(n) && findFather(1) != -1) break;
    }
    printf("%d\n",ans);
}

int findFather(int x) {
    if (father[x] < 0) return x;
    else return father[x] = findFather(father[x]);
}