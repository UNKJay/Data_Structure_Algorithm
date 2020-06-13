#include <iostream>

using namespace std;

#define MAX_TREE 10
#define Null -1
typedef int Tree;

struct Tree_Node {
    char data;
    Tree left;
    Tree right;
} T1[MAX_TREE],T2[MAX_TREE];

int Create_Tree( struct Tree_Node T[]) {
    int n;
    int Root=Null;
    int flag[MAX_TREE];
    cin>>n;
    if (n) {
        for (int i = 0; i < n; i++)
        {
            flag[i] = 0;
        }
        
        for (int i = 0; i < n; i++)
        {
            
            char cl,cr;
            cin>>T[i].data;
            cin.get();  cl = cin.get();
            cin.get();  cr = cin.get();
            if (cl != '-') {
                T[i].left = cl - '0';
                flag[T[i].left] = 1;
            } else 
                T[i].left = Null;

            if (cr != '-') {
                T[i].right = cr - '0';
                flag[T[i].right] = 1;
            } else 
                T[i].right = Null;

        }
        for (int i = 0; i < n; i++)
        {
            if (flag[i] == 0) {
                Root = i;
                break;
            }
        }
    }
    return Root;
}

int Is_Omorphic(int Root1, int Root2){
    if (Root1 == Null && Root2 == Null) return 1;
    if ((Root1 != Null && Root2 == Null) || (Root1 == Null && Root2 != Null)) return 0;
    if (T1[Root1].data != T2[Root2].data) return 0;

    if (T1[Root1].left == Null && T2[Root2].left == Null) return Is_Omorphic(T1[Root1].right,T2[Root2].right);
    if ((T1[Root1].left != Null && T2[Root2].left != Null) && (T1[T1[Root1].left].data == T2[T2[Root2].left].data)) 
        return Is_Omorphic(T1[Root1].left,T2[Root2].left) && Is_Omorphic(T1[Root1].right,T2[Root2].right);
    else
        return Is_Omorphic(T1[Root1].left,T2[Root2].right) && Is_Omorphic(T1[Root1].right,T2[Root2].left);
}

int main() {
    int Root1 = Create_Tree(T1);
    int Root2 = Create_Tree(T2);

    cout<<(Is_Omorphic(Root1,Root2)?"Yes":"No")<<endl;

    return 0;
}