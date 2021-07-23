#include <bits/stdc++.h>
using namespace std;
bool isDuplicate(string s){
    std::stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]==')'){
            if(st.top()=='(') return true;
            else{
                while(st.top()!='('){
                    st.pop();
                }
                st.pop();
            }
        }
        else{
            st.push(s[i]);
        }
    }
    return false;
}
int main() {
	string s="((a+b)+(c+d))";
	std::cout << isDuplicate(s) << std::endl;
	return 0;
}
