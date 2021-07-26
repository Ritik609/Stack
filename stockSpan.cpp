#include <bits/stdc++.h>
using namespace std;
void ngr(int arr[],int n,int ans[]){
    std::stack<int> st;
    st.push(0);
    ans[0]=1;
    for(int i=1;i<n;i++){
        while(st.size()>0 && arr[i]>=arr[st.top()]){
            st.pop();
        }
        if(st.size()==0)
          ans[i]=i+1;
        else{
            ans[i]=i-st.top();
        }
        st.push(i);
    }
}
int main() {
	int arr[]={5,7,2,9,1,8,25,3,7,35,7,8};
	int n=12;
	int ans[12];
	ngr(arr,n,ans);
    for(int i=0;i<n;i++)
      std::cout << ans[i] << std::endl;
	return 0;
}
