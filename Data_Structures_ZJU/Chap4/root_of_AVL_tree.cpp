#include<iostream>

using namespace std;

typedef struct TreeNode* Tree;
struct TreeNode {
    int data;
    Tree left,right;
};

Tree MakeTree(int N);       //建树
Tree NewNode(int data);     //新结点
Tree InsertTree(Tree T, int data);  //插入
int Height(Tree T);         //计算高度  
Tree LLRotation(Tree T);        //LL
Tree RRRotation(Tree T);        //RR
Tree LRRotation(Tree T);        //LR
Tree RLRotation(Tree T);        //RL

int main() {
    int N;
    cin>>N;
    Tree T = MakeTree(N);
    cout<<T->data<<endl;
    return 0;
}

Tree MakeTree(int N) {
    int data;
    cin>>data;
    Tree T = NewNode(data);

    for (int i = 0; i < N-1; i++)
    {
        cin>>data;
        T = InsertTree(T,data);
    }
    return T;
}

Tree NewNode(int data) {
    Tree T = new struct TreeNode;
    T->data = data;
    T->left = T->right = nullptr;
    return T;
}

int Height(Tree T) {
    if (!T) return 1;
    int left_height = Height(T->left);
    int right_height = Height(T->right);
    int max = left_height>right_height?left_height:right_height;
    return max+1;
}

Tree InsertTree(Tree T, int data) {
    if (!T) {
        T = NewNode(data);
    } else {
        if (data > T->data) {
            T->right = InsertTree(T->right, data);
            if (Height(T->right) - Height(T->left) == 2) {
                if (data > T->right->data) {
                    T = RRRotation(T);
                } else {
                    T = RLRotation(T);
                }
            }
        } else {
            T->left = InsertTree(T->left, data);
            if (Height(T->left) - Height(T->right) == 2) {
                if (data > T->left->data) {
                    T = LRRotation(T);
                } else {
                    T = LLRotation(T);
                }
            }
        }
    }
    return T;
}

Tree LLRotation(Tree T){
    Tree a = T;
    Tree b = T->left, br = b->right;
    b->right = a;
    a->left = br;
    return b;
}       

Tree RRRotation(Tree T) {
    Tree a = T;
    Tree b = T->right, bl = b->left;
    b->left = a;
    a->right = bl;
    return b;
}

Tree LRRotation(Tree T) {
    Tree a = T;
    Tree b = T->left;
    Tree c = b->right, cl = c->left, cr = c->right;
    c->left = b;
    c->right = a;
    b->right = cl;
    a->left = cr;
    return c;
}

Tree RLRotation(Tree T) {
    Tree a = T;
    Tree b = T->right;
    Tree c = b->left, cl = c->left, cr = c->right;
    c->left = a;
    c->right = b;
    a->right = cl;
    b->left = cr;
    return c;
}