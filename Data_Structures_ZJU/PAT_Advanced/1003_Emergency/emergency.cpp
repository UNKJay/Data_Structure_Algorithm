#include<iostream>
#include<vector>

#define INFINITY (~(1<<31))

using namespace std;

int N,M,S,D;
vector<vector<int>> GraphLength;
vector<int> GraphData;
vector<bool> collected;
vector<int> dist;                   //最短路距离
vector<int> cost;                   //最短路可号召人数
vector<int> count;                  //最短路条数

void Dijkstra();

int main() {
    cin>>N>>M>>S>>D;
    GraphLength.assign(N,vector<int>(N,0));
    GraphData.assign(N,0);
    collected.assign(N,false);
    dist.assign(N,INFINITY);
    cost.assign(N,0);
    count.assign(N,0);

    for (int i = 0; i < N; i++)
    {
        cin>>GraphData[i];
    }

    for (int i = 0; i < M; i++)
    {
        int city1,city2,length;
        cin>>city1>>city2>>length;
        GraphLength[city1][city2] = length;
        GraphLength[city2][city1] = length;
    }
    Dijkstra();
}

void Dijkstra() {
    collected[S] = true;
    dist[S] = 0;
    cost[S] = GraphData[S];
    count[S] = 1;

    for (int i = 0; i < N; i++)
    {
        if (GraphLength[S][i]) {
            dist[i] = GraphLength[S][i];
            cost[i] = GraphData[i] + cost[S];
            count[i] += count[S]; 
        }
    }
    
    while (!collected[D]) {
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
            if (GraphLength[MiniV][i] && (collected[i] == false) ) {            //找到最短路
                if (dist[MiniV] + GraphLength[MiniV][i] < dist[i]) {
                    dist[i] = dist[MiniV] + GraphLength[MiniV][i];
                    //path[i] = MiniV;
                    cost[i] = cost[MiniV] + GraphData[i];
                    count[i] = count[MiniV];
                } else  if (dist[MiniV] + GraphLength[MiniV][i] == dist[i]) {
                    if (cost[MiniV] + GraphData[i] > cost[i])
                        cost[i] = cost[MiniV] + GraphData[i];
                    count[i] += count[MiniV];
                    //path[i] = MiniV
                }
            }
        }
    }
    cout<<count[D]<<" "<<cost[D]<<endl;
}