#include<bits/stdc++.h>

using namespace std;

bool isStringDigit (const string& str) {
    for (char c: str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    int n,m;
    scanf("%d%d%*c",&n,&m);

    string p,r;
    vector<pair<string,regex>> rules;
    vector<pair<regex,string>> trans = {
        {regex("<int>"),"([0-9]+)"}, {regex("<str>"),"([^/]+)"}, {regex("<path>"),"(.+)"}
    };
    for (int i = 0; i < n; i++)
    {
        cin>>p>>r;
        for (auto i: trans) {
            p = regex_replace(p,i.first,i.second);
        }
        rules.push_back({r,regex(p)});
    }
    
    smatch result;
    while (m--) {
        cin>>p;
        for (auto i: rules) {
            if (regex_match(p,result,i.second)) {
                printf("%s",i.first.c_str());
                for (int i = 1; i<result.size(); i++) {
                    p = result[i];
                    if (p!="" && isStringDigit(p)) {
                        int d;
                        sscanf(p.c_str(),"%d",&d);
                        printf(" %d",d);
                    } else {
                        printf(" %s",p.c_str());
                    }
                }
                printf("\n");
                goto loop;
            }
        }
        printf("404\n");
        loop:;
    }
    return 0;
}