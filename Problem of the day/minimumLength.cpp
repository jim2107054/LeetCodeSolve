#include<bits/stdc++.h>
using namespace std;

int minimumLengthAfterRemovals(string& s) {
     stack<char> st;

    for (char ch : s) {
        st.push(ch);
        
        // Check the top two characters in the stack
        if (st.size() >= 2){
            char top1 = st.top();
            st.pop();
            char top2 = st.top();
            // Check if they form "AB" or "CD"
            if ((top1 == 'B' && top2 == 'A') || (top1 == 'D' && top2 == 'C')) {
                // Remove the last two characters
                st.pop();
            } else {
                // If they do not form the required substring, push the first character back
                st.push(top1);
            }
        }
    }

    // The remaining characters in the stack represent the resulting string
    return st.size();
}

int main() {
     string s;
     cout << "Enter the string: ";
     cin >> s;

    int result = minimumLengthAfterRemovals(s);
     cout << "Minimum possible length of the resulting string: " << result <<  endl;

    return 0;
}
