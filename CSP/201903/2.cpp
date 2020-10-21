/* 以下为使用双栈模拟中缀表达式的求值过程
#include<iostream>
#include<map>
#include<stack>

using namespace std;

int cal(string str);

map<char,int> op;
stack<int> opNum;
stack<char> opChar;

int main() {
    op['#'] = 0;
    op['+'] = op['-'] = 1;
    op['x'] = op['/'] = 2;
    int n;
    string s;
    cin>>n;
    while (n--) {
        cin>>s;
        cout<<(cal(s) == 24?"Yes":"No")<<endl;
    }
    return 0;
}

int cal(string str) {
    int num1,num2;
    char c;
    str += '#';
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9') {
            opNum.push(str[i]-'0');
        } else {
            while (!opChar.empty() && op[str[i]] <= op[opChar.top()]) {
                c = opChar.top();
                opChar.pop();
                num1 = opNum.top();
                opNum.pop();
                num2 = opNum.top();
                opNum.pop();
                if (c == '+') opNum.push(num2+num1);
                else if (c == '-') opNum.push(num2-num1);
                else if (c == 'x') opNum.push(num2*num1);
                else if (c == '/') opNum.push(num2/num1);
            }
            opChar.push(str[i]);
        }
    }
    num1 = opNum.top();
    opNum.pop();
    opChar.pop();
    return num1;
}

*/

// 以下为转换为后缀表达式后进行求值

#include<iostream>
#include<map>
#include<stack>

using namespace std;

int cal(string str);

map<char,int> op;
stack<int> opNum;
stack<char> opChar;

int main() {
    op['+'] = op['-'] = 1;
    op['x'] = op['/'] = 2;
    int n;
    string s;
    cin>>n;
    while (n--) {
        cin>>s;
        cout<<(cal(s) == 24?"Yes":"No")<<endl;
    }
    return 0;
}

int cal(string str) {
    string post = "";// 转换为后缀表达式
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9') {
            post += str[i];
        } else {
            while (!opChar.empty() && op[str[i]] <= op[opChar.top()]) {
                post += opChar.top();
                opChar.pop();
            }
            opChar.push(str[i]);
        }
    }
    while (!opChar.empty()) {
        post += opChar.top();
        opChar.pop();
    }
    int num1,num2;
    char c;
    for (int i = 0; i < post.size(); i++)
    {
        if (post[i] >= '0' && post[i] <= '9') {
            opNum.push(post[i] - '0');
        } else {
            num1 = opNum.top();
            opNum.pop();
            num2 = opNum.top();
            opNum.pop();
            if (post[i] == '+') opNum.push(num2+num1);
            else if (post[i] == '-') opNum.push(num2-num1);
            else if (post[i] == 'x') opNum.push(num2*num1);
            else if (post[i] == '/') opNum.push(num2/num1);
        }
    }
    num1 = opNum.top();
    opNum.pop();
    return num1;
}