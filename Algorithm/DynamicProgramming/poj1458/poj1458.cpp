#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char s1[1000];
char s2[1000];
int maxLen[1000][1000];

int main(){
    while (cin>>s1>>s2)
    {
        int len1=strlen(s1);
        int len2=strlen(s2);
        for (int i = 0; i <= len1; ++i)
            maxLen[i][0]=0;
        for (int j = 0; j <= len2; ++j)
            maxLen[0][j]=0;
        for (int i=1;i<=len1;++i)
            for (int j=1;j<=len2;++j){
                if (s1[i-1]==s2[j-1])
                    maxLen[i][j]=maxLen[i-1][j-1]+1;
                else
                    maxLen[i][j]=max(maxLen[i-1][j],maxLen[i][j-1]);
                
            }
        cout<<maxLen[len1][len2]<<endl;
    }
    
    return 0;
}