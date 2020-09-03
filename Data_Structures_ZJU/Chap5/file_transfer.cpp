#include<iostream>

#define MAXSIZE 10001
using namespace std;

typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXSIZE];

void Initiallization(SetType S, int N) {
    for (int i = 0; i < N; i++)
    {
        S[i] = -1;
    }
}

SetName Find(SetType S, ElementType X) {        //路径压缩
    // for (; S[X] >= 0; X=S[X])        普通
    // return X;
    if (S[X] < 0) return X;
    return S[X] = Find(S,S[X]);         //路径压缩
}

void Union(SetType S, SetName root1, SetName root2) {
    if (root1 == root2) return ;        //different
    if (S[root1] < S[root2]) {       //root1节点多
        S[root1] += S[root2];
        S[root2] = root1;
    } else {
        S[root2] += S[root1];
        S[root1] = root2;
    }
}

void InputConnection(SetType S) {
    ElementType u,v;
    cin>>u>>v;
    SetName root1 = Find(S,u-1);
    SetName root2 = Find(S,v-1);
    Union(S,root1,root2);
}

void CheckConnection(SetType S) {
    ElementType u,v;
    cin>>u>>v;
    SetName root1 = Find(S,u-1);
    SetName root2 = Find(S,v-1);
    if (root1 == root2) 
        cout<<"yes"<<endl;
    else 
        cout<<"no"<<endl;
}

void CheckNetWork(SetType S, int N) {
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] < 0) count++;
    }
    if (count == 1) 
        cout<<"The network is connected."<<endl;
    else 
        cout<<"There are "<<count<<" components."<<endl;
}

int main() {
    SetType S;
    int N;
    cin>>N;
    char in;
    Initiallization(S,N);

    do {
        cin>>in;
        switch (in)
        {
        case 'C':
            CheckConnection(S);
            break;
        
        case 'I':
            InputConnection(S);
            break;

        case 'S':
            CheckNetWork(S,N);
            break;
        }
    } while (in != 'S');
    return 0;
}