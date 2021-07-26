#include <bits/stdc++.h>
using namespace std;
void ngr(int arr[],int n,int ans[]){
    std::stack<int> st;
    st.push(n-1);
    ans[n-1]=n;
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 and arr[i]>arr[st.top()]){
            st.pop();
        }
        if(st.size()==0)
          ans[i]=n;
        else{
            ans[i]=st.top();
        }
        st.push(i);
        
    }
}
int main() {
	int arr[]={8,3,7,5,10,8,4,9,5};
	int n=9;
	int ans[9];
	ngr(arr,n,ans);
    int k=4;
    int j=0;
    
    for(int i=0;i<=n-k;i++){
        if(j<i)
            j=i;
        while(ans[j]<i+k){
            j=ans[j];
        }
    std::cout << arr[j] << std::endl;
    }
	return 0;
}
