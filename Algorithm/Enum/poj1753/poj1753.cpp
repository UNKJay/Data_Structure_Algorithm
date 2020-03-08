#include<memory>
#include<iostream>
#include<cstring>
using namespace std;

char oriLight[4];       //init
char lights[4];         //change
char result[4];        //result

int GetBit(char c,int i){
    return (c>>i)&1;
}

void SetBit(char &c,int i,int v){
    if (v)
        c|=(1<<i);
    else
        c&=~(1<<i);
}

void FlipBit(char &c,int i){
    c^=(1<<i);
}

int GetOne(char result[]){
    int num=0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (GetBit(result[i],j))
                ++num;
        }
        
    }
    return num;
}

int main(){
    int ans=17;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            char c;
            cin>>c;
            if (c=='b')
                SetBit(oriLight[i],j,1);
            else 
                SetBit(oriLight[i],j,0);
        }
    int t=2;
    while (t--)
    {
        for (int n = 0; n < 16; ++n)
        {
            int switchs=n;
            memcpy(lights,oriLight,sizeof(oriLight));
            for (int i = 0; i < 4; ++i)
            {
                result[i]=switchs;
                for (int j = 0; j < 4; ++j)
                {
                    if (GetBit(switchs,j))
                    {
                        if (j>0)
                            FlipBit(lights[i],j-1);
                        FlipBit(lights[i],j);
                        if (j<3)
                            FlipBit(lights[i],j+1);
                    }
                }
                if (i<3)
                    lights[i+1]^=switchs;
                switchs=lights[i];   
            }
            if (lights[3]==0)
            {
                int s=GetOne(result);
                if (s<ans)
                    ans=s;
            }
        } 
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                FlipBit(oriLight[i],j);
    }
    if (ans==17)       
        cout<<"Impossible"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}