#include<cstdio>
#include<cmath>

using namespace std;

struct coordinate {
    int x,y;
};

int main() {
    int n;
    scanf("%d",&n);
    coordinate bin[1005];
    int result[5] = {0};

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&bin[i].x,&bin[i].y);
    }

    for (int i = 0; i < n; i++)
    {
        int score = 0;
        int orthgonal = 0;
        for (int j = 0; j < n; j++)
        {
            int x = abs(bin[i].x-bin[j].x);
            int y = abs(bin[i].y-bin[j].y);
            if ( x + y == 1) {
                ++orthgonal;
            }
            if ( x * y == 1) {
                ++score;
            }
        }
        if (orthgonal == 4) {
            result[score]++;
        }
    }
    for(int v:result) {
        printf("%d\n",v);
    }
}