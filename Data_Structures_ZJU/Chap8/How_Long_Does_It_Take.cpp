#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

const int MAXV = 110;

struct Edge {
    int v;
    int weight;
    Edge(int _v, int _w):v(_v),weight(_w) {}
};

bool TopSort();
int CriticalPath();

int N,M;
int inDegree[MAXV];
int ve[MAXV], vl[MAXV];
vector<Edge> G[MAXV];
stack<int> topOrder;            //拓扑序列

int main() {
    int u,v,w;
    int ans;
    scanf("%d%d",&N,&M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        inDegree[v]++;
        G[u].push_back(Edge(v,w));
    }
    
    ans = CriticalPath();
    printf("%d\n",ans);
    for (int u = 1; u <= N; u++)
    {
        for (int j = G[u].size() - 1; j >= 0; j--) {
            int v = G[u][j].v;
            int w = G[u][j].weight;
            int e = ve[u];
            int l = vl[v] - w;
            if (e == l) {
                printf("%d->%d\n",u,v);
            }
        }
    }
    return 0;
}

bool TopSort() {
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0) 
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topOrder.push(u);
        for (auto i: G[u]) {
            int v = i.v;
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
            
            if (ve[u] + i.weight > ve[v]) {
                ve[v] = ve[u] + i.weight;
            }
        }
    }
    return (topOrder.size() == N) ;
}

int CriticalPath() {
    if (!TopSort()) return 0;

    int maxLength = 0;
    for (int i = 1; i <= N; i++)
    {
        maxLength = (ve[i] > maxLength)?ve[i]:maxLength;
    }
    fill(vl,vl+N+1,maxLength);

    while (!topOrder.empty())
    {
        int u = topOrder.top();
        topOrder.pop();

        for (auto i: G[u]) {
            int v = i.v;
            if (vl[v] - i.weight < vl[u]) {
                vl[u] = vl[v] - i.weight;
            }
        }
    }

    /*
    for (int u = 1; u <= N; u++)
    {
        for (int j = G[u].size() - 1; j >= 0; j--) {
            int v = G[u][j].v;
            int w = G[u][j].weight;
            int e = ve[u];
            int l = vl[v] - w;
            if (e == l) {
                printf("%d->%d\n",u,v);
            }
        }
    }
    */   
    return maxLength;
}