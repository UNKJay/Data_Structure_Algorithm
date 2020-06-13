#include<iostream>
#include<stack>
using namespace std;

int main(){
    int M,N,K;
    cin>>M>>N>>K;

    while (K--)
    {
        int val[N];
        stack<int> sta;
        for (int i = 0; i < N; i++)
        {
            cin>>val[i];
        }
        
        int p=0;
        bool flag=false;
        for (int i = 0; i < N; i++)
        {
            if (sta.size()<M) {
                sta.push(i+1);
            } else {
                flag=true;
                break;
            }
            
            while (!sta.empty() && (sta.top() == val[p])) {
                sta.pop();
                p++;
            }
        }
        if (flag)
            cout<<"NO"<<endl;
        else if (sta.empty())
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
        
    }
    
    return 0;
}