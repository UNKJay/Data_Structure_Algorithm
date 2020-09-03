#include<iostream>

using namespace std;

long int gcd(long int a, long int b) {
    return b==0?a:gcd(b,a%b);
}

void print_rational( long int a, long int b);

int main() {
    long int a,b,c,d;
    cin>>a;
    getchar();
    cin>>b;
    getchar();
    cin>>c;
    getchar();
    cin>>d;
    char op[4] = {'+','-','*','/'};
    for (int i = 0; i < 4; i++) {
        print_rational(a,b);
        cout<<" "<<op[i]<<" ";
        print_rational(c,d);
        cout<<" = ";
        switch (op[i])
        {
        case '+':
            print_rational(a*d+b*c, b*d);
            break;
        case '-':
            print_rational(a*d-b*c, b*d);
            break;

        case '*':
            print_rational(a*c, b*d);
            break;

        default:
            print_rational(a*d, b*c);
            break;
        }
        cout<<endl;
    }
    return 0;
}

void print_rational(long int a, long int b) {
    if (b == 0) {
        cout<<"Inf";
        return;
    }

    int flag = 1;
    if (a < 0) {
        flag *= -1;
        a *= -1;
    }
    if (b < 0) {
        flag *= -1;
        a *= -1;
    }
    long int tmp = gcd(a,b);
    a = a/tmp;
    b = b/tmp;
    if (flag == -1) cout<<"(-";
    if (a > b) {
        cout<<a/b;
        if ((a % b) != 0) cout<<" "<<a%b<<"/"<<b;
    } else if (a == 0) {
        cout<<"0";
    } else if (a < b){
        cout<<a<<"/"<<b;
    } else {
        cout<<1;
    }
    if (flag == -1) cout<<")";
}