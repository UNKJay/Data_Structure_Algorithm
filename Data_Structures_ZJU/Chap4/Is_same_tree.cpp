#include<iostream>

using namespace std;

typedef struct TreeNode* Tree;
struct TreeNode{
    int data;
    Tree left;
    Tree right;
    int flag;               //访问标志位
};

Tree Make_New_Node(int data) {
    Tree T = new struct TreeNode;
    T->data = data;
    T->left = T->right = nullptr;
    T->flag = 0;
    return T;
}

Tree Insert(Tree T, int data) {
    if (!T) {
        T = Make_New_Node(data);
        return T;
    }
    if (data > T->data) {
        T->right = Insert(T->right,data);
    } else {
        T->left = Insert(T->left,data);
    }
    return T;
}


Tree Make_New_Tree(int N) {
    int data;
    cin>>data;
    Tree Root = Make_New_Node(data);
    for (int i = 0; i < N-1; i++)
    {
        cin>>data;
        Insert(Root,data);
    }
    return Root;
}

int Check(Tree T,int data) {

    if (T->flag) {
        if (data > T->data) {
            return Check(T->right,data);
        } else if (data < T->data) {
            return Check(T->left,data);
        } else {
            return 0;
        }
    } else {
        if (data == T->data) {
            T->flag = 1;                //
            return 1;
        } else {
            return 0;
        }
    }
}

int Judge(Tree T, int N) {
    int data;
    int flag = 0;       //判断有没有发生不正确的情况
    cin>>data;
    if (T->data != data) {
        flag = 1;
    } else {
        T->flag = 1;        //
    }

    for (int i = 0; i < N-1; i++)
    {
        cin>>data;
        if ((!flag) && (!Check(T,data))) {flag = 1;}
    }
    if (!flag) return 1;
    else return 0;
}

void Reset(Tree T) {
    if (T->left) {
        Reset(T->left);
    }
    if (T->right) {
        Reset(T->right);
    }
    T->flag = 0;
}

void Free(Tree T) {
    if (T->left) {
        Free(T->left);
    }
    if (T->right) {
        Free(T->right);
    }
    delete T;
}

int main() {
    int N,L;
    cin>>N>>L;
    while (N)
    {
        Tree T = Make_New_Tree(N);
        for (int i = 0; i < L; i++)
        {
            cout<<(Judge(T,N)?"Yes":"No")<<endl;
            Reset(T);                   //
        }
        Free(T);
        cin>>N;
    }
    return 0;
}