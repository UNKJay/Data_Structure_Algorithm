#include <iostream>
#include <algorithm>
 
using namespace std;
int a[1009];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j,m,ans=0;
        cin>>n;
        for(i=1; i<=n; i++)
            cin>>a[i];
        sort(a+1,a+1+n);
        m=n;
        while(m>0)
        {
            if(m>=4)
            {
                if(a[m]+a[m-1]+2*a[1]>a[2]+a[1]+a[m]+a[2])
                {
                    ans+=a[2]+a[1]+a[m]+a[2];
                }
                else
                {
                    ans+=a[m]+a[m-1]+2*a[1];
                }
                m-=2;
            }
            else if(m==3)
            {
                ans+=a[m]+a[1]+a[2];
                m=0;
            }
            else if(m==2)
            {
                ans+=a[m];
                m=0;
            }
            else if(m==1)
            {
                ans+=a[m];
                m=0;
            }
        }
        cout<<ans<<endl;
    }
}