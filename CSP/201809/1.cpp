#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> init(n);
    for (int i = 0; i < n; i++)
    {
        cin>>init[i];
    }
    vector<int> result(n);
    for (int i = 1; i < n-1; i++)
    {
        result[i] = floor((init[i-1] + init[i] + init[i+1])/3.0);
    }
    result[0] = floor((init[0]+init[1])/2.0);
    result[n-1] = floor((init[n-2]+init[n-1])/2.0);
    for (int i = 0; i < n-1; i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<result[n-1]<<endl;
    return 0;
}