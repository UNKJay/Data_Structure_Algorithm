#include<bits/stdc++.h>

using namespace std;

void query(int index);
string cal(string a, string b);

int n,s,l;
bool exist[1005];
vector<string> disk;

int main() {
    ios::sync_with_stdio(false);
    int index,m;
    string str;
    // scanf("%d%d%d",&n,&s,&l);
    cin>>n>>s>>l;
    disk.resize(n);
    for (int i = 0; i<l; ++i) {
        cin>>index;
        // scanf("%d%*c",&index);
        exist[index] = true;
        cin>>disk[index];
    }

    cin>>m;
    // scanf("%d",&m);
    while (m--) {
        cin>>index;
        // scanf("%d",&index);
        query(index);
    }
    return 0;
}

void query(int index) {
    int diskLength = disk[0].size();
    int diskBlock = diskLength/8;

    int belongLevel = index / ((n-1) * s);
    if (belongLevel >= diskBlock/s) {
        printf("-\n");
        return;
    }
    int levelPDisk = n-1-(belongLevel % n);
    int belongDisk = (levelPDisk + ((index % ( (n-1) * s)) / s) +1)%n;
    int start = (belongLevel*s + index % s)*8;
    if (exist[belongDisk]) {
        printf("%s\n",disk[belongDisk].substr(start,8).c_str());
    } else {
        if (count(exist,exist+n,false) > 1) {
            printf("-\n");
            return;
        }

        string result = disk[(belongDisk+1)%n].substr(start,8);
        for (int i = (belongDisk + 2) % n; i!=belongDisk; i = (i+1) % n) {
            string temp = disk[i].substr(start,8);
            result = cal(result,temp);
        }
        printf("%s\n",result.c_str());
    }
}

string cal(string a, string b) {
    int a1,a2,c;
    char result[10];
    string result2;
    sscanf(a.c_str(),"%X",&a1);
    sscanf(b.c_str(),"%X",&a2);
    c = a1 ^ a2;
    sprintf(result,"%X",c);
    return result2 = result;
}

/*
2 1 2
0 000102030405060710111213141516172021222324252627
1 000102030405060710111213141516172021222324252627
2
0
1

3 2 2
0 000102030405060710111213141516172021222324252627
1 A0A1A2A3A4A5A6A7B0B1B2B3B4B5B6B7C0C1C2C3C4C5C6C7
2
2
5
*/