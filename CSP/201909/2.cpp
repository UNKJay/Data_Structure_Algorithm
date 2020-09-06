#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
    int N,M;
    int sum = 0;
    int init_num,d=0,e=0;
    cin>>N;
    vector<bool> flag(N,false);
    for (int i = 0; i < N; i++)
    {
        cin>>M>>init_num;
        int drop_num;
        for (int j = 0; j < M-1; ++j)
        {
            cin>>drop_num;
            if (drop_num <= 0) {
                init_num += drop_num;
            } else if (init_num > drop_num) {
                flag[i] = true;
                init_num  = drop_num;
            }
        }
        sum += init_num;
        if (flag[i]) {
            d++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (flag[i] && flag[(i+1)%N] && flag[(i-1+N)%N]) {
            e++;
        }
    }
    

    cout<<sum<<" "<<d<<" "<<e<<endl;
    return 0;
}