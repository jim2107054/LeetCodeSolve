#include<bits/stdc++.h>
using namespace std;

int minSwaps(string s) {
        //Base case
        if(s.size()<=2) return 0;

        stack<char>st;
        for(char ch:s){
            st.push(ch);
            if(st.size()>=2){
                char top1=st.top();
                st.pop();
                char top2=st.top();

                if(top1==']' && top2=='['){
                    st.pop();
                }
                else{
                    st.push(top1);
                }
            }
        }
        if(s.size()==st.size()){
            return ceil(1.0*s.size()/4);
        }

        return ceil(((1.0*st.size())/4));
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;

    cout<<minSwaps(s)<<endl;
}