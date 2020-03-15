#include <iostream>

using namespace std;
int way(int n,int i) {
    if (n == 0)
        return 1;
    if (i == 0 )
        return 0;
    if (i>n)
        return way(n,n);
    return way(n-i,i)+way(n,i-1);
}

int main() {
    int n;
    while(cin>>n)
        cout<<way(n,n)<<endl;
    return 0;
}