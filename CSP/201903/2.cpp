// 易错点
// 读题， x 代表 *

#include<iostream>
#include<cstring>

using namespace std;

int expression_value();
int term_value();
int factor_value();

int main() {
    int n;
    cin>>n;
    while (n--) {
        cin.get();
        cout<< ((expression_value() == 24) ? "Yes" : "No") << endl;
    }
    return 0;
}

int expression_value() {
    int result = term_value();
    while (true) {
        char c = cin.peek();
        if (c == '+' || c == '-') {
            cin.get();
            int value = term_value();
            if (c == '+') {
                result += value;
            } else {
                result -= value;
            }
        } else {
            break;
        }
    }
    return result;
}

int term_value() {
    int result = factor_value();
    while (true)
    {
        char c = cin.peek();
        if (c == 'x' || c == '/') {
            cin.get();
            int value = factor_value();
            if (c == 'x') {
                result *= value;
            } else
            {
                result /= value;
            }
        } else
        {
            break;
        }
    }
    return result;
}

int factor_value() {
    char c = cin.peek();
    int result = 0;
    if (c == '(') {
        cin.get();
        result = expression_value();
        cin.get();
    } else {
        while (isdigit(c))
        {
            cin.get();
            result = result * 10 + c - '0';
            c = cin.peek();
        }
    }
    return result;
}