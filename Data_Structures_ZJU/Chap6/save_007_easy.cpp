#include<iostream>
#include<vector>

using namespace std;

void save_007();
bool DFS(int v);
bool first_jump(int v);
bool is_safe(int v);
bool jump(int v, int w);

struct coordinate {
    int x;
    int y;
};

int N;
int D;
vector<bool> visited;
vector<struct coordinate> graph;

int main() {
    cin>>N>>D;
    graph.resize(N);
    visited.assign(N,false);

    for (int i = 0; i < N; i++)
    {
        cin>>graph[i].x>>graph[i].y;
    }
    save_007();
    return 0;
}

void save_007() {
    bool result = false;
    for (int i=0; i<graph.size(); i++) {
        if (!visited[i] && first_jump(i)) {
            result = DFS(i);
            if (result) break;
        }
    }
    cout<<(result?"Yes":"No")<<endl;
}

bool first_jump(int v) {
    int x = graph[v].x;
    int y = graph[v].y;
    return x*x+y*y <= (D+7.5)*(D+7.5);
}

bool DFS(int v) {
    visited[v] = true;
    bool result = false;
    if (is_safe(v)) return true;
    else {
        for (int i = 0; i < N; i++)
        {
            if (!visited[i] && jump(v,i)) {
                result = DFS(i);
                if (result) break;
            }
        }
    }
    return result;
}

bool is_safe(int v) {
    return (graph[v].x + 50 <= D) || (50 - graph[v].x <= D) || (graph[v].y + 50 <= D) || (50 - graph[v].y <= D);
}

bool jump(int v, int w) {
    int x = graph[v].x - graph[w].x;
    int y = graph[v].y - graph[w].y;
    return x*x+y*y <= D*D;
}