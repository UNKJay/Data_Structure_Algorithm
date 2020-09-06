#include<iostream>

using namespace std;

int main() {
    
    int r,y,g;
    int n;
    cin>>r>>y>>g>>n;

    int result = 0;
    int option,time;
    while (n--)
    {
        cin>>option>>time;
        switch (option)
        {
        case 0:
            result += time;
            break;
        
        case 1:
            result += time;
            break;

        case 2:
            result += (time + r);
            break;
    
        default:
            break;
        }
    }
    cout<<result<<endl;
    return 0;
}