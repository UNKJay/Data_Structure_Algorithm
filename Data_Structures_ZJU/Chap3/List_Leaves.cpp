#include<iostream>
#include<queue>

#define MAX_TREE 10
#define Null -1
using namespace std;

struct Tree_Node{
    int left;
    int right;
} T[MAX_TREE];

int Build_Tree(struct Tree_Node T[]){
    int N;
    int Root = Null;
    cin>>N;
    if (N) {
        int flag[MAX_TREE];
        for (int i=0; i<N; i++) flag[i] = 0;
        for (int i = 0; i < N; i++)
        {
            char cl,cr;
            cin>>cl;
            cin.get();  cr = cin.get();
            if (cl != '-') {
                T[i].left = cl - '0';
                flag[T[i].left] = 1;
            } else
                T[i].left = Null;

            if (cr != '-') {
                T[i].right = cr - '0';
                flag[T[i].right] = 1;
            } else 
                T[i].right = Null;
        }
        for (int i = 0; i < N; i++)
        {
            if (flag[i] == 0) {
                Root = i;
                break;
            }
        }
    }
    return Root;
}

void Print_Leaves(int Root) {
    queue<int> q;
    q.push(Root);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        if (T[tmp].left != Null ) q.push(T[tmp].left);
        if (T[tmp].right != Null) q.push(T[tmp].right);
        if (T[tmp].left == Null && T[tmp].right == Null){
            cout<<tmp;
            if (!q.empty()) cout<<' ';
        }
    }
    cout<<endl;
}

int main(){
    int Root = Build_Tree(T);
    Print_Leaves(Root);
    return 0;
}