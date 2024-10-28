#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> numSet(nums.begin(), nums.end()); 
        int maxStreak = 0;

        for (int num : nums) {
            long long current = num;
            int streak = 0;
            
            // Find consecutive squares in sequence
            while (numSet.find(current) != numSet.end()) {
                streak++;
                current = current * current;
                if (current > INT_MAX) break; 
            }
            
            maxStreak = max(maxStreak, streak);
        }
        
        return maxStreak <= 1 ? -1 : maxStreak;
    }
};


int main()
{
    Solution s;
    int n;
    cout<<"Enter your array size: ";
    cin>>n;
    
    vector<int>nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<"Longest square streak in nums is: "<<s.longestSquareStreak(nums)<<endl;

    return 0;
}