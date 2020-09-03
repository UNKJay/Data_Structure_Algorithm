#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;


// 以下为直接根据前序和中序得到后序

int GetNum( const string &s );
void GivePostOrder( int pre_left, int in_left, int post_left, int n);

vector<int> pre_order;
vector<int> in_order;
vector<int> post_order;
stack<int> sta;             //辅助
int N;


int main() {
    cin>>N;
    cin.get();
    post_order.assign(N,0);
    string s;
    for (int i = 0; i < 2*N; i++)
    {
        getline(cin,s);
        if (s[1] == 'o') {  //pop
            int temp = sta.top();
            sta.pop();
            in_order.push_back(temp);
        } else {            //push
            int temp = GetNum(s);
            pre_order.push_back(temp);
            sta.push(temp);
        }
    }
     GivePostOrder(0,0,0,N);
     cout<<post_order[0];
     for (int i = 1; i <= N-1; i++)
     {
         cout<<" "<<post_order[i];
     }
     cout<<endl;
    return 0;
}

int GetNum (const string &s) {
    istringstream is(s.substr(5));
    int num;
    is>>num;
    return num;
}

void GivePostOrder( int pre_left, int in_left, int post_left, int n) {
    if (n == 0) return ;
    if (n == 1) {
        post_order[post_left] = pre_order[pre_left];
        return ;
    }
    int root = pre_order[pre_left];
    post_order[post_left + n -1] = root;

    int i;
    for (i = 0; i < n; i++) {
        if (in_order[in_left + i] == root) break;
    }

    int left_length = i;
    int right_length = n - left_length - 1;
    GivePostOrder( pre_left + 1, in_left, post_left, left_length);
    GivePostOrder( pre_left + left_length + 1, in_left + left_length + 1, post_left + left_length , right_length);
}



/* 以下为构建新树的做法
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
*/