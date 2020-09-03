#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

#define INF (~(1<<31))

int N,K;
vector<int> weight;
vector<vector<int>> graph;
vector<bool> collected;
vector<int> d;

int totalPath, maxHappiness, maxAvgHappiness;
vector<int> tempPath, path;
/* 
vector<int> num;
vector<int> happiness;
vector<int> pt;                         //pt记录顶点数
*/
vector<vector<int>> pre;                        //pre记录前驱
map<string,int> cityToIndex;            //城市名变为编号
map<int,string> indexToCity;          //编号变为城市名

void Dijsktra(int s);

void DijsktraForDFS(int s);
void DFS(int v);
void Print(int v);

int main() {
    string start,city1,city2;
    cin>>N>>K>>start;

    weight.assign(N,0);
    graph.assign(N,vector<int>(N,INF));
    cityToIndex[start] = 0;         //起点为0
    indexToCity[0] = start;
    for (int i = 1; i < N; i++)
    {
        cin>>city1>>weight[i];
        cityToIndex[city1] = i;
        indexToCity[i] = city1;
    }

    for (int i = 0; i < K; i++)
    {
        cin>>city1>>city2;
        int c1 = cityToIndex[city1];
        int c2 = cityToIndex[city2];
        cin>>graph[c1][c2];
        graph[c2][c1] = graph[c1][c2];
    }
    
    DijsktraForDFS(0);
    int Rom = cityToIndex["ROM"];
    DFS(Rom);
    //cout<<num[Rom]<<" "<<d[Rom]<<" "<<happiness[Rom]<<" "<< happiness[Rom] / pt[Rom]<<endl;
    cout<<totalPath<<" "<<d[Rom]<<" "<<maxHappiness<<" "<< static_cast<int>(maxAvgHappiness)<<endl;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout<<indexToCity[path[i]];
        if (i > 0) cout<<"->";
    }
    cout<<endl;
    return 0;
}

/*
void Dijsktra(int s) {              //一步一步求
    num.assign(N,0);
    d.assign(N,INF);
    happiness.assign(N,0);
    pt.assign(N,0);
    collected.assign(N,false);

    num[s] = 1;
    d[s] = 0;

    for (int i = 0; i < N; i++)
    {
        pre.push_back(i);
    }

    while (true) {
        int u = -1, MIN = INF;
        for (int i = 0; i < N; i++)
        {
            if (!collected[i] && d[i] < MIN) {
                MIN = d[i];
                u = i;
            }
        }
        if (u == -1) break;
        collected[u] = true;
        for (int v = 0; v < N; v++)
        {
            if (!collected[v] && graph[u][v] != INF) {
                if (d[u] + graph[u][v] < d[v]) {
                    d[v] = d[u] + graph[u][v];
                    num[v] = num[u];
                    happiness[v] = happiness[u] + weight[v];
                    pt[v] = pt[u] + 1;
                    pre[v] = u;
                } else if (d[u] + graph[u][v] == d[v]) {
                    num[v] += num[u];
                    if (happiness[v] < happiness[u] + weight[v]) {
                        happiness[v] = happiness[u] + weight[v];
                        pt[v] = pt[u] + 1;
                        pre[v] = u;
                    } else if (happiness[v] == happiness[u] + weight[v]) {
                        double uAvg = 1.0 * (happiness[u] + weight[v])/(pt[u] + 1);
                        double vAvg = 1.0 * (happiness[v])/(pt[v]);
                        if (uAvg > vAvg) {
                            pt[v] = pt[u] + 1;
                            pre[v] = u;
                        }
                    }
                }
            }
        }  
    }
}

void Print(int v) {
    if (v == 0) {
        cout<<indexToCity[v];
        return ;
    }
    Print(pre[v]);
    cout<<"->"<<indexToCity[v];
}
*/

void DijsktraForDFS(int s) {
    d.assign(N,INF);
    pre.resize(N);
    collected.assign(N,false);

    d[s] = 0;

    for (int i = 0; i < N; i++)
    {
        pre[i].push_back(i);
    }

    while (true) {
        int u = -1, MIN = INF;
        for (int i = 0; i < N; i++)
        {
            if (!collected[i] && d[i] < MIN) {
                MIN = d[i];
                u = i;
            }
        }
        if (u == -1) break;
        collected[u] = true;
        for (int v = 0; v < N; v++)
        {
            if (!collected[v] && graph[u][v] != INF) {
                if (d[u] + graph[u][v] < d[v]) {
                    d[v] = d[u] + graph[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + graph[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }  
    }
}

void DFS(int v) {
    if (v == 0) {       //回到起点
        tempPath.push_back(v);
        totalPath++;
        int tempHappiness = 0;
        for (int i = tempPath.size() - 2; i >= 0; i--)
        {
            tempHappiness += weight[tempPath[i]];
        }

        double tempAvg = 1.0 * tempHappiness / (tempPath.size() - 1);
        if (tempHappiness > maxHappiness) {
            path = tempPath;
            maxHappiness = tempHappiness;
            maxAvgHappiness = tempAvg;
        } else if (tempHappiness == maxHappiness && tempAvg > maxAvgHappiness) {
            path = tempPath;
            maxAvgHappiness = tempAvg;
        }

        tempPath.pop_back();
        return ;
    }

    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size() ; i++)
    {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}