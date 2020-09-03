#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

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
vector<struct coordinate> graph;
vector<int> dist;
vector<int> path;

int main() {
    cin>>N>>D;
    graph.resize(N);
    dist.assign(N,-1);
    path.assign(N,-1);

    for (int i = 0; i < N; i++)
    {
        cin>>graph[i].x>>graph[i].y;
    }
    sort(graph.begin(),graph.end(),[](const struct coordinate & a, const struct coordinate& b) {return (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);});
    save_007();
    return 0;
}

void save_007() {
    if (D >= 42.5) {
        cout<<1<<endl;
        return ;
    }
    queue<int> q;
    int result = -1;
    for (int i = 0; i < N; i++)
    {
        if (first_jump(i)) {
            q.push(i);
            dist[i] = 1;
            path[i] = i;
        } else if (i == 0) {
            cout<<0<<endl;
            return ;
        }
    }
    

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        if (is_safe(temp)) {
            result = temp;
            break;
        }

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == -1 && jump(temp, i)) {
                q.push(i);
                dist[i] = dist[temp] + 1;
                path[i] = temp;
            }
        }
    }
    
    if (result == -1) {
        cout<<0<<endl;
        return ;
    } else {
        stack<int> sta;
        cout<<dist[result] + 1<<endl;
        while (path[result] != result) {
            sta.push(result);
            result = path[result];
        }
        sta.push(result);
        while (!sta.empty())
        {
            cout<<graph[sta.top()].x<<" "<<graph[sta.top()].y<<endl;
            sta.pop();
        }
    }
}

bool first_jump(int v) {
    int x = graph[v].x;
    int y = graph[v].y;
    return x*x+y*y <= (D+7.5)*(D+7.5);
}

bool is_safe(int v) {
    return (graph[v].x + 50 <= D) || (50 - graph[v].x <= D) || (graph[v].y + 50 <= D) || (50 - graph[v].y <= D);
}

bool jump(int v, int w) {
    int x = graph[v].x - graph[w].x;
    int y = graph[v].y - graph[w].y;
    return x*x+y*y <= D*D;
}