#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int k_beauty(const string& sub, int num) {
        int divisor = stoi(sub); //string to integer conversion.
        if (divisor == 0) return 0; // Handle the case where the substring is "0"
        return (num % divisor == 0) ? 1 : 0;
    }
public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        string nums = to_string(num);
        for (int i = 0; i <= nums.size() - k; ++i){
            string sub = nums.substr(i, k);//get a sub string which is start at i'th position and length is=k.
            ans += k_beauty(sub, num);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int num = 120;
    int k = 2;
    cout << solution.divisorSubstrings(num, k) << endl; // Example usage
    return 0;
}

