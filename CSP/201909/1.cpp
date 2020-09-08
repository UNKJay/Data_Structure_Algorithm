#include<cstdio>
#include<cmath>

using namespace std;

int main() {
    int N,M;
    int sum = 0;
    int largest_id=0,largest_num=0;

    scanf("%d%d",&N,&M);

    int init_num;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d",&init_num);
        sum += init_num;

        int drop_num,total_num=0;
        for (int j = 0; j < M; ++j)
        {
            scanf("%d",&drop_num);
            total_num += abs(drop_num);
        }

        sum -= total_num;
        largest_id = (total_num>largest_num)?i:largest_id;
        largest_num = (total_num>largest_num)?total_num:largest_num;
    }
    printf("%d %d %d\n",sum,largest_id,largest_num);
    return 0;
}