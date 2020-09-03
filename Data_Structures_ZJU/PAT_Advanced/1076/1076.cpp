#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,L;
vector<vector<int>> MGraph;
vector<bool> visited;

void Input();
int BFS( int n);

int main() {
    cin>>N>>L;
    int K;
    Input();
    cin>>K;
    for (int i=0; i<K; ++i) {
        int num;
        cin>>num;
        visited.assign(N+1,false);
        cout<<BFS(num)<<endl;
    }
    return 0;
}

void Input() {
    MGraph.resize(N+1);
    for (int i = 1; i <= N; i++)
    {
        MGraph[i].assign(N+1,0);
    }
    visited.assign(N+1,false);
    
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin>>num;
        for (int j = 0; j < num; j++)
        {
            int temp;
            cin>>temp;
            MGraph[temp][i] = 1;
        }
    }
}

int BFS( int n) {
    int result = 0;
    int level = 0, last = n, tail;
    queue<int> q;

    q.push(n);
    visited[n] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = 1; i <= N; i++)
        {
            if (MGraph[temp][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
                result++;
                tail = i;
            }
        }
        if (temp == last) {
            level++;
            last = tail;
        }

        if (level == L) break;
    }
    return result;
}