#include<iostream>
#include<queue>
#define MAX_VERTEX_NUM 10

using namespace std;

void DFS(int v);
void BFS(int v);

int Nv,Ne;
int MGraph[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
bool visited[MAX_VERTEX_NUM];

int main() {
    
    cin>>Nv>>Ne;
    for(int i = 0; i<Ne; ++i) {
        int V1,V2;
        cin>>V1>>V2;
        MGraph[V1][V2] = 1;
        MGraph[V2][V1] = 1;
    }
    for (int i = 0; i<Nv; ++i) {
        if (visited[i]) continue;
        cout<<"{";
        DFS(i);
        cout<<" }"<<endl;
    }
    
    for (int i = 0; i < Nv; i++)
    {
        visited[i] = false;
    }
    
    for (int i = 0; i < Nv; i++) {
        if (visited[i]) continue;
        cout<<"{";
        BFS(i);
        cout<<" }"<<endl;
    }
    return 0;
}

void DFS(int v) {
    visited[v] = true;
    cout<<" "<<v;
    for (int i = 0; i<Nv; ++i) {
        if (MGraph[v][i] == 1 && !visited[i])
            DFS(i);
    }
}

void BFS(int v) {
    visited[v] = true;
    cout<<" "<<v;
    queue<int> q;
    q.push(v);

    while (!q.empty())
    {
        int V = q.front();
        q.pop();
        for (int i = 0; i < Nv; i++)
        {
            if (MGraph[V][i] == 1 && !visited[i]) {
                visited[i] = true;
                cout<<" "<<i;
                q.push(i);
            }
        }
    }
}