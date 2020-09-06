#include<iostream>

using namespace std;

int main() {
    int n;
    int sum = 0;
    int last_score = 0;
    while (cin>>n)
    {
        if (n == 0 ) {
            break;
        }

        if (n == 1) {
            sum += 1;
            last_score = 1;
        }

        if (n == 2) {
            if (last_score == 1) {
                last_score = 2;
                sum += 2;
            } else {
                last_score += 2;
                sum += last_score;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}