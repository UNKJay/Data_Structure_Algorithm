#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int N,M;
    int sum = 0;
    int largest_id=0,largest_num=0;

    cin>>N>>M;

    int init_num;
    for (int i = 1; i <= N; i++)
    {
        cin>>init_num;
        sum += init_num;

        int drop_num,total_num=0;
        for (int j = 0; j < M; ++j)
        {
            cin>>drop_num;
            total_num += abs(drop_num);
        }

        sum -= total_num;
        largest_id = (total_num>largest_num)?i:largest_id;
        largest_num = (total_num>largest_num)?total_num:largest_num;
    }
    cout<<sum<<" "<<largest_id<<" "<<largest_num<<endl;
    return 0;
}