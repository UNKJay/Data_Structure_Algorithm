/* Prim
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXV = 1010;
const int INF = 0x3fffffff;

struct Edge {
    int dest;
    int weight;
    Edge(int _d, int _w):dest(_d),weight(_w) {}
};

int N,M,ans = 0;
bool collected[MAXV] = {false};
int d[MAXV];
vector<Edge> G[MAXV];

void Prim(int s);

int main() {
    int u,v,w;
    bool result = true;
    scanf("%d%d",&N,&M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    Prim(1);
    for (int i = 1; i <= N; i++)
    {
        if (!collected[i]) {
            result = false;
            break;
        }
    }
    printf("%d\n",result?ans:-1);
    return 0;
}

void Prim(int s) {
    int u = -1, MIN = INF;
    fill(d,d+MAXV,INF);
    d[1] = 0;
    
    while (true)
    {
        int u = -1, MIN = INF;
        for (int i = 1; i <= N; i++)
        {
            if (!collected[i] && d[i] < MIN) {
                u = i;
                MIN = d[i];
            }
        }
        
        if (u == -1) break;
        collected[u] = true;
        ans += d[u];

        for (auto i : G[u]) {
            if (!collected[i.dest] && i.weight < d[i.dest]) {
                d[i.dest] = i.weight;
            }
        }
    }
}

*/

//Kruskal

#include<cstdio>
#include<algorithm>

using namespace std;
const int MAXV = 1010;
const int MAXE = 3030;

struct Edge {
    int u,v;
    int weight;
} E[MAXE];

int N,M;
int Father[MAXV];

int Kruskal();
int FindFather( int x);

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d",&E[i].u, &E[i].v, &E[i].weight);
    }
    printf("%d\n",Kruskal());
    return 0;
}

int Kruskal() {
    int ans = 0, numEdge = 0;
    fill(Father,Father+N,-1);
    sort(E,E+M,[](const Edge& a, const Edge &b) {return a.weight < b.weight;});

    for (int i = 0; i < M; i++)
    {
        int faU = FindFather(E[i].u);
        int faV = FindFather(E[i].v);
        if (faU != faV) {
            ans += E[i].weight;
            numEdge ++;
            Father[faU] = faV;
            if (numEdge == N-1) break;
        }
    }
    if (numEdge == N-1) return ans;
    else return -1;
}

int FindFather(int x) {
    if (Father[x] < 0 ) return x;
    else  return Father[x] = FindFather(Father[x]);
}