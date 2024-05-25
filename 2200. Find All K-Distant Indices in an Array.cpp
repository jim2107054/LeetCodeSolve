#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> index;
        vector<int> ans;

        // Collect all indices where the key occurs
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == key) {
                index.push_back(i);
            }
        }

        // Find all indices within k distance from any key index
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < index.size(); ++j) {
                if (abs(i - index[j]) <= k) {
                    ans.push_back(i);
                    break;  // No need to check further once the condition is met
                }
            }
        }

        // Remove duplicates if any
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {734, 228, 636, 204, 552, 732, 686, 461, 973, 874, 90, 537, 939, 986, 855, 387, 344, 939, 552, 389, 116, 93, 545, 805, 572, 306, 157, 899, 276, 479, 337, 219, 936, 416, 457, 612, 795, 221, 51, 363, 667, 112, 686, 21, 416, 264, 942, 2, 127, 47, 151, 277, 603, 842, 586, 630, 508, 147, 866, 434, 973, 216, 656, 413, 504, 360, 990, 228, 22, 368, 660, 945, 99, 685, 28, 725, 673, 545, 918, 733, 158, 254, 207, 742, 705, 432, 771, 578, 549, 228, 766, 998, 782, 757, 561, 444, 426, 625, 706, 946};
    int key = 939;
    int k = 34;
    vector<int> result = solution.findKDistantIndices(nums, key, k);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
