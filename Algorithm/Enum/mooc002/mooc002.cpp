#include<iostream>
#include<cstring>

using namespace std;

int oriClock[10];
int curClock[10];
int Move[10];

int main(){
    for (int i = 1; i < 10; i++)
        cin>>oriClock[i];
    
    for (Move[1]= 0; Move[1] < 4; Move[1]++)
    {
        for (Move[2]= 0; Move[2] < 4; Move[2]++)
        {
            for ( Move[3] = 0; Move[3] < 4; Move[3]++)
            {
                memcpy(curClock,oriClock,sizeof(oriClock));

                curClock[1] = (curClock[1]+Move[1]+Move[2])%4;
                curClock[2] = (curClock[2]+Move[1]+Move[2]+Move[3])%4;
                curClock[3] = (curClock[3]+Move[2]+Move[3])%4;

                curClock[4] = (curClock[4]+Move[1])%4;
                curClock[5] = (curClock[5]+Move[1]+Move[3])%4;
                curClock[6] = (curClock[6]+Move[3])%4;

                Move[4] = (4-curClock[1])%4;
                Move[5] = (4-curClock[2])%4;
                Move[6] = (4-curClock[3])%4;

                curClock[4] = (curClock[4]+Move[4]+Move[5])%4;
                curClock[5] = (curClock[5]+Move[5])%4;
                curClock[6] = (curClock[6]+Move[5]+Move[6])%4; 

                curClock[7] = (curClock[7]+Move[4])%4;
                curClock[8] = (curClock[8]+Move[5])%4;
                curClock[9] = (curClock[9]+Move[6])%4;

                Move[7]=(4-curClock[4])%4;
                Move[9]=(4-curClock[6])%4;

                curClock[5]=(curClock[5]+Move[7]+Move[9])%4;

                curClock[7] = (curClock[7]+Move[7])%4;
                curClock[8] = (curClock[8]+Move[7]+Move[9])%4;
                curClock[9] = (curClock[9]+Move[9])%4;

                Move[8]=(4-curClock[8])%4;
                curClock[7] = (curClock[7]+Move[8])%4;
                curClock[9] = (curClock[9]+Move[8])%4;

                if (curClock[5]+curClock[7]+curClock[9]==0){
                    for (int i = 1; i < 10; i++)
                    {
                        while (Move[i]--)
                            cout<<i<<' ';
                    }
                    return 0;
                }
            }
            
        }
        
    }
}