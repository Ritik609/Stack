#include <bits/stdc++.h>
using namespace std;
int calc(int a, int b,char c){
    if(c=='+') return a+b;
    else if(c=='-') return a-b;
    else if(c=='*') return a*b;
    else if(c=='/') return a/b;
}//-+2/*6483
int main() {
	string s="+32";
	int n=s.size();
	std::stack<int>  vs;
	std::stack<string> ps;
	std::stack<string> is;
	for(int i=n-1;i>=0;i--){
	     
	    if(s[i]=='+' or s[i]=='-' or s[i]=='*'  or s[i]=='/'){
	        int a=vs.top();
            vs.pop();
            int b=vs.top();
            vs.pop();
            int res=calc(a,b,s[i]);
            vs.push(res);
	        
	       string val1=is.top();
            is.pop();
            string val2=is.top();
            is.pop();
            string opr;
            opr.push_back(s[i]);
            string res1='('+val1+opr+val2+')';
            is.push(res1);
            
            string y=ps.top();
            ps.pop();
            string z=ps.top();
            ps.pop();
            string res2=opr+y+z;
            ps.push(res2);
	    }
	  else {
	        string str;
	        str.push_back(s[i]);
	        ps.push(str);
	        is.push(str);
	        vs.push(s[i]-'0');
	    }
	}
	std::cout << vs.top() << std::endl;
	std::cout << is.top() << std::endl;
	std::cout << ps.top() << std::endl;
	return 0;
}
