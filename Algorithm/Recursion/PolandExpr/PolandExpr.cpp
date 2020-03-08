#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

double expr(){
    char s[10];
    cin>>s;
    switch (s[0])
    {
    case '+':
        return expr()+expr();
        break;
    
    case '-':
        return expr()-expr();
        break;

    case '*':
        return expr()*expr();
        break;

    case '/':
        return expr()/expr();
        break;

    default:
        return atof(s);
        break;
    }
}

int main(){
    cout<<fixed<<setprecision(6)<<expr()<<endl;
    return 0;
}