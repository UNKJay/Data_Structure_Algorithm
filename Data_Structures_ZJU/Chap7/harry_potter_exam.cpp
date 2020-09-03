#include<iostream>
#include<vector>

#define INFINITY 65535

using namespace std;

int Nv,Ne;                      //1..N-1
vector<vector<int>> MGraph;
vector<vector<int>> D;

bool Floyd();
void FindMinAnimal();
int FindMaxDist( int v);

int main() {
    cin>>Nv>>Ne;
    MGraph.assign(Nv,vector<int>(Nv,INFINITY));        
    D.assign(Nv,vector<int>(Nv,INFINITY));
    for (int i = 0; i < Ne; i++)
    {
        int l,r,weight;
        cin>>l>>r>>weight;
        MGraph[--l][--r] = weight;
        MGraph[r][l] = weight;
        D[l][r] = weight;
        D[r][l] = weight;
    }
    Floyd();
    FindMinAnimal();
    return 0;
}

bool Floyd() {                      //本题不需要使用bool值，只是做演示
    for (int k=0; k<Nv; k++) {
        for (int i = 0; i<Nv; i++) {
            for (int j = 0; j<Nv; j++) {
                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    if (i == j && D[i][j] < 0) return false;
                }
            }
        }
    }
    
    return true;
}

void FindMinAnimal() {
    int Animal, MinDist = INFINITY , MaxDist;
    for (int i = 0; i < Nv; i++)
    {
        MaxDist = FindMaxDist(i);
        if (MaxDist == INFINITY) {
            cout<<0<<endl;
            return;
        }

        if (MinDist > MaxDist) {
            MinDist = MaxDist;
            Animal = i + 1;
        }
    }
    cout<<Animal<<" "<<MinDist<<endl;
}

int FindMaxDist( int v) {
    int result = 0;
    for (int i = 0; i < Nv; i++)
    {
        if (i != v && D[v][i] > result) result = D[v][i];
    }
    return result;
}