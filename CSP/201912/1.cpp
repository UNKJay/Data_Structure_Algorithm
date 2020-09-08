#include<cstdio>

using namespace std;

bool contain7(int i) {
    int j;
    while (i) {
        j = i % 10;
        if (j == 7) return true;
        else i = i/10;
    }
    return false;
}

int main() {
    int n,i=1;
    int count = 0;
    int skip[5] = {0};
    scanf("%d",&n);
    while (count != n) {
        if (i % 7 == 0 || contain7(i)) {
            skip[i%4]++;
            i++;
            continue;
        } else {
            count++;
            i++;
        }
    }
    skip[4] = skip[0];
    for (int i = 1; i < 5; i++)
    {
        printf("%d\n",skip[i]);
    }
    return 0;
}