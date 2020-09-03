#include<cstdio>
#include<algorithm>

using namespace std;

struct User{
    int id;
    int rank = 1;
    int score[6] = {-1,-1,-1,-1,-1,-1};
    int totalScore = 0;
    int perfect = 0;
    bool show = false;
} U[100005];

int N,K,M;

bool cmp(const User& u1, const User& u2) {
    if (u1.totalScore != u2.totalScore)
        return u1.totalScore > u2.totalScore;
    
    if (u1.perfect != u2.perfect)
        return u1.perfect > u2.perfect;
    
    return u1.id < u2.id;
}

int main() {
    scanf("%d%d%d",&N,&K,&M);
    int p[K];
    for (int i = 1; i <= K; i++)
    {
        scanf("%d",&p[i]);
    }

    while (M--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        U[a].id = a;
        if (c > -1) {
            U[a].show = true;
        } else {
            c = 0;
        }
        U[a].score[b] = max(U[a].score[b],c);
    }

    for (int i = 1; i <= N; i++)
    {
        if (U[i].show) {
            for (int j = 1; j <= K; j++)
            {
                if (U[i].score[j] == -1) continue;
                U[i].totalScore += U[i].score[j];
                if (U[i].score[j] == p[j]) U[i].perfect++;
            }
        }
    }
    sort(U+1,U+N+1,cmp);
    for (int i = 2; i <= N; i++)
    {
        U[i].rank = U[i].totalScore != U[i-1].totalScore ? i:U[i-1].rank;
    }
    
    for (int i = 1; i <= N; i++)
    {
        if (!U[i].show) continue;
        printf("%d %05d %d",U[i].rank,U[i].id,U[i].totalScore);
        for (int j = 1; j <= K; j++)
        {
            if (U[i].score[j] > -1) 
                printf(" %d",U[i].score[j]);
            else
                printf(" -");
        }
        printf("\n");
    }
    return 0;
}