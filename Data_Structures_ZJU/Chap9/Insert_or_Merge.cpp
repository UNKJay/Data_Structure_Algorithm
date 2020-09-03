#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
int origin[105];
int target[105];
int temp[105];

int main() {
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&origin[i]);
    }
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&target[i]);
    }
    memcpy(temp,origin,sizeof(origin));

    bool result = false;
    for (int i=1; i<N; i++) {
        sort(temp,temp+i+1);
        if (equal(temp,temp+N,target)) {
            result = true;
            printf("Insertion Sort\n");
            sort(temp, temp+i+2);
            break;
        }
    }

    if (!result) {
        printf("Merge Sort\n");
        memcpy(temp,origin,sizeof(origin));
        for (int i = 2; i < N; i*=2)
        {
            for (int j = 0; j < N; j+=i)
            {
                sort(temp+j, j+i < N? temp+j+i:temp+N);
            }

            if (equal(temp,temp+N,target)) {
                for (int j = 0; j < N; j+= i*2)
                {
                    sort(temp+j, j+2*i < N? temp+j+2*i:temp+N);
                }
                break;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%s%d",i>0?" ":"",temp[i]);
    }
    printf("\n");
    return 0;
}