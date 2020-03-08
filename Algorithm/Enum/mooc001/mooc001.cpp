#include<iostream>
#include<algorithm>

using namespace std;

int GetBit(int c,int i){
    return (c>>i)&1;
}

void SetBit(int &c,int i,int v){
    if (v)
        c|=(1<<i);
    else
        c&=~(1<<i);
}

void FilpBit(int &c, int i){
    c^=(1<<i);
}

int main(){
    string lockLine;
    getline(cin,lockLine);

    int oriLock=0;
    int desLock=0;
    int curLock=0;

    int len=lockLine.length();
    for (int i = 0; i < len; i++)
        SetBit(oriLock,i,lockLine[i]-'0');
    
    getline(cin,lockLine);
    for (int i = 0; i < len; i++)
        SetBit(desLock,i,lockLine[i]-'0');

    int miniTimes=len;
    for (int i = 0; i < 2; i++)
    {
        curLock=oriLock;
        int switches=i;
        int times=0;
        for (int j = 0; j < len; j++)
        {
            if (switches){
                times++;
                FilpBit(curLock,j);
                if (j>0)
                    FilpBit(curLock,j-1);
                if (j<len-1)
                    FilpBit(curLock,j+1);
            }
            switches=GetBit(curLock,j)^GetBit(desLock,j);
        }
        if (curLock==desLock)
            miniTimes=min(miniTimes,times);
            
    }
    if (miniTimes==len)
        cout<<"impossible"<<endl;
    else
        cout<<miniTimes<<endl;
    return 0;
}