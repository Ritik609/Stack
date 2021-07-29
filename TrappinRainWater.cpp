#include <bits/stdc++.h>
using namespace std;
int trap(int heights[],int n){
    int l=0,u=n-1;
    int maxLeft=heights[0];
    int maxRight=heights[n-1];
    int ans=0;
    while(l<u){
        if(heights[l]<=heights[u]){
            l++;
            maxLeft=max(maxLeft,heights[l]);
            ans=ans+(maxLeft-heights[l]);
            
        }
        else{
            u--;
            maxRight=max(maxRight,heights[u]);
            ans=ans+(maxRight-heights[u]);
        }
    }
    return ans;
}
int main()
{
   
    int heights[] = { 7, 0, 4, 2, 5, 0, 6, 4, 0, 5 };
    int n = sizeof(heights) / sizeof(heights[0]);
    std::cout << trap(heights,n) << std::endl;
}
