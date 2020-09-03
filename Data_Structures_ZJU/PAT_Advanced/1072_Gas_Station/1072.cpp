#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

#define INF (~(1<<31))
struct Edge {
    int v;
    int length;
    Edge(int _v = 0, int _length = 0):v(_v),length(_length) {}
};

int trans(char str[]);
void Dijsktra( int S);

int N,M,K,D;
vector<vector<Edge>> graph;             //邻接表
vector<bool> collected;
vector<int> dist;

int main() {
    scanf("%d%d%d%d",&N,&M,&K,&D);
    graph.resize(N+M+1);
    for (int i = 0; i < K; i++)
    {
        char a[10];
        char b[10];
        int s,v,l;
        scanf("%s",a);
        scanf("%s",b);
        scanf("%d",&l);
        s = trans(a);
        v = trans(b);
        graph[s].push_back(Edge(v,l));
        graph[v].push_back(Edge(s,l));
    }
    
    int location = -1;
    double miniAverage = INF;
    double miniLength = -1;
    for (int i = 1; i <= M; i++)             //对M个地方都用一次Dijsktra
    {
        int maxLength = -1;
        int minLength = INF;
        int sum = 0;
        collected.assign(N+M+1,false);
        dist.assign(N+M+1,INF);
        Dijsktra(i+N);


        for (int j = 1; j <= N; j++) {
            int l = dist[j];
            sum += l;
            maxLength = (l > maxLength)?l:maxLength;
            minLength = (l < minLength)?l:minLength;
        }
        if (maxLength > D) continue;

        if ((miniLength < minLength) || (miniLength == minLength && miniAverage > (sum * 1.0/N))){
            miniLength = minLength;
            location = i+N;
            miniAverage = (sum * 1.0/N);
        }
    }

    if (location == -1) 
        printf("No Solution\n");
    else 
        printf("G%d\n%.1f %.1f\n",location - N,miniLength,miniAverage);

    return 0;
}

int trans(char str[]) {
    int result = 0;
    int i = (str[0] == 'G')?1:0;
    for (; i<strlen(str); i++) {
        result = result * 10 + str[i] - '0';
    }
    if (str[0] == 'G') result += N;
    return result;
}

void Dijsktra( int S) {
    dist[S] = 0;
    while (true) {
        int miniV = -1;
        int miniL = INF;
        for (int i = 1; i <= N+M; i++)
        {
            if (!collected[i] && dist[i] < miniL) {
                miniV = i;
                miniL = dist[i];
            }
        }
        if (miniV == -1) break;
        collected[miniV] = true;

        //更新
        for(Edge e: graph[miniV]) {
            if (!collected[e.v] && dist[miniV] + e.length < dist[e.v]) {
                dist[e.v] = dist[miniV] + e.length;
            }
        }
    }
}