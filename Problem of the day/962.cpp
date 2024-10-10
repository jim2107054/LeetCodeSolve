#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v) {
    stack<int> s;
    int maxWidth = 0;

    // Collect indices of the elements in a decreasing manner
    for (int i = 0; i < v.size(); i++) {
        if (s.empty() || v[s.top()] > v[i]) {
            s.push(i); 
        }
    }

    for (int j = v.size() - 1; j >= 0; j--) {
        while (!s.empty() && v[j] >= v[s.top()]) {
            maxWidth = max(maxWidth, j - s.top());
            s.pop(); 
        }
    }

    return maxWidth;
}

int main() {
    int n, ip;
    cout << "Enter the size of your vector: ";
    cin >> n;
    vector<int> v(n); 

    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "Maximum Width Ramp is: " << solve(v) << endl;
    return 0;
}
