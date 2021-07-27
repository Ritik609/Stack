#include <bits/stdc++.h>
#include<ctype.h>
using namespace std;
int calc(int a,int b,char optor){
    if(optor=='+')
      return a+b;
    else if(optor=='-')
      return a-b;
    else if(optor=='*')
      return a*b;
    else if(optor=='/')
      return a/b;
}
int precedence(char optor){
    if(optor=='+')
      return 1;
    else if(optor=='-')
      return 1;
    else if(optor=='*')
      return 2;
    else if(optor=='/')
      return 2;
}
int main() {
    string s="2+(5-3*6/2)";
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
            if(opr.size()>0 and opr.top()!='(' and precedence(s[i])<=precedence(opr.top()))
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
    std::cout << oprand.top() << std::endl;
	return 0;
}
