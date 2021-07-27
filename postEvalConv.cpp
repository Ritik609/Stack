#include<bits/stdc++.h>
using namespace std;

int calc(int var1,int var2,char opr)
{
    if(opr=='+') return var1+var2;
    if(opr=='-') return var1-var2;
    if(opr=='*') return var1*var2;
    if(opr=='/') return var1/var2;
    return 0;
}
int main()
{
    string s="264*8/+3-";

    stack<string> is;
    stack<int> vs;
    std::stack<string> ps;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/'){
            int b=vs.top();
            vs.pop();
            int a=vs.top();
            vs.pop();
            int res=calc(a,b,s[i]);
            vs.push(res);
            
            string val2=is.top();
            is.pop();
            string val1=is.top();
            is.pop();
            string opr;
            opr.push_back(s[i]);
            string res1='('+val1+opr+val2+')';
            is.push(res1);
            
            string z=ps.top();
            ps.pop();
            string y=ps.top();
            ps.pop();
            string oprator;
            oprator.push_back(s[i]);
            string res2=oprator+y+z;
            ps.push(res2);
        }
        else{
            string str;
            str.push_back(s[i]);
            vs.push(s[i]-'0');
            ps.push(str);
            is.push(str);
        }
    }
    std::cout << vs.top() << std::endl;
    std::cout << is.top() << std::endl;
    std::cout << ps.top() << std::endl;
    return 0;       
}
