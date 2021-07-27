#include<bits/stdc++.h>
using namespace std;

int main() {
	string s="ddidddid";
	int n=s.size();
	std::stack<int> st;
	int count=1;
	for (int i = 0; i <= n; i++) {
	        if(s[i]=='d'){
	            st.push(count);
	            count++;
	        }
	        else{
	            st.push(count);
	            count++;
	            while(st.size()>0){
	                int a=st.top();
	                cout<<a;
	                st.pop();
	            }
	        }
	}
	while(st.size()>0){
	                int a=st.top();
	                cout<<a;
	                st.pop();
	            }
	return 0;
}
