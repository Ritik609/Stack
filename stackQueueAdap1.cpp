#include<bits/stdc++.h>
using namespace std;
class stacks 
{
        stack<int>mainS,helperS;
    public:
        void add(int x)
        {
            if(mainS.size()>=1)
            {
                while(mainS.size()>0)
                {
                    helperS.push(mainS.top());
                    mainS.pop();
                }
                mainS.push(x);
                while(helperS.size()>0)
                {
                    mainS.push(helperS.top());
                    helperS.pop();
                }
            }
            else mainS.push(x);
        }
        int remove()
        {
            if(mainS.size()==0)
            {
                cout<<"Queue underflow\n";
                return -1;
            }
            int x=mainS.top();
            mainS.pop();
            return x;
        }
        int peek()
        {
            if(mainS.size()==0)
            {
                cout<<"Queue underflow\n";
                return -1;
            }
            int x=mainS.top();
            return x;
        }
        int size()
        {
            return mainS.size();
        }
};
int main()
{
    string s;
    stacks ob;
    while(cin>>s)
    {
        if(s=="add")
        {
            int x;
            cin>>x;
            ob.add(x);
        }
        else if(s=="remove")
        {
            int x =ob.remove();
            if(x!=-1)
            {
                cout<<x<<"\n";
            }
        }
        else if(s=="peek")
        {
            int x =ob.peek();
            if(x!=-1)
            {
                cout<<x<<"\n";
            }
        }
        else if(s=="size")
        {
            int x =ob.size();
            if(x!=-1)
            {
                cout<<x<<"\n";
            }
        }
        else if(s=="quit")
        {
            break;
        }
    }
}
