#include<iostream>
#include<string>
#include<stack>

using namespace std;

typedef struct Tree_Node* Tree;
struct Tree_Node {
    int data;
    Tree left;
    Tree right;
};

int Get_Num(string& s) {
    string num = s.substr(5);
    int result = 0;
    for (int i = 0; i < num.length(); i++)
    {
        result = result * 10 + num[i]-'0';
    }
    return result;
}

void Postorder(Tree& T) {
    if (T == nullptr) return ;
    Postorder(T->left);
    Postorder(T->right);
    cout<<T->data<<' ';
}

int main() {
    int N,num;  
    cin>>N;
    Tree Last_Pop = nullptr;
    int Last_Move = 1;      //0 -- pop  1 -- push
    stack<Tree> sta;
    string s;
    cin.get();
    getline(cin,s);
    num = Get_Num(s);
    Tree Root = new struct Tree_Node;
    Root->data = num;
    Root->left = nullptr;
    Root->right = nullptr;
    sta.push(Root);

    for (int i = 0; i < 2*N - 1; i++)
    {
        getline(cin,s);
        if (s.at(1) == 'o') {       //POP
            Last_Pop = sta.top();
            sta.pop();
            Last_Move = 0;
        } else {                    //Push
            num = Get_Num(s);
            Tree tmp = new struct Tree_Node;
            tmp->data = num;
            tmp->left = nullptr;
            tmp->right = nullptr;
            if (Last_Move == 1) {
                sta.top()->left = tmp;
            } else {
                Last_Pop->right = tmp;
            }
            sta.push(tmp);
            Last_Move = 1;
        }
    }
    
    Postorder(Root->left);
    Postorder(Root->right);
    cout<<Root->data<<endl;
    return 0;
}