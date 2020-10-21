#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
    int n,l,t;
    scanf("%d%d%d",&n,&l,&t);
    int location[105];
    int velocity[105];
    int axis[1005] = {0};
    fill(velocity,velocity+n,1);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&location[i]);
        axis[location[i]]++;
    }
    
    while (t--)
    {
        for (int i = 0; i < n; i++)
        {
            axis[location[i]]--;
            location[i] += velocity[i];
            axis[location[i]]++;
            if (location[i] == 0 || location[i] == l) {
                velocity[i] = -velocity[i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (axis[location[i]] == 2) {
                velocity[i] = -velocity[i];
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ",location[i]);
    }
    printf("\n");
    return 0;
}