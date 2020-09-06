// 注意取模运算后，每一个都要自己模拟走一遍

#include<iostream>

using namespace std;

int ans[5];

bool contain7(int num) {
    while (num)
    {
        if ((num % 10) == 7){
            return true;
        }
        num /= 10;
    }
    return false;
}

int main() {
    int n;
    int calledNum = 0;
    int callingNum = 1;
    cin>>n;
    for (int i = 1; i < 5; i++)
    {
        ans[i]=0;
    }
    while (calledNum < n)
    {
        if ((callingNum % 7 == 0 ) || contain7(callingNum)) {
            ans[(callingNum++)%4]++;
        }
        else
        {
            ++callingNum;
            ++calledNum;
        }
    }
    
    for (int i = 1; i < 4; i++)
    {
        cout<<ans[i]<<endl;
    }
    cout<<ans[0]<<endl;
    return 0;
}