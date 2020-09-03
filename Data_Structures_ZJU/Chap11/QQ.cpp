#include<iostream>
#include<map>

using namespace std;

int N;
map<string, string> M;

int main() {
    char c;
    string name,password;
    cin>>N;
    while (N--) {
        cin >> c>>name>>password;
        switch (c)
        {
        case 'L':
            if (M.find(name) == M.end()) 
                cout<<"ERROR: Not Exist"<<endl;
            else if (M[name] != password) 
                cout<<"ERROR: Wrong PW"<<endl;
            else 
                cout<<"Login: OK"<<endl;
            break;
        
        case 'N':
            if (M.find(name) == M.end()) {
                cout<<"New: OK"<<endl;
                M[name] = password;
            } else 
                cout<<"ERROR: Exist"<<endl;
            break;
        }
    }
    return 0;
}