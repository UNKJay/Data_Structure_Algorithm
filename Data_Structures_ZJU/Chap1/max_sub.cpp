#include <iostream>

using namespace std;

int Max3(int a,int b,int c){
    return a>b?a>c?a:c:b>c?b:c;
}

int DivideAndConquer(int List[], int left, int right){

    if (left==right)        //end position
        return List[left]>0?List[left]:0;

    int center;
    int MaxLeftSum,MaxRightSum;
    
    center=(left+right)/2;
    MaxLeftSum=DivideAndConquer(List,left,center);
    MaxRightSum=DivideAndConquer(List,center+1,right);

    int MaxLeft=0,SumLeft=0;
    for (int i = center; i >=left ; i--)
    {
        SumLeft+=List[i];
        if (SumLeft>MaxLeft)
            MaxLeft=SumLeft;
    }
    
    int MaxRight=0,SumRight=0;
    for (int i = center+1; i <=right ; i++)
    {
        SumRight+=List[i];
        if (SumRight>MaxRight)
            MaxRight=SumRight;
    }

    return Max3(MaxRightSum,MaxLeftSum,MaxLeft+MaxRight);
}

int main(){
    int N;
    cin>>N;
    int *List=new int[N];
    for (int i = 0; i < N; i++)
        cin>>List[i];
    
    cout<<DivideAndConquer(List,0,N-1)<<endl;
    delete []List;
    return 0;
}