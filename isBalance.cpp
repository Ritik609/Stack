#include <bits/stdc++.h>
using namespace std;

bool isBalance(string s){
    std::stack<char> st;
    for(int i=0;i<s.size();i++){
       if(s[i]=='{' or s[i]=='(' or s[i]=='{')
         st.push(s[i]);
        else if(s[i]=='}'){
            if(st.size()==0)
                  return false;
                else if(st.top()!='{'){
                    return false;
                }
                else{
                    st.pop();
                }
        }
        else if(s[i]==']')
        {
            if(st.size()==0)
                  return false;
                else if(st.top()!='['){
                    return false;
                }
                else{
                    st.pop();
                }
        }
        else if(s[i]==')')
if(st.size()==0)
                  return false;
                else if(st.top()!='('){
                    return false;
                }
                else{
                    st.pop();
                    
                }    }
        if(st.size()==0)
          return true;
        else
          return false;
    
}
int main() {
	string s="((a+b)+(c+d)}";
	std::cout << isBalance(s) << std::endl;
	return 0;
}
