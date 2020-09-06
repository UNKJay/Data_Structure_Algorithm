#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

//易错点;
// 读题读题，输出的奇怪要求

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> array(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>array[i];
    }

    int min,max;
    double middle;
    min = array[0]>array[n-1]? array[n-1]:array[0];
    max = array[0]>array[n-1]? array[0]:array[n-1];

    if ( n % 2) {
        int middle = array[(n-1)/2];
        cout<<max<<" "<<middle<<" "<<min<<endl;
    } else if ( (array[n/2]+array[n/2-1]) %2 ){
        double middle = (array[n/2]+array[n/2-1])/2.0;
        cout<<max<<" "<<fixed<<setprecision(1)<<middle<<" "<<min<<endl;
    } else {
        int middle = (array[n/2]+array[n/2-1]) /2;
        cout<<max<<" "<<middle<<" "<<min<<endl;
    }
    return 0;
}