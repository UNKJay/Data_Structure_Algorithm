#include<cstdio>
#include<algorithm>

using namespace std;

int N;
int Position[100005];

int main() {
    int result = 0,a;

    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&a);
        Position[a] = i;
    }

    int index = 1;
    while (true) {
        while (Position[0] != 0) {
            swap(Position[0],Position[Position[0]]);
            result++;
        }

        for (; index<N; index++) {
            if (Position[index] != index) {
                swap(Position[0],Position[index]);
                result++;
                break;
            }
        }

        if (index == N)
            break;
    }
    
    printf("%d\n",result);
    return 0;
}