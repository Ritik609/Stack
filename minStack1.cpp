#include<bits/stdc++.h>
using namespace std;

class stacks
{
    stack<int>s;
    stack<int>mn;
    public:
        void push(int x)
        {
            s.push(x);
            if(mn.size()==0 or mn.top()>=x)
            {
                mn.push(x);
            }
        }
        int pop()
        {
            if(s.size()==0)
            {
                cout<<"Stack underflow\n";
                return -1;
            }
            if(s.top()==mn.top())
                mn.pop();
            int x = s.top();
            s.pop();
            return x;
        }
        int top()
        {
            if(s.size()==0)
            {
                cout<<"Stack underflow\n";
                return -1;
            }
            return s.top();
        }
        int min()
        {
            if(mn.size()==0)
            {
                cout<<"Stack underflow\n";
                return -1;
            }
            return mn.top(); 
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
