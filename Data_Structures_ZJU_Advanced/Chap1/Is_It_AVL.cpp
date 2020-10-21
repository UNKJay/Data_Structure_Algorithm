#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct TreeNode* Tree;
struct TreeNode {
    int height = 1;
    Tree left = nullptr, right = nullptr;
};

bool check();
Tree MakeTree(int root, int num);

int K,N;
int Node[35];
bool flag = true;

int main() {
    cin>>K;
    while (K--) {
        cin>>N;
        for (int i = 0; i < N; i++)
        {
            cin>>Node[i];
        }
        flag = true;
        cout<<(check()?"Yes":"No")<<endl;
    }
    return 0;
}

bool check() {
    Tree root = MakeTree(0,N);
    return flag;
}

Tree MakeTree(int root, int num) {
    if (num == 0) return nullptr;
    else if (num == 1) {
        Tree R = new TreeNode;
        return R;
    }

    int i = 0;
    int height1 = 0, height2 = 0;
    for (; Node[root+i] <= Node[root] && i <= (num -1); i++) {}
    Tree R = new TreeNode;
    Tree Left = MakeTree(root+1,i-1);
    Tree Right = MakeTree(root+i, num-i);
    R->left = Left;
    R->right = Right;
    if (Left) height1 = Left->height;
    if (Right) height2 = Right->height;
    R->height = (height1 > height2) ? height1 + 1: height2 + 1;
    if (height1 - height2 >= 2 || height1 - height2 <= -2) flag = false;
    return R;
}