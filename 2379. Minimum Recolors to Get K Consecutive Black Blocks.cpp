#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int checkWhite(const string& s) {
        int cnt = 0;
        for (char ch : s) {
            if (ch == 'W') cnt++;
        }
        return cnt;
    }

public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        for (int i = 0; i <= blocks.size() - k; i++) {
            string sub = blocks.substr(i, k);
            int white = checkWhite(sub);
            ans = min(ans, white);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string blocks = "WBBWWBBWBW";
    int k = 7;
    int result = solution.minimumRecolors(blocks, k);
    cout << "Minimum recolors needed: " << result << endl;
    return 0;
}
