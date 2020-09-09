#include<cstdio>
#include<vector>

using namespace std;

int main() {
    long long int sum = 0;
    int n,a,b;
    int index,value;
    scanf("%d%d%d",&n,&a,&b);

    vector<pair<int,int>> A;
    for (int i = 0; i < a; i++)
    {
        scanf("%d%d",&index,&value);
        A.push_back(make_pair(index,value));
    }

    int i = 0;
    for (int j = 0; j < b; j++)
    {
        scanf("%d%d",&index,&value);
        while (i<a) {
            if (A[i].first > index) break;
            else if (A[i].first < index) {
                i++;
            } else {
                sum += A[i].second * value;
                i++;
            }
        }
    }
    printf("%lld\n",sum);
    return 0;
}