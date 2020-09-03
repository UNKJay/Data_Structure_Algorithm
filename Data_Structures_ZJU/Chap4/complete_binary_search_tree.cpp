#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int a[1010],t[1010];

int getLeftLength(int n) {
    int height = (int) log2(n+1);               //完全二叉树的高度，除去叶子
    int X = n + 1 - (int)pow(2,height);         //叶子数量
    X = (X > (int)pow(2,height-1))?(int)pow(2,height-1):X;      //左子树的叶子数量
    return (int)pow(2,height-1)-1+X;
}

void solve(int a_left, int a_right, int t_root ) {
    int length = a_right - a_left + 1;
    if (length == 0) return;
    int l = getLeftLength(length);
    t[t_root] = a[l+a_left];
    int left_root = t_root * 2 + 1;             //0..N-1的情况
    int right_root = left_root + 1;
    solve(a_left, a_left+l-1, left_root);
    solve(a_left+l+1,a_right, right_root);
}

int main() {
    int N;
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    sort(a,a+N);
    solve(0,N-1,0);
    for (int i = 0; i < N; i++)
    {
        if (i) cout<<" ";
        cout<<t[i];
    }
    cout<<endl;
    return 0;
}