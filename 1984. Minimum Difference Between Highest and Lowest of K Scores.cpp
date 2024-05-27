#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0; // If k is 1, the minimum difference is always 0
        sort(nums.begin(), nums.end()); // Sort the array to make finding min differences easier
        int ans = INT_MAX;

        // Find the minimum difference between the highest and lowest of k consecutive elements
        for (int i = 0; i <= nums.size() - k; ++i) {
            int diff = nums[i + k - 1] - nums[i];
            ans = min(ans, diff);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {9,4,1,7};
    int k = 2;
    int result = solution.minimumDifference(nums, k);
    cout << "Minimum difference: " << result << endl;
    return 0;
}
