#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;

    int prime[10000];
    int num=1;
    prime[num++] = 2;
    for (int i=3; i<=n; i++) {
        int flag=0;
        for (int j = 1; j < num; j++)
        {
            if (i % prime[j] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            prime[num++] = i;
        }   
    }

    int total=0;
    for (int i = 1; i < num-1; i++)
    {
        if (prime[i+1]-prime[i] == 2)
            total++;
    }
    cout<<total<<endl;
    return 0;
}