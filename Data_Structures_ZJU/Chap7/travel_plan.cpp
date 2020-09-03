#include<iostream>
#include<vector>

#define INFINITY 500000

using namespace std;

int N,M,S,D;
vector<vector<int>> GraphLength;
vector<vector<int>> GraphCost;
vector<bool> collected;
vector<int> dist;
vector<int> cost;

void Dijkstra();

int main() {
    cin>>N>>M>>S>>D;
    GraphLength.assign(N,vector<int>(N,0));
    GraphCost.assign(N,vector<int>(N,0));
    collected.assign(N,false);
    dist.assign(N,INFINITY);
    cost.assign(N,0);

    for (int i = 0; i < M; i++)
    {
        int city1,city2,length,c;
        cin>>city1>>city2>>length>>c;
        
        GraphLength[city1][city2] = length;
        GraphCost[city1][city2] = c;
        GraphLength[city2][city1] = length;
        GraphCost[city2][city1] = c;
    }
    Dijkstra();
}

void Dijkstra() {
    collected[S] = true;
    dist[S] = 0;
    cost[S] = 0;
    for (int i = 0; i < N; i++)
    {
        if (GraphLength[S][i]) {
            dist[i] = GraphLength[S][i];
            cost[i] = GraphCost[S][i];
        }
    }
    
    while (true) {
        int MiniV = -1;
        int MiniDist = INFINITY;
        for (int i = 0; i < N; i++) {
            if (!collected[i] && dist[i] < MiniDist) {
                MiniV = i;
                MiniDist = dist[i];
            }
        }

        if (MiniV == -1) break;             //找不到这样的节点了
        collected[MiniV] = true;
        for (int i = 0; i < N; i++)
        {
            if (GraphLength[MiniV][i] && (collected[i] == false) ) {
                if (dist[MiniV] + GraphLength[MiniV][i] < dist[i]) {
                    dist[i] = dist[MiniV] + GraphLength[MiniV][i];
                    //path[i] = MiniV;
                    cost[i] = cost[MiniV] + GraphCost[MiniV][i];
                } else  if (dist[MiniV] + GraphLength[MiniV][i] == dist[i] && cost[MiniV] + GraphCost[MiniV][i] < cost[i]) {
                    cost[i] = cost[MiniV] + GraphCost[MiniV][i];
                    //path[i] = MiniV
                }
            }
        }
    }

    cout<<dist[D]<<" "<<cost[D]<<endl;
}