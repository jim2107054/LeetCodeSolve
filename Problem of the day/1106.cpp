#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    char solve(stack<char>& s) {
        vector<int> v;
        s.pop(); // Remove the closing ')'

        // Collect the values inside the parenthesis until '(' is found
        while (!s.empty() && s.top() != '(') {
            if (s.top() == 't') {
                v.push_back(1); // true
            } else if (s.top() == 'f') {
                v.push_back(0); // false
            }
            s.pop();
        }

        if (v.empty()) {
            return 'n'; // Return 'n' to indicate no valid boolean values
        }

        s.pop(); // Remove '('

        // Now, the operation is at the top of the stack
        char operation = s.top();
        s.pop();
        
        //Print items of vector and the required operation it need to perform.
        cout<<"Element in vector are: ";
        for(auto u:v){
            cout<<u<<" ";
        }
        cout<<"Operator is: "<<operation<<endl;

        // Apply the operation
        int ans = v[0]; // Start with the first value

        if (operation == '&') {
            // Logical AND: All values must be true
            for (int i = 1; i < v.size(); i++) {
                ans = ans && v[i];
            }
        } else if (operation == '|') {
            // Logical OR: At least one value must be true
            for (int i = 1; i < v.size(); i++) {
                ans = ans || v[i];
            }
        } else if (operation == '!') {
            // Logical NOT: Negate the first value only
            ans = !v[0];
        }

        // Return 't' or 'f' based on the final result
        return ans == 1 ? 't' : 'f';
    }

public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        int n = expression.size();

        for (int i = 0; i < n; i++) {
            if (expression[i] == ')') {
                // If we encounter a closing parenthesis, solve the expression inside
                s.push(')');
                char result = solve(s);
                if (result != 'n') {
                    s.push(result); // Push the result ('t' or 'f') back to the stack
                }
            } 
            else if(expression[i]==',') continue;
            else {
                // Push all other characters to the stack
                s.push(expression[i]);
            }
        }

        // Final result should be at the top of the stack
        return s.top() == 't';
    }
};

int main() {
    Solution sol;
    string expression = "&(|(f))"; 
    bool result = sol.parseBoolExpr(expression);
    cout << (result ? "true" : "false") << endl;
    return 0;
}

