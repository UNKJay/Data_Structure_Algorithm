#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
int origin[105];
int target[105];
int temp[105];

void Percedown(int l, int r);

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
        printf("Heap Sort\n");
        memcpy(temp,origin,sizeof(origin));
        for (int i= (N-1)/2; i>=0; i--) {
            Percedown(i,N);
        }

        for (int i = N-1; i > 0; i--)
        {
            swap(temp[0],temp[i]);
            Percedown(0,i);
            if (equal(temp,temp+N,target)) {
                swap(temp[0],temp[i-1]);
                Percedown(0,i-1);
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

void Percedown(int l, int r) {
    int x = temp[l];
    int parent, child;
    for (parent = l; parent * 2 + 1 < r; parent = child) {
        child = parent * 2 + 1;
        if (child < r-1 && temp[child]<temp[child+1])
            child++;
        if (x < temp[child]) {
            temp[parent] = temp[child];
        } else {
            break;
        }
    }
    temp[parent] = x;
}