#include<iostream>

#define MAXN 1001
#define MINH -10001

using namespace std;

int heap[MAXN],size;

void Create() {
    size = 0;
    heap[0] = MINH;
}

/*
    建堆时除了可以一次一次的插入，还可以先放入数组满足完全二叉树的性质，然后针对当前数据进行排序。
    从倒数第一个有孩子的节点开始，满足左边是堆且右边是堆，开始进行调整，和删除时进行一样的调整即可
*/
void Insert(int x) {        //插入操作，需要判断是否满了
    int i = ++size;
    for ( ; heap[i/2] > x ; i=i/2 )     //> x 是与x进行比较，i记录位置
    {
        heap[i] = heap[i/2];
    }
    heap[i] = x;
}

int Delete() {      //要判断是否为空
    int min_item = heap[1];
    int parent,child;
    int tmp = heap[size--];     //将最后一个直接放置在第一个
    for ( parent = 1 ; parent*2<=size ; parent = child)       //有左孩子
    {
        child = parent*2;
        if ((child != size) && (heap[child]>heap[child+1]))     //child指向较小的孩子，前一个保证有两个孩子
            child++;
        if (tmp > heap[child]) {
            heap[parent] = heap[child];
        } else break;
    }
    heap[parent] = tmp;
    return min_item;
}

int main() {
    int N,M,x;
    cin>>N>>M;
    Create();           //初始化

    for (int i = 0; i < N; i++)
    {
        cin>>x;
        Insert(x);
    }

    for (int i = 0; i < M; i++)
    {
        cin>>x;
        cout<<heap[x];
        for ( x=x/2 ; x >= 1 ; x=x/2)
        {
            cout<<" "<<heap[x];
        }
        cout<<endl;
    }
    return 0;
}