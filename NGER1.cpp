#include <bits/stdc++.h>
using namespace std;
void ngr(int arr[],int n,int ans[]){
    std::stack<int> st;
    st.push(0);
    for(int i=1;i<n;i++){
        while(st.size()>0 and arr[i]>arr[st.top()]){
            int pos=st.top();
            ans[pos]=arr[i];
            st.pop();
        }
        st.push(i);
        
    }
    while(!st.empty()){
            int pos=st.top();
            ans[pos]=-1;
            st.pop();
        }
}
int main() {
	int arr[]={4,7,2,8,4,20,2,9,6};
	int n=9;
	int ans[9];
	ngr(arr,n,ans);
    for(int i=0;i<n;i++)
      std::cout << ans[i] << std::endl;
	return 0;
}
