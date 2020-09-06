#include<iostream>
#include<vector>

using namespace std;


int main() {
    int n;
    int sum = 0;
    vector<int> result(1000000,0);
    cin>>n;
    for (int i = 0; i < 2*n; i++)
    {
        int a,b;
        cin>>a>>b;
        for (int j = a; j < b; j++)
        {
            result[j]++;
        }
    }
    for (int i = 0; i < 1000000; i++)
    {
        if (result[i]>1) {
            ++sum;
        }
    }
    cout<<sum<<endl;
    return 0;
}