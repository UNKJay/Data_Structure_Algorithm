#include<cstdio>
#include<list>

using namespace std;

int main() {
    int n,m,p,q;
    scanf("%d%d",&n,&m);
    list<int> l;
    for (int i = 1; i <= n; i++)
    {
        l.push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d",&p,&q);
        list<int>::iterator it = l.begin();
        while (*it != p) it++;
        it = l.erase(it);
        while (q>0) {
            it++;
            q--;
        }
        while (q<0) {
            it--;
            q++;
        }
        l.insert(it,p);
    }
    for (list<int>::iterator it = l.begin(); it!=l.end(); it++) {
        if (it != l.begin()) printf(" ");
        printf("%d",*it);
    }
    printf("\n");
    return 0;
}