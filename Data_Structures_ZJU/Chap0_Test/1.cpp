#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    char c;
    cin>>n;
    cin.get();
    c=cin.get();

    int line=floor(sqrt((n+1)/2));
    for (int i = 1; i < line; i++)
    {
        int space_num = i-1;
        int char_num = 2*line-1-2*space_num;
        for (int j = 0; j < space_num; j++)
        {
            cout.put(' ');
        }
        
        for (int j = 0; j < char_num; j++)
        {
            cout.put(c);
        }
        cout<<endl;
    }
    
    for (int i = 1; i <= line; i++)
    {
        int space_num = line-i;
        int char_num = 2*line-1-2*space_num;
        for (int j = 0; j < space_num; j++)
        {
            cout.put(' ');
        }
        
        for (int j = 0; j < char_num; j++)
        {
            cout.put(c);
        }
        cout<<endl;
    }
    
    cout<<n-2*line*line+1<<endl;


    return 0;
}