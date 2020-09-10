#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXV = 1005;

int N,M;
bool visited[MAXV];
bool know[MAXV][MAXV];
vector<int> G[MAXV];

void DFS(int u, int start);

int main() {
    int u,v,result = 0;
    scanf("%d%d",&N,&M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    
    for (int i = 1; i <= N; i++) {
        fill(visited+1,visited+N+1,false);
        DFS(i,i);
    }

    for (int i = 1; i <= N; i++)
    {
        if (count(know[i]+1, know[i] + N + 1, true) == N)
            result++;
    }
    printf("%d\n",result);
    return 0;
}

void DFS(int u, int start) {
    visited[u] = true;
    know[start][u] = true;
    know[u][start] = true;
    for (auto v:G[u]) {
        if (!visited[v])
            DFS(v,start);
    }
}