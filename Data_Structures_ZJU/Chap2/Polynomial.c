#include<stdio.h>
#include<stdlib.h>

typedef struct PolyNode* Polynomial;
struct PolyNode{
    int coef;
    int expon;
    Polynomial link;
};

void Attach(int c,int e,Polynomial* pRear){
    Polynomial p;
    p=(Polynomial)malloc(sizeof(struct PolyNode));
    p->coef=c;
    p->expon=e;
    p->link=NULL;
    (*pRear)->link=p;
    (*pRear)=p;
}

Polynomial ReadPoly(){
    Polynomial P,Rear,tmp;
    int N;
    scanf("%d",&N);
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    Rear=P;
    P->link=NULL;

    while (N--)
    {
        int c,e;
        scanf("%d%d",&c,&e);
        Attach(c,e,&Rear);
    }
    tmp=P;
    P=P->link;
    free(tmp);
    return P;
}

Polynomial MultPoly(Polynomial P1, Polynomial P2){
    if (!P1||!P2) return NULL;
    Polynomial P,Rear,t1,t2,t;
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->link=NULL;
    Rear=P;
    t1=P1,t2=P2;
    while (t2)
    {
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2=t2->link;
    }
    t1=t1->link;
    while (t1)
    {
        t2=P2;
        Rear=P;
        int c,e;
        while(t2){
            c=t1->coef*t2->coef;
            e=t1->expon+t2->expon;
            while (Rear->link && Rear->link->expon>e)
            {
                Rear=Rear->link;
            }
            
            if (Rear->link && Rear->link->expon==e) {
                if (Rear->link->coef+c == 0 ) {
                    t=Rear->link;
                    free(t);
                    Rear->link=NULL;
                } else {
                    Rear->link->coef+=c;                    
                }
            } else
            {
                t=(Polynomial)malloc(sizeof(struct PolyNode));
                t->link=Rear->link;
                Rear->link=t;
                t->coef=c;
                t->expon=e;
                Rear=Rear->link;
            }
            
            t2=t2->link;
        }
        t1=t1->link;
    }
    t=P;
    P=P->link;
    free(t);
    return P;
}

Polynomial AddPoly(Polynomial P1,Polynomial P2){
    Polynomial t1=P1,t2=P2;
    Polynomial P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->link=NULL;
    Polynomial Rear=P;
    while (t1&&t2)
    {
        if (t1->expon==t2->expon){
            if (t1->coef+t2->coef == 0 ) {
                t1=t1->link;
                t2=t2->link;
            } else {
                Attach(t1->coef+t2->coef,t1->expon,&Rear);
                t1=t1->link;
                t2=t2->link;
            }
        } else if(t1->expon>t2->expon){
            Attach(t1->coef,t1->expon,&Rear);
            t1=t1->link;
        } else {
            Attach(t2->coef,t2->expon,&Rear);
            t2=t2->link;
        }
    }
    while (t1)
    {
        Attach(t1->coef,t1->expon,&Rear);
        t1=t1->link;
    }
    while (t2)
    {
        Attach(t2->coef,t2->expon,&Rear);
        t2=t2->link;
    }
    Polynomial t=P;
    P=P->link;
    free(t);
    return P;
}

void PrintPoly(Polynomial P){
    if (!P) {
        printf("0 0\n");
        return;
    }
    int flag=0;
    while (P)
    {
        if (!flag)
            flag=1;
        else
            printf(" ");
        printf("%d %d",P->coef,P->expon);
        P=P->link;
    }
    printf("\n");
}

int main(){
    Polynomial P1,P2,PP,PS;
    P1=ReadPoly();
    P2=ReadPoly();
    PP=MultPoly(P1,P2);
    PrintPoly(PP);
    PS=AddPoly(P1,P2);
    PrintPoly(PS);
    return 0;
}