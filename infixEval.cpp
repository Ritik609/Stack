#include<bits/stdc++.h>
using namespace std;
int priority(char c)
{
    if(c=='+' or c=='-') return 1;
    else return 2;
}
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
    string s="2 * (5 + 3) / 4";

    stack<char>opr;
    stack<int>oprand;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        // operand
        if(isdigit(s[i]))
        {
            oprand.push(s[i]-'0');
        }
        else if(s[i]=='(')
            opr.push(s[i]);
        else if(s[i]==')')
        {
            while(opr.size()>0 and opr.top()!='(')
            {
            char oprator=opr.top();
            opr.pop();
            int var2=oprand.top();
            oprand.pop();
            int var1=oprand.top();
            oprand.pop();
            int res=calc(var1,var2,oprator);
            oprand.push(res);
            }
            opr.pop();
        }
        else if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/')
        {
            while(opr.size()>0 and opr.top()!='(' and priority(opr.top())>=priority(s[i]))
            {
            char oprator=opr.top();
            opr.pop();
            int var2=oprand.top();
            oprand.pop();
            int var1=oprand.top();
            oprand.pop();
            int res=calc(var1,var2,oprator);
            oprand.push(res);
            }
            opr.push(s[i]);
        }
    }
    while(opr.size()>0)
    {

        char oprator=opr.top();
            opr.pop();
            int var2=oprand.top();
            oprand.pop();
            int var1=oprand.top();
            oprand.pop();
            int res=calc(var1,var2,oprator);
            oprand.push(res);
    }
    cout<<oprand.top();
}
