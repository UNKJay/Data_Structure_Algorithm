// #include<stdio.h>
// #include<algorithm>

#include<cstdio>

#define MAXN 100010
using namespace std;

struct Node{
    int data;
    int next;
} node[MAXN];

typedef struct Node* List;

int Reverse( List L, int K ) {
    int new_head = L->next;
    int old_head = node[new_head].next;
    int cnt = 1;

    while (cnt < K ) {
        int temp = node[old_head].next;
        node[old_head].next = new_head;
        new_head = old_head;
        old_head = temp;
        cnt++;
    }
    node[L->next].next = old_head;
    return new_head;
}

void Print( List L) {
    int position = L->next;
    while (node[position].next != -1)
    {
        printf("%05d %d %05d\n", position,node[position].data,node[position].next);
        position = node[position].next;
    }
    printf("%05d %d %d\n", position,node[position].data,node[position].next);
}

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

    //不投机取巧的写法
    int num = 0;                //总共节点数
    int pos = first_addr;
    while (pos != -1)
    {
        num ++;
        pos = node[pos].next;
    }
    
    List L = new struct Node;
    L->next = first_addr;
    List head = L;
    for (int i = 0; i < (num/K) ; i++) {
        int temp = L->next;
        L->next = Reverse(L,K);
        L = &(node[temp]);
    }
    Print(head);
    //投机取巧的写法
    // int addr_list[MAXN];
    // int p=first_addr,j=0;
    // while (p!=-1)
    // {
    //     addr_list[j++]=p;
    //     p=node[p].next;
    // }
    
    // int i=0;
    // while(i+K<=j){
    //     reverse(&addr_list[i],&addr_list[i+K]);
    //     i=i+K;
    // }
    
    // for (int i = 0; i < j-1; i++)
    // {
    //     printf("%05d %d %05d\n",addr_list[i],(node[addr_list[i]]).data,addr_list[i+1]);
    // }
    // printf("%05d %d -1\n",addr_list[j-1],(node[addr_list[j-1]]).data);
}