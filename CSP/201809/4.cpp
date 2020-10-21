#include<cstdio>
#include<set>
#include<vector>
#include<unordered_map>

using namespace std;

struct commodity
{
    long long id;
    int score;
    commodity(long long _i , int _s):id(_i),score(_s) {}
    bool operator< (const commodity& c) const{
        return this->score != c.score ? this->score > c.score : this->id < c.id;
    }
}; 

int main() {
    const long long mul = (long long) (1e9);
    long long a;
    int m,n,id,score,OPNum,c,t,total;
    vector<int> K(m);
    set<commodity> commodities;
    unordered_map<long long , set<commodity>::iterator> um;
    scanf("%d%d",&m,&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&id,&score);
        for (int j = 0; j < m; j++)
        {
            a = j * mul + id;
            um[a] = commodities.insert(commodity(a,score)).first;
        }
    }

    scanf("%d",&OPNum);
    while (OPNum--) {
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            scanf("%d%d%d",&t,&id,&score);
            a = t * mul + id;
            um[a] = commodities.insert(commodity(a,score)).first;
            break;
        
        case 2:
            scanf("%d%d",&t,&id);
            a = t * mul + id;
            commodities.erase(um[a]);
            um.erase(a);
            break;

        case 3:
            vector<vector<int>> ans(m);
            scanf("%d",&total);
            for (int i = 0; i < m; i++)
            {
                scanf("%d",&K[i]);
            }
            for (auto i: commodities) {
                t = i.id/mul;
                if (ans[t].size() < K[t]) {
                    ans[t].push_back(i.id % mul);
                    if (--total == 0) break;
                }
            }

            for (auto i: ans) {
                if (i.empty()) {
                    printf("-1\n");
                } else {
                    for (auto j: i) {
                        printf("%d ",j);
                    }
                    printf("\n");
                }
            }
            break;
        }
    }
    return 0;
}