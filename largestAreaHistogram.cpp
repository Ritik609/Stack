#include <bits/stdc++.h>
using namespace std;
void ngr(int arr[],int n,int ans[]){
    std::stack<int> st;
    st.push(n-1);
    ans[n-1]=n;
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 && arr[i]<arr[st.top()]){
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
void ngl(int arr[],int n,int ans[]){
    std::stack<int> st;
    st.push(0);
    ans[0]=-1;
    for(int i=1;i<n;i++){
        while(st.size()>0 && arr[i]<arr[st.top()]){
            st.pop();
        }
        if(st.size()==0)
          ans[i]=-1;
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
}
int main() {
	int arr[]={5,7,2,9,1,8,5,3,7};
	int n=9;
	int ans1[9];
	ngr(arr,n,ans1);
	int ans2[9];
	ngl(arr,n,ans2);
	int maxArea=INT_MIN;
    for(int i=0;i<n;i++)
      {
          int width=ans1[i]-ans2[i]-1;
          int area=width*arr[i];
          if(area>maxArea)
            maxArea=area;
      }
      std::cout << maxArea << std::endl;
	return 0;
}
