#include <iostream>

using namespace std;

int f(int m,int n) {
    if (n>m)
        return f(m,m);
    if (m == 0)
        return 1;
    if (n == 0)
        return 0;
    return f(m-n,n)+f(m,n-1);
}

int main(){
    int m,n,t;
    cin>>t;
    while (t--)
    {
        cin>>m>>n;
        cout<<f(m,n)<<endl;
    }
    return 0;
}