#include<iostream>


// 易错点
// 数据类型！！！ long long 
using namespace std;

int wait_time(long long used , int option , int initial_time);

int r,y,g;

int main() {
    int n;
    cin>>r>>y>>g>>n;

    long long result = 0;
    int option,time;
    while (n--)
    {
        cin>>option>>time;
        switch (option)
        {
        case 0:
            result += time;
            break;
    
        default:
            result += wait_time(result,option,time);
            break;
        }
    }
    cout<<result<<endl;
    return 0;
}

int wait_time(long long used , int init_option , int initial_left) {
    int now_option,now_left;
    int begin_left_time;
    switch (init_option)
    {
    case 1:
        begin_left_time = (used - initial_left + r) % (r+g+y);
        break;

    case 3:
        begin_left_time = (used - initial_left + r + g) % (r+g+y);
        break;

    default:
        begin_left_time = (used - initial_left + r + g + y) % (r+g+y);
        break;
    }

    if (begin_left_time < r) {
        now_option = 1;
        now_left = r - begin_left_time;
    } else if (begin_left_time < r+g) {
        now_option = 3;
        now_left = r+g-begin_left_time;
    } else {
        now_option = 2;
        now_left = r+g+y - begin_left_time;
    }

    switch (now_option)
        {
        case 1:
            return now_left;

        case 2:
            return now_left+r;
    
        default:
            return 0;
        }
}