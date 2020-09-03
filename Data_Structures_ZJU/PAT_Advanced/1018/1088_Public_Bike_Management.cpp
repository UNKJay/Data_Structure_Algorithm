#include<iostream>
#include<vector>

using namespace std;


#define INF (~(1<<31))

void Dijsktra(int s);
void DFS(int v);

int C,N,Sp,M;
int send = INF, back = INF;              //send表示带出去的，bike表示带回来的
vector<bool> collected;
vector<int> d;
vector<vector<int>> G;
vector<int> weight;
vector<vector<int>> pre;
vector<int> tempPath, path;

int main() {
    cin>>C>>N>>Sp>>M;
    G.assign(N+1,vector<int>(N+1,INF));
    weight.resize(N+1);
    for (int i = 1; i <= N; i++)
    {
        cin>>weight[i];
        weight[i] -= C/2;
    }

    for (int i = 0; i < M; i++)
    {
        int station1, station2;
        cin>>station1>>station2;
        cin>>G[station1][station2];
        G[station2][station1] = G[station1][station2];
    }
    
    Dijsktra(0);
    DFS(Sp);
    cout << send << " ";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout<< path[i];
        if (i > 0 ) cout<<"->";
    }
    cout << " " << back << endl;
    return 0;
}

void Dijsktra(int s) {
    collected.assign(N+1,false);
    d.assign(N+1,INF);
    pre.resize(N+1);
    for (int i = 0; i < N+1; i++)
    {
        pre[i].push_back(i);
    }
    d[s] = 0;

    while (true) {
        int u = -1, MIN = INF;
        for (int i = 0; i < N+1; i++)
        {
            if (!collected[i] && d[i] < MIN) {
                u = i;
                MIN = d[i];
            }
        }
        if (u == -1) break;
        collected[u] = true;

        for (int v = 0; v < N+1; v++)
        {
            if (!collected[v] && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v) {
    if (v == 0) {       //叶子节点
        int tempSend = 0, tempBack = 0;
        tempPath.push_back(v);
        for (int i = tempPath.size() - 1; i >= 0; i--)
        {
            int id = tempPath[i];
            if (weight[id] > 0 ) {
                tempBack += weight[id];
            } else {
                if (tempBack > (-weight[id])) {
                    tempBack += weight[id];
                } else {
                    tempSend += (-weight[id] - tempBack);
                    tempBack = 0;
                }
            }
        }
        if (tempSend < send) {
            send = tempSend;
            path = tempPath;
            back = tempBack;
        } else if (tempSend == send && tempBack < back) {
            path = tempPath;
            back = tempBack;
        }
        tempPath.pop_back();
        return ;
    }

    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++)
    {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}
