#include <bits/stdc++.h>
using namespace std;
void nger(int arr[],int n,int ans[]){
    std::stack<int> st;
    st.push(arr[n-1]);
    ans[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 and arr[i]>=st.top()){
            st.pop();
        }
        if(st.size()==0)
            ans[i]=-1;
        else{
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
}
int main() {
	int arr[]={4,3,2,5,8,10,3,6};
	int n=8;
	int ans[8];
	nger(arr,n,ans);
	for(int i=0;i<n;i++)
	  std::cout << ans[i] << std::endl;
	return 0;
}
