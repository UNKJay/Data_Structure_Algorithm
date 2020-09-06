#include<iostream>
#include<string>

using namespace std;

int N;
string pre,in;

int Height(int preRoot, int inLeft, int size);

int main() {
    cin>>N;
    cin>>pre>>in;
    cout<<Height(0,0, N)<<endl;
    return 0;
}

int Height(int preRoot, int inLeft, int size) {
    if (size == 0) return 0;

    int i = 0;
    for (; i<size; i++) {
        if (in[inLeft+i] == pre[preRoot]) break;
    }
    int left = Height(preRoot + 1, inLeft, i);
    int right = Height(preRoot + i + 1, inLeft + i +1, size - i -1);
    //cout<<preRoot<<" " << inRoot<<" " << size<<" "<<pre[preRoot]<<" "<<left<<" " <<right<<endl;
    return left>right?left+1:right+1;
}