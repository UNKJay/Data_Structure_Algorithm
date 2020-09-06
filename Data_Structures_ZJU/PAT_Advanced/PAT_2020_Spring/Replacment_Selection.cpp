#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
    int N,M;
    int t,last;
    vector<int> first,next,arr;
    priority_queue<int,vector<int>,greater<int>> q;
    scanf("%d%d",&N,&M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&t);
        if (i<M) q.push(t);
        arr.push_back(t);
    }
    
    int count = 0;
    int index = M;
    while (count < N)
    {
        last = q.top();
        q.pop();
        count++;
        first.push_back(last);
        if (index < N) {
            t = arr[index++];
            if (t > last) {
                q.push(t);
            } else {
                next.push_back(t);
            }
        }
        if (q.empty()) {
            for (int j = 0; j < first.size(); j++)
            {
                printf("%s%d",j>0?" ":"",first[j]);
            }
            printf("\n");
            first.clear();
            for (int j = 0; j < next.size(); j++)
            {
                q.push(next[j]);
            }
            next.clear();
        }
    }
    return 0;
}