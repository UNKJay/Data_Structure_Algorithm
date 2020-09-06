#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n,l,t;
    cin>>n>>l>>t;
    vector<int>location(n);
    vector<int>velocity(n,1);
    vector<int>axis(l+1,0);

    for (int i = 0; i < n; i++)
    {
        cin>>location[i];
        axis[location[i]]++;
    }
    
    while (t--)
    {
        for (int i = 0; i < n; i++)
        {
            axis[location[i]]--;
            location[i] += velocity[i];
            axis[location[i]]++;
            if (location[i] == 0 || location[i] == l) {
                velocity[i] = -velocity[i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (axis[location[i]] == 2) {
                velocity[i] = -velocity[i];
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<location[i]<<" ";
    }
    cout<<endl;    
    return 0;
}