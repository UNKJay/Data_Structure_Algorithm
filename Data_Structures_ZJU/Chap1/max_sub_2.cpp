#include<iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int *List=new int[N];
    for (int i=0;i<N;i++)
        cin>>List[i];
    
    int sum=0,MaxSub=0;
    for (int i = 0; i < N; i++)
    {
        sum+=List[i];
        if (sum<0)
            sum=0;
        else if (sum>MaxSub)
            MaxSub=sum;
    }
    cout<<MaxSub<<endl;
    delete []List;
    return 0;
}