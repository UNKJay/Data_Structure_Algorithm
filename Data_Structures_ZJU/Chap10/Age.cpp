#include<cstdio>

using namespace std;

int N;
int age[51];

int main() {
    int a;
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&a);
        age[a]++;
    }
    for (int i = 0; i < 51; i++)
    {
        if (age[i] != 0) {
            printf("%d:%d\n",i,age[i]);
        }
    }
    return 0;
}