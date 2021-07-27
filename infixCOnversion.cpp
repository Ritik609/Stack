#include<bits/stdc++.h>
using namespace std;
int priority(char c)
{
    if(c=='+' or c=='-') return 1;
    else return 2;
}

int main()
{
    string s="2+3";

    stack<char>opr;
    stack<string>pre;
    std::stack<string> post;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        // operand
        
        if(isdigit(s[i]) or isalpha(s[i])){
            string preS,postS;
            preS.push_back(s[i]);
            postS.push_back(s[i]);
            pre.push(preS);
            post.push(postS);
        }
        else if(s[i]=='(')
            opr.push(s[i]);
        else if(s[i]==')')
        {
            while(opr.size()>0 and opr.top()!='(')
            {
            char opt=opr.top();
            opr.pop();
            string oprator;
            oprator.push_back(opt);
            string b=pre.top();
            pre.pop();
            string a=pre.top();
            pre.pop();
            string ans=oprator+a+b;
            pre.push(ans);
            
            string c =post.top();
            post.pop();
            string d=post.top();
            post.pop();
            string ans1=d+c+oprator;
            post.push(ans1);
            }
            opr.pop();
        }
        else if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/')
        {
            while(opr.size()>0 and opr.top()!='(' and priority(opr.top())>=priority(s[i]))
            {
            char opt=opr.top();
            opr.pop();
            string oprator;
            oprator.push_back(opt);
            string b=pre.top();
            pre.pop();
            string a=pre.top();
            pre.pop();
            string ans=oprator+a+b;
            pre.push(ans);
            
            string c =post.top();
            post.pop();
            string d=post.top();
            post.pop();
            string ans1=d+c+oprator;
            post.push(ans1);
            }
            opr.push(s[i]);
        }
    }
    while(opr.size()>0)
    {
            char opt=opr.top();
            opr.pop();
            string oprator;
            oprator.push_back(opt);
            string b=pre.top();
            pre.pop();
            string a=pre.top();
            pre.pop();
            string ans=oprator+a+b;
            pre.push(ans);
            
            string c =post.top();
            post.pop();
            string d=post.top();
            post.pop();
            string ans1=d+c+oprator;
            post.push(ans1);
    }
    std::cout << pre.top() << std::endl;
    std::cout << post.top() << std::endl;
}
