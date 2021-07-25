#include <bits/stdc++.h>
using namespace std;
void ngr(int arr[],int n,int ans[]){
    std::stack<int> st;
    st.push(arr[n-1]);
    ans[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 && arr[i]>=st.top()){
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
	int arr[]={4,7,2,8,4,20,2,9,6};
	int n=9;
	int ans[9];
	ngr(arr,n,ans);
    for(int i=0;i<n;i++)
      std::cout << ans[i] << std::endl;
	return 0;
}
