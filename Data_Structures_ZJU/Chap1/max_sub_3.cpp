/*
    为ZJU mooc 修改
    注意特殊情况，如全为负数;最高值为0
*/

#include<iostream>

using namespace std;

int main(){

    int N;
    cin>>N;
    int *array=new int[N];

    for (int i=0;i<N;i++)
        cin>>array[i];
        
    int sum=0,maxSum=0,max;
    int currentLow=0,currentHigh=0;
    int low=0,high=0;

    max=array[0];
    for (int i = 0; i < N; i++)
    {
        if (array[i]>max)
            max=array[i];

        sum+=array[i];
        currentHigh=i;
        if (sum<0){
            sum=0;
            currentLow=i+1;
        }
        else if (sum>maxSum)
        {
            maxSum=sum;
            low=currentLow;
            high=currentHigh;
        }
    }

    if (max<0)
        high=N-1;
    if (max==0)
        cout<<0<<" "<<0<<" "<<0;
    else
        cout<<maxSum<<" "<<array[low]<<" "<<array[high]<<endl;
    delete []array;
    return 0;
}