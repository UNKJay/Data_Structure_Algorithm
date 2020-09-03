#include<iostream>
#include<string>

#define MAXSIZE 64
#define MINH -1

using namespace std;


typedef struct TreeNode* HuffmanTree;
typedef HuffmanTree ElementType;
typedef struct HeapStruct* MinHeap;
typedef struct JudgeNode* JudgeTree;

struct TreeNode {
    int weight;
    HuffmanTree left = nullptr, right = nullptr;
};

struct HeapStruct {
    ElementType Elements[MAXSIZE];
    int size = 0;
};


struct JudgeNode {
    int flag = 0;
    JudgeTree left = nullptr , right = nullptr;
};

MinHeap Create();
void Insert( MinHeap H ,ElementType X);
ElementType Delete (MinHeap H);
int WPL(HuffmanTree T, int level);
bool Judge(string s, JudgeTree J);

int main() {
    int N , value[MAXSIZE];
    cin>>N;
    MinHeap H = Create();

    for (int i = 0; i < N; i++)
    {
        char ch;
        int x;
        cin>>ch;
        ElementType X = new struct TreeNode;
        cin>>x;
        X->weight = x;
        value[i] = x;
        Insert(H,X);
    }
    
    for (int i=0; i<N-1; i++) {
        ElementType X = new struct TreeNode;
        X->left = Delete(H);
        X->right = Delete(H);
        X->weight = X->left->weight + X->right->weight;
        Insert(H,X);
    }

    int M;
    cin>>M;

    int code_len = WPL(H->Elements[1] , 0);
    
    
    while (M--)
    {
        bool result = true;
        int count = 0 ;
        char c;
        string s;
        JudgeTree J = new struct JudgeNode;
        for (int i = 0; i<N; i++) {
            cin>>c>>s;
            count += value[i] * s.length();
            if (result) {
                result = Judge(s,J);
            }
        }
        delete J;
        if (result && count == code_len)
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
    return 0;
}

MinHeap Create() {
    MinHeap H = new struct HeapStruct;
    H->Elements[0] = new struct TreeNode; 
    H->Elements[0]->weight = MINH;
    return H;
}

void Insert( MinHeap H ,ElementType X) {
    int i = ++(H->size);
    for ( ; H->Elements[i/2]->weight > (X->weight) ; i=i/2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = X;
}

ElementType Delete( MinHeap H) {
    ElementType min_item = H->Elements[1];
    ElementType tmp = H->Elements[H->size--];
    int parent = 1, child;
    for ( ; parent*2 <= H->size ; parent = child) {
        child = parent * 2;
        if ((child != H->size) && (H->Elements[child]->weight > H->Elements[child+1]->weight))          //bug在这，一定要慎用指针，前面没有加weight
            child++;
        if (tmp->weight <= H->Elements[child]->weight) break;               
        H->Elements[parent] = H->Elements[child];
    }
    H->Elements[parent] = tmp;
    return min_item;
}

int WPL(HuffmanTree T, int level) {
    if (!T->right) return T->weight * level;
    else return WPL(T->left , level + 1) + WPL(T->right , level + 1);
}

bool Judge(string s, JudgeTree J) {
    int i = 0;
    for ( ; i<s.length(); i++) {
        if (s[i] == '0') {
            if (J->left == nullptr) {
                J->left = new struct JudgeNode;
            } else if (J->left->flag == 1) {
                return false;
            }
            J = J->left;
        } else {
            if (J->right == nullptr) {
                J->right = new struct JudgeNode;
            } else if (J->right->flag == 1) {
                return false;
            }
            J = J->right;
        }
    }
    J->flag = 1;
    if (J->left == nullptr && J->right == nullptr)
        return true;
    else 
        return false;
}