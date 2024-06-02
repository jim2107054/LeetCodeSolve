class Solution {
private:
    int firstOccurence(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int result = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                result = mid;
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return result;
    }

    int lastOccurence(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int result = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                result = mid;
                start = mid + 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return result;
    }

    int solve(vector<int>& nums, int a, int b) {
        if (a > b) swap(a, b);
        int index1 = firstOccurence(nums, a);
        int index2 = lastOccurence(nums, b);

        if (index1 == -1 || index2 == -1) return 0;
        return index2 - index1 + 1;
    }

public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] - nums[i] == 1) {
                int ans = solve(nums, nums[i], nums[i + 1]);
                result = max(result, ans);
            }
        }
        return result;
    }
};
