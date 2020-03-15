#include <iostream>
#include <string>

using namespace std;

string s;
int ptr;
bool factor();
bool item();
bool notExpr();
bool expr();

bool expr() {
    bool result = item();
    while (s[ptr] == '|')
    {
        ++ptr;
        result = result | item();
    }
    return result;
}

bool item() {
    bool result = factor();
    while (s[ptr]=='&')
    {
        ++ptr;
        result = result & factor();
    }
    return result;
}

bool notExpr() {
    bool result;
    switch (s[ptr])
    {
    case 'V':
        ++ptr;
        return false;
        break;
    
    case 'F':
        ++ptr;
        return true;
        break;

    case '!':
        ++ptr;
        return !notExpr();
        break;

    case '(':
        ++ptr;
        result = expr();
        ++ptr;
        return !result;
        break;
    }
}

bool factor() {
    bool result;
    switch (s[ptr])
    {
    case 'V':
        ++ptr;
        return true;
        break;
    
    case 'F':
        ++ptr;
        return false;
        break;

    case '!':
        ++ptr;
        return notExpr();
        break;

    case '(':
        ++ptr;
        result = expr();
        ++ptr;
        return result;
        break;
    }
}



int main() {
    int t=1;
    while (getline(cin,s))
    {
        ptr=0;
        int index = 0;
        while ((index = s.find(' ' , index)) != string::npos)
            s.erase(index,1);
        
        bool result =  expr();
        if (result)
            cout<<"Expression "<<t++<<": V"<<endl;
        else
            cout<<"Expression "<<t++<<": F"<<endl;
    }
    
    return 0;
}