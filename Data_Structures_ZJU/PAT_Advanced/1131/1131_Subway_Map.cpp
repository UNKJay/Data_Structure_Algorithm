#include<cstdio>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

const int MAXV = 10005;
const int INF = 0x3fffffff;

int N,K,M,start,dest;
vector<int> G[MAXV],pre[MAXV],tempPath;
int d[MAXV];                      //距离
unordered_map<int,int> line;        //记录边和对应的线
vector<pair<int,int>> trans;

void BFS();
void DFS(int v);

int main() {
    scanf("%d",&N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d%d",&M,&start);
        for (int j = 1; j < M; j++, start = dest)
        {
            scanf("%d",&dest);
            line.insert({start*10000+dest,i});
            line.insert({dest*10000+start,i});
            G[start].push_back(dest);
            G[dest].push_back(start);
        }
    }

    scanf("%d",&K);
    while (K--)
    {
        scanf("%d%d",&start,&dest);
        BFS();
        tempPath.clear();
        trans.clear();
        DFS(dest);
        printf("%d\n",d[dest]);
        for (int i = 1; i < trans.size(); i++)
        {
            printf("Take Line#%d from %04d to %04d.\n",trans[i].second,trans[i-1].first,trans[i].first);
        }
    }
    
    return 0;
}

void BFS() {
    queue<int> q;
    for (int i = 0; i < MAXV; i++)
    {
        pre[i].clear();
        d[i] = INF;
    }
    d[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        
        int u = q.front();
        //printf("%d\n",u);
        q.pop();
        if (d[u] > d[dest]) continue;

        for (int v: G[u]) {
            
            if (d[u] + 1 < d[v]) {
                //printf("v:%d %d\n",v,d[v]);
                pre[v].clear();
                pre[v].push_back(u);
                d[v] = d[u] + 1;
                if (d[v] != INF)
                    q.push(v);
            } else if (d[u] + 1 == d[v]) {
                pre[v].push_back(u);
            }
        }
    }   
}

void DFS(int v) {
    if (v == start) {
        tempPath.push_back(v);
        vector<pair<int,int>> tempTrans = {{start,-1}};
        for (int i = tempPath.size() - 2; i > 0; --i)
        {
            if (line[tempPath[i] * 10000 + tempPath[i-1]] != line[tempPath[i] * 10000 + tempPath[i+1]]) {
                tempTrans.push_back( { tempPath[i] , line[tempPath[i] * 10000 + tempPath[i+1]]} );
            }
        }
        tempTrans.push_back({dest, line[tempPath[0]*10000+tempPath[1]]});
        
        if (trans.empty() || tempTrans.size() < trans.size()) {
            trans = tempTrans;
        }
        tempPath.pop_back();
    }

    tempPath.push_back(v);
    for (int i:pre[v]) {
        DFS(i);
    }
    tempPath.pop_back();
}