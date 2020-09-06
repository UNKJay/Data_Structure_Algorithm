// 二维数组 vector 的写法好好学习

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
    int n;
    cin>>n;
    vector<vector<int>> bin(n,vector<int>(2));
    vector<int> result(5,0);

    for (int i = 0; i < n; i++)
    {
        cin>>bin[i][0]>>bin[i][1];
    }

    for (int i = 0; i < n; i++)
    {
        int score = 0;
        int orthgonal = 0;
        for (int j = 0; j < n; j++)
        {
            int x = abs(bin[i][0]-bin[j][0]);
            int y = abs(bin[i][1]-bin[j][1]);
            if ( x + y == 1) {
                ++orthgonal;
            }
            if ( x * y == 1) {
                ++score;
            }
        }
        if (orthgonal == 4) {
            result[score]++;
        }
    }
    for(int v:result) {
        cout<<v<<endl;
    }   
}