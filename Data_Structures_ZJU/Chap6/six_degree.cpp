#include<iostream>
#include<queue>
#include<vector>
#include<iomanip>

using namespace std;

int Nv,Ne;
vector<vector<int>> MGraph;
vector<bool> visited;

int BFS(int v);

int main() {
    cin>>Nv>>Ne;
    MGraph.resize(Nv+1);
    visited.assign(Nv+1,false);
    for (int i = 1; i <= Nv; i++)
    {
        MGraph[i].assign(Nv+1,0);
    }
    
    for (int i = 1; i <= Ne; i++)
    {
        int V1,V2;
        cin>>V1>>V2;
        MGraph[V1][V2] = 1;
        MGraph[V2][V1] = 1;
    }
    
    for (int i=1; i<=Nv; i++) {
        
        visited.assign(Nv+1,false);
        int V = BFS(i);
        double result = 100.0*V/Nv;
        cout<<i<<": "<<setiosflags(ios_base::fixed)<<setprecision(2)<<result<<"%"<<endl;
    }
    return 0;
}

int BFS(int v) {
    int level = 0;
    int count = 1;
    int last = v;
    int tail = 0;

    queue<int> q;
    visited[v] = true;
    q.push(v);

    while (!q.empty())
    {
        int V = q.front();
        q.pop();
        for (int i = 1; i <= Nv; i++)
        {
            if (MGraph[V][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
                count++;
                tail = i;
            }
        }
        if (V == last) {
            level ++;
            last = tail;
        }
        if (level == 6) break;
    }
    return count;
}