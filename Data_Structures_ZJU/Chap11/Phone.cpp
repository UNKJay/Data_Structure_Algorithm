
/* 使用map简单粗暴
#include<iostream>
#include<string>
#include<map>

using namespace std;

int N;
map<string, int> record;

int main() {
    int max = 0;
    string maxId;
    string s1,s2;
    cin>>N;
    while (N--) {
        cin>>s1>>s2;
        record[s1]++;
        record[s2]++;
        if (record[s1] > max) {
            max = record[s1];
            maxId = s1;
        }
        if (record[s2] > max) {
            max = record[s2];
            maxId = s2;
        }
    }

    int count = 0;
    for (auto i:record) {
        if (i.second == max) {
            count++;
            if (count == 1) maxId = i.first;
        }
    }

    cout<<maxId<<" "<<max;
    if (count>1) cout<<" "<<count<<endl;
}
*/

// 基本功