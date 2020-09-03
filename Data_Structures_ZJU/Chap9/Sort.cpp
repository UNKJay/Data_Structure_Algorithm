#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100010;
const int CUTOFF = 100;

int N;
long long int A[MAXN];
long long int TempA[MAXN];

void BubbleSort();
void InsertSort(int l, int r);
void ShellSort();
void HeapSort();    void PercDown(int L , int R);
void MergeSort();   void Merge(int L, int R, int rightEnd); void MSort(int l, int rightEnd);    void MergePass(int length);
void QuickSort(int l, int r);   long long int Median3(int l, int r);


int main() {
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld",&A[i]);
    }
    //BubbleSort();
    //InsertSort();
    // ShellSort();
    // HeapSort();
    //MergeSort();
    QuickSort(0,N-1);
    for (int i = 0; i < N; i++)
    {
        printf("%lld",A[i]);
        if (i == N-1) printf("\n");
        else printf(" ");
    }
    return 0;
}

void BubbleSort() {
    for (int p = N-1; p >= 0; --p)          //p为元素放的位置
    {
        bool flag = false;
        for (int i = 0; i < p; i++)
        {
            if (A[i] > A[i+1]) {
                long long int temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                flag = true;
            }
        }
        if (!flag) break;
    }
}

void InsertSort(int l, int r) {
    for (int p = l+1; p <= r; p++)
    {
        int i;
        long long int temp = A[p];
        for (i = p; i > 0 && A[i-1] > temp; --i)
        {
            A[i] = A[i-1];
        }
        A[i] = temp;
    }   
}

void ShellSort() {
    for (int D = N/2; D > 0; D /= 2){
        for (int p = D; p < N; p += D)
        {
            int i;
            long long int temp = A[p];
            for (i = p; i >= D && A[i-D] > temp; i -= D)
            {
                A[i] = A[i-D];
            }
            A[i] = temp;
        }
    }
}

void HeapSort() {       //构建最大堆，调整，0-N-1
    for (int i = (N-1)/2; i >= 0; i--)
    {
        PercDown(i,N);                // build heap
    }
    for (int i = N-1; i > 0; --i) {
        long long int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        PercDown(0,i);
    }
}

void PercDown(int L, int R) {       // 树根不是堆
    long long int temp = A[L];
    int parent,child;
    for (parent = L; parent * 2 + 1 < R; parent = child) {
        child = parent * 2 + 1;
        if (child != R-1 && A[child] < A[child+1])
            child++;
        if (temp < A[child]) {
            A[parent] = A[child];
        } else {
            break;
        }
    }
    A[parent] = temp;
}

// L为左边开始位置，R为右边开始位置，rightEnd为右边结束位置
void Merge(int l, int r, int rightEnd) {
    int leftEnd = r - 1;
    int temp = l;
    int num = rightEnd - l + 1;
    while (l <= leftEnd && r <= rightEnd) {
        if (A[l] <= A[r]) TempA[temp++] = A[l++];
        else TempA[temp++] = A[r++];
    }

    while (l <= leftEnd) TempA[temp++] = A[l++];
    while (r <= rightEnd) TempA[temp++] = A[r++];
    for (int i = 0; i < num; i++, rightEnd--)
    {
        A[rightEnd] = TempA[rightEnd];
    }
}

void MSort(int l, int rightEnd) {
    int center;
    if (l < rightEnd) {
        center = (l + rightEnd) / 2;
        MSort(l,center);
        MSort(center+1, rightEnd);
        Merge(l,center+1,rightEnd);
    }
}

void MergeSort() {
    // 递归版本
    // MSort(0,N-1);       

    // 非递归版本
    int length = 1;
    while (length < N) {
        MergePass(length);
        length *= 2;
        MergePass(length);
        length *= 2;
    }
}

void MergePass( int length) {
    int i;
    for (i = 0; i <= N-2*length; i += 2*length)
    {
        Merge(i, i+length, i+length*2-1);
    }
    if (i + length < N) {
        Merge(i, i+length, N-1);
    } else {
        for (int j = i; j < N; j++) TempA[j] = A[j];
    }
}

long long int Median3(int l, int r) {
    int center = (l+r)/2;
    if (A[center] < A[l]) {
        swap(A[l],A[center]);
    }
    if (A[r] < A[l]) {
        swap(A[l],A[r]);
    }

    if (A[r] < A[center]) {
        swap(A[center],A[r]);
    }
    swap(A[center],A[r-1]);         //将主元藏起来
    return A[r-1];
}


// QuickSort(0,N-1)
void QuickSort(int l, int r) {
    if (CUTOFF <= r-l) {            //最好为100
        long long int pivot = Median3(l,r);
        int i = l;
        int j = r-1;
        for (;;) {
            while (A[++i] < pivot) {}
            while (A[--j] > pivot) {}
            if (i < j) {
                swap(A[i],A[j]);
            } else break;
        }
        swap(A[i],A[r-1]);          //确定主元位置
        QuickSort(l,i-1);
        QuickSort(i+1,r);
    } else {
        InsertSort(l,r);
    }
}

