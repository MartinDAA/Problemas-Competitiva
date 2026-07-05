#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution { 
public: 
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {


    vector<int> nums;
    int x;

    while (cin >> x) {
        nums.push_back(x);
    }
    
    Solution sol;
    int result = sol.lengthOfLIS(nums);
    
    cout << "Output: " << result << "\n";

    return 0;
}