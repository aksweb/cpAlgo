#include<bits/stdc++.h>
using namespace std;
 
int main()
{

    stack<int> st;
    st.push(1);
    st.push(2);st.push(13);st.push(14);st.push(15);
 
    while(st.size()){
        cout<<st.back();
        st.pop();
    }
 
    return 0;
}