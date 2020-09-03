#include<iostream>
#include<string>
using namespace std;

int KMP();
void BuildMatch(int match[]);

string str, pattern;

int main() {
    int result;
    int N;
    cin>>str;
    cin>>N;
    while (N--) {
        cin>>pattern;
        result = KMP();
        if (result == -1) {
            cout<<"Not Found"<<endl;
        } else {
            cout<<str.substr(result)<<endl;
        }
    }
    return 0;
}

int KMP() {
    int n = str.length();
    int m = pattern.length();
    if (n<m) return -1;
    int s,p;
    int * match = new int[m];

    BuildMatch(match);
    s = p = 0;
    while (s<n && p<m) {
        if (str[s] == pattern[p]) {s++; p++;}
        else if (p > 0) p = match[p-1] + 1;
        else s++;
    }
    return (p==m)?(s-m):-1;
}

void BuildMatch(int match[]) {
    match[0] = -1;
    int m = pattern.length();
    for (int i = 1; i<m; i++) {
        int j = match[i-1];
        while (j >= 0 && pattern[j+1] != pattern[i]) 
            j = match[j];
        if (pattern[j+1] == pattern[i])
            match[i] = j+1;
        else match[i] = -1;
    }
}