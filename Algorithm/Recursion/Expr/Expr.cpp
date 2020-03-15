#include <iostream>
#include <cstring>

using namespace std;

int expression_value();     //求一个表达式的值
int term_value();           //求一个项的值
int factor_value();         //求一个因子的值

int main(){
    cout<<expression_value()<<endl;
    return 0;
}

int expression_value(){
    int result = term_value();      //求第一项的值
    while (true)
    {
        char op = cin.peek();       //查看一个字符不取走
        if (op == '+' || op == '-'){
            cin.get();              //取走字符
            int value = term_value();
            if (op == '+'){
                result += value;
            }
            else {
                result -= value;
            }
        }
        else {
            break;
        }
    }
    return result;
}

int term_value() {
    int result = factor_value();      //求第一个因子的值
    while (true)
    {
        char op = cin.peek();       //查看一个字符不取走
        if (op == '*' || op == '/'){
            cin.get();              //取走字符
            int value = factor_value();
            if (op == '*'){
                result *= value;
            }
            else {
                result /= value;
            }
        }
        else {
            break;
        }
    }
    return result;
}

int factor_value() {
    int result = 0;
    char c = cin.peek();
    if (c == '(') {
        cin.get();
        result = expression_value();
        cin.get();
    }
    else {
        while (isdigit(c))
        {
            cin.get();
            result = result * 10 + c - '0';
            c = cin.peek();
        }
    }
    return result;
}