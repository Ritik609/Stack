#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[][4]={ {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 0, 0, 0},
           {0, 0, 1, 0} };
    std::stack<int> st;
    for (int i = 0; i < 4; i++) {
        st.push(i);
    }
    while(st.size()>=2){
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        if(arr[b][a]==0)
            st.push(b);
        else{
            st.push(a);
        }
    }
    int pot=st.top();
    for (int i = 0; i < 4; i++) {
        /* code */
        if(i!=pot){
            if(arr[i][pot]==0 or arr[pot][i]==1)
               {
                   std::cout << "false" << std::endl;
                   return 0;
        }
    }
    }
    cout<<pot;
	return 0;
}
