#include<bits/stdc++.h>
using namespace std;

int solve(string s){
    stack<char>st;

    for(auto ch:s){
        st.push(ch);

        if(st.size()>=2){
            auto top1 = st.top();
            st.pop();
            auto top2 = st.top();

            if(top1==')' && top2=='('){
                st.pop();
            }
            else{
                st.push(top1);
            }
        }
    }
    return st.size();
}

int main()
{
    string s;
    cout<<"Enter your input string: ";
    cin>>s;
    cout<<"Minimum add to make parentheses valid is: "<<solve(s)<<endl;

    return 0;
}