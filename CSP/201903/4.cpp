#include<bits/stdc++.h>

using namespace std;

int T,n;
bool wait[10005];
vector<string> code;
map<int,int> position;

bool getStatus(int start, int dest, bool flag);     //flag 为true start Rdest; false startSdest
int getNum(int index, int start);

int main() {
    cin>>T>>n;
    getchar();
    while (T--) {
        string str;
        code.clear();
        position.clear();
        fill(wait,wait+n,false);
        for (int i = 0; i < n; i++)
        {
            position[i] = 0;
            getline(cin,str);
            code.push_back(str);
        }
        
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            while (position[i] < code[i].size()) {
                char c = code[i][position[i]];
                int dest = getNum(i,position[i]+1);
                wait[i] = true;
                if (!getStatus(i,dest,c == 'R')) {
                    flag = false;
                    break;
                } else {
                    wait[i] = false;
                }
            }
            if (!flag) break;
        }
        if (flag) printf("0\n");
        else printf("1\n");
    }
    
    return 0;
}

int getNum(int index, int start) {
    int result = 0;
    while (isdigit(code[index][start])) {
        result = result * 10 + code[index][start] - '0';
        start++;
        if (start >= code[index].size()) {
            break;
        }
    }
    if (start >= code[index].size()) {
        position[index] = start;
    } else {
        position[index] = start+1;
    }
    return result;
}

bool getStatus(int start, int dest, bool flag)     //flag 为true start Rdest; false startSdest
{
    if (wait[dest]) return false;
    if (position[dest] >= code[dest].size()) return false;
   char c,another;
    while (true) {
        c = code[dest][position[dest]];
        another = getNum(dest,position[dest]+1);
        if (another == start) {
            char test = flag?'R':'S';
            if (c == test) {
                // printf("%d %d %d %c %c\n",another,dest,start,c,test);
                return false;
            } else {
                return true;
            }
        } else {
            if (position[dest] >= code[dest].size()) return false;
            wait[dest] = true;
            if (!getStatus(dest,another,c=='R')) {
                return false;
            } else {
                wait[dest] = false;
                if (position[dest] >= code[dest].size()) return false;
            }
        }
    }
}

/*
3 2
R1 S1
S0 R0
R1 R1 S1 S1
S0 S0 R0 R0
R1 S1
R0 S0

2 3
R1 S1
R2 S0 R0 S2
S1 R1
R1
R2 S0 R0
S1 R1
*/