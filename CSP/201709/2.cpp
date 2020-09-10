#include<cstdio>
#include<queue>

using namespace std;

struct Key{
    int index;      //钥匙编号
    int time;       //当前时间点
    bool flag;      // true:还   false:借
    Key(int _i, int _t, bool _f):index(_i),time(_t),flag(_f) {}
    bool operator< (const Key & k) const {
        if (this->time != k.time)
            return this->time > k.time;
        else if (this->flag != k.flag)
            return !(this->flag);
        else 
            return this->index > k.index;
    }
};

/*
struct cmp {
    bool operator() (Key k1, Key k2) {
        if (k1.time != k2.time) {
            return k1.time > k2.time;
        } else if (k1.flag != k2.flag) {
            return !k1.flag;
        } else 
            return k1.index > k2.index;
    }
};
*/

int main() {
    int N,K;
    int w,s,c;
    int loc[1005];          //位置存放的钥匙编号
    //priority_queue<Key,vector<Key>,cmp> q;
    priority_queue<Key> q;
    scanf("%d%d",&N,&K);
    for (int i = 1; i <= N; i++)
    {
        loc[i] = i;
    }
    
    for (int i = 0; i < K; i++)
    {
        scanf("%d%d%d",&w,&s,&c);
        q.push(Key(w,s,false));
        q.push(Key(w,s+c,true));
    }
    while (!q.empty()) {
        Key k = q.top();
        q.pop();
        if (k.flag) {
            int i = 1;
            while (loc[i] != -1) i++;
            loc[i] = k.index;
        } else {
            int i = 1;
            while (loc[i] != k.index) i++;
            loc[i] = -1;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (i>1) printf(" ");
        printf("%d",loc[i]);
    }
    printf("\n");
    return 0;
}