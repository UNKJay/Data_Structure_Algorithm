#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<cctype>

using namespace std;

int N;
string equation;
unordered_map<string,int> ans;

void expression(int first, int last, int basic);
void formula(int first, int last, int basic);
int calculate(int &first, int last);

int main() {
    cin>>N;
    while (N--)
    {
        cin>>equation;
        ans.clear();
        int k = equation.find('=');
        expression(0,k-1,1);
        expression(k+1,equation.size()-1,-1);
        auto i = find_if(ans.begin(), ans.end(), [](const pair<string, int>& p) {return p.second != 0;});
        cout<<(i==ans.end()?'Y':'N')<<endl;
    }
    return 0;
}

void expression(int first, int last, int basic) {
    for (int i = first, j = first; i<=last; i = j + 1) {
        j = equation.find('+',i);
        if ((j == string::npos ) || (j > last)) {
            j = last + 1;
        }
        formula(i,j-1,basic);
    }
}

void formula(int first, int last, int basic) {
    if ((first == last) || ((last - first == 1) && islower(equation[last]))) {
        ans[equation.substr(first, last - first + 1)] += basic;
        return ;
    }
    basic *= calculate(first,last);
    for (int i = first, j = i + 1; i <= last; i = j, ++j) {
        if (isupper(equation[i])) {
            if (j <= last && islower(equation[j]))
                ++j;
            int k = j;
            formula(i,k-1,basic * calculate(j, last));
        } else if (equation[i] == '(') {
            for (int num = 1; num != 0; ++j) {
                if (equation[j] == '(') ++num;
                if (equation[j] == ')') --num;
            }
            int k=j;
            formula(i + 1, k-1, basic*calculate(j,last));
        }
    }
}

int calculate(int &first, int last) {
    int ans = 0;
    for (; first <= last && isdigit(equation[first]); ++first) {
        ans = ans * 10 + equation[first] - '0';
    }
    return ans == 0?1:ans;
}