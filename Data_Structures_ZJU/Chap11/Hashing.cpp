#include<cstdio>

using namespace std;

const int MAX = 100005;

int N,M;
bool prime[MAX];

void FindPrime() {
    prime[0] = prime[1] = true;
    for (int i = 2; i < MAX; i++)
    {
        if (!prime[i])
            for (int j = i+i; j<MAX; j+=i) 
                prime[j] = true;
    }
}

int main() {
    int a,position;
    scanf("%d%d",&M,&N);
    FindPrime();
    
    while(prime[M])
        M++;

    int table[M] = {0};         // Hash Table
    for (int j=0; j<N; j++) {
        scanf("%d",&a);
        position = a % M;
        for (int i = 1; i<=M && table[position] != 0; position = (a + i*i) % M,i++) ;       // 这里是a

        if (table[position] == 0) {
            table[position] = a;
            printf("%s%d",j>0?" ":"",position);
        } else {
            printf("%s-",j>0?" ":"");
        }
    }
    printf("\n");
    return 0;
}