#include<bits/stdc++.h>
using namespace std;

class stacks
{
    stack<int>s;
    int mn;
    public:
        void push(int x)
        {
            if(s.size()==0)
            {
                mn=x;
                s.push(x);
            }
            else if(x>=mn)
            {
                s.push(x);
            }
            else 
            {
                int val=x+(x-mn);
                mn=x;
                s.push(val);
            }
        }
        int pop()
        {
            if(s.size()==0)
            {
                cout<<"Stack underflow\n";
                return -1;
            }
            if(s.top()<mn) 
            {
                int x = mn;
                mn = 2*mn-s.top();
                s.pop();
                return x;
            }
            else
            {
                int x=s.top();
                s.pop();
                return x;
            }
        }
        int top()
        {
            if(s.size()==0)
            {
                cout<<"Stack underflow\n";
                return -1;
            }
            
            if(s.top() < mn)
            {
                return mn;
            }
            else
            {
                return s.top();
            }
        }
        int min()
        {
            if(s.size()==0)
            {
                cout<<"Stack underflow\n";
                return -1;
            }
            return mn; 
        }
        int size()
        {
            return s.size();
        }
};
int main()
{
    stacks ob;
    string s;
    while(cin>>s)
    {
        if(s=="push")
        {
            int x;
            cin>>x;
            ob.push(x);          
        }
        else if(s=="pop")
        {
            int x=ob.pop();
            if(x!=-1)
                cout<<x<<"\n";
            
        }
        else if(s=="top")
        {
            int x=ob.top();
            if(x!=-1)
                cout<<x<<"\n";
        }
        else if(s=="size")
        {
            int x = ob.size();
            cout<<x<<"\n";
        }
        else if(s=="min")
        {
            int x=ob.min();
            if(x!=-1) cout<<x<<"\n";
        }
        else if(s=="quit")
        {
            break;
        }
    }
    
}
