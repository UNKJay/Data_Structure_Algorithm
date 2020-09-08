#include<cstdio>

using namespace std;

int main() {
    
    int r,y,g;
    int n;
    scanf("%d%d%d%d",&r,&y,&g,&n);

    int result = 0;
    int option,time;
    while (n--)
    {
        scanf("%d%d",&option,&time);
        switch (option)
        {
        case 0:
            result += time;
            break;
        
        case 1:
            result += time;
            break;

        case 2:
            result += (time + r);
            break;
    
        default:
            break;
        }
    }
    printf("%d\n",result);
    return 0;
}