/*
 * 
*/

#include<iostream>
#include<string>

using namespace std;

string s;
string permutation="";
int L;
bool used[8]={0};

void Permutation(int n){
    if (n==L){
        cout<<permutation<<endl;
        return;
    }

    for (int i = 0; i < L; ++i)
    {
        if (!used[i]){
            permutation.replace(n,1,1,s[i]);
            used[i]=true;
            Permutation(n+1);
            used[i]=false;
        }
    }
}

int main(){
    cin>>s;
    L=s.length();
    Permutation(0);
    return 0;
}