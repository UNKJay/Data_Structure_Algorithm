#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>> h(n,vector<int>(2));
    vector<vector<int>> w(n,vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        cin>>h[i][0]>>h[i][1];
    }

    for (int i = 0; i < n; i++)
    {
        cin>>w[i][0]>>w[i][1];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (w[j][0] >= h[i][1] || w[j][1] <= h[i][0]) {
                continue;
            }

            if (w[j][0] >= h[i][0] && w[j][1] >= h[i][1]) {
                sum += (h[i][1] - w[j][0]);
                continue;
            }

            if (w[j][0] >= h[i][0] && w[j][1] <= h[i][1]) {
                sum += (w[j][1] - w[j][0]);
                continue;
            }

            if (w[j][0] <= h[i][0] && w[j][1] <= h[i][1]) {
                sum += (w[j][1] - h[i][0]);
                continue;
            }
            
            if (w[j][0] <= h[i][0] && w[j][1] >= h[i][1]) {
                sum += (h[i][1] - h[i][0]);
                continue;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}