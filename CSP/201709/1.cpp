#include<cstdio>

using namespace std;

int main() {
    int N;
    scanf("%d",&N);
    N = N/10;
    printf("%d\n",N + (N/5*2) + ((N%5 >= 3)?1:0) );
    return 0;
}