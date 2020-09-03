#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int MAXV = 10005;

int N;
int table[MAXV];
vector<int> G[MAXV];

int main() {
    scanf("%d",&N);
    
    int indegree[N] = {0};

    for (int i = 0; i < N; i++)
    {
        scanf("%d",&table[i]);
    }

    vector<int> q;
    for (int i = 0; i < N; i++)
    {
        if (table[i] <= -1) continue;
        int position = table[i] % N;
        while (position != i) {
            G[position].push_back(i);
            indegree[i]++;
            position = (position+1) % N;
        }
        if (indegree[i] == 0) {
            q.push_back(i);
        }
    }
    
    sort(q.begin(),q.end(),[]( int a,  int b) {return table[a] > table[b];});
    
    // Top Sort
    bool flag = false;
    while (!q.empty()) {
        int u = q.back();
        q.pop_back();
        if (table[u] == -1) continue;
        if (!flag) {
            printf("%d",table[u]);
            flag = true;
        } else {
            printf(" %d",table[u]);
        }

        for (auto v:G[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push_back(v);
        }
        sort(q.begin(),q.end(),[]( int a,  int b) {return table[a] > table[b];});
    }
    printf("\n");
    return 0;
}


/*
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int MAXV = 10005;

int N;
int table[MAXV];
vector<int> G[MAXV];

struct cmp {
    bool operator() (int i, int j) {
        return table[i]>table[j];
    }
};

int main() {
    scanf("%d",&N);
    
    int indegree[N] = {0};

    for (int i = 0; i < N; i++)
    {
        scanf("%d",&table[i]);
    }

    priority_queue<int,vector<int>,cmp> q;
    for (int i = 0; i < N; i++)
    {
        if (table[i] <= -1) continue;
        int position = table[i] % N;
        while (position != i) {
            G[position].push_back(i);
            indegree[i]++;
            position = (position+1) % N;
        }
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    // Top Sort
    bool flag = false;
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        if (!flag) {
            printf("%d",table[u]);
            flag = true;
        } else {
            printf(" %d",table[u]);
        }

        for (auto v:G[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }
    printf("\n");
    return 0;
}
*/