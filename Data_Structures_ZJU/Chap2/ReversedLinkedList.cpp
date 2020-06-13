#include<stdio.h>
#include<algorithm>

#define MAXN 100010
using namespace std;

struct {
    int data;
    int next;
} node[MAXN];

int main(){
    int first_addr,N,K;
    scanf("%d%d%d",&first_addr,&N,&K);
    for (int i = 0; i < N; i++)
    {
        int addr,data,next_addr;
        scanf("%d%d%d",&addr,&data,&next_addr);
        node[addr].data=data;
        node[addr].next=next_addr;
    }

    int addr_list[MAXN];
    int p=first_addr,j=0;
    while (p!=-1)
    {
        addr_list[j++]=p;
        p=node[p].next;
    }
    
    int i=0;
    while(i+K<=j){
        reverse(&addr_list[i],&addr_list[i+K]);
        i=i+K;
    }
    
    for (int i = 0; i < j-1; i++)
    {
        printf("%05d %d %05d\n",addr_list[i],(node[addr_list[i]]).data,addr_list[i+1]);
    }
    printf("%05d %d -1\n",addr_list[j-1],(node[addr_list[j-1]]).data);
}