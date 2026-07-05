#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct FenwickTree {
        int N;
        vector<int> cnt;

        FenwickTree(int n) {
            N = n + 1;
            cnt.assign(N, 0);
        }

        void add(int i) {
            for (i++; i < N; i += (i & -i))
                cnt[i]++;
        }

        int find(int i) {
            int ans = 0;
            for (i++; i > 0; i -= (i & -i))
                ans += cnt[i];
            return ans;
        }
    };

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        vector<int> ans(n, 0);
        
        int shift = INT_MAX, max_val = INT_MIN;
        for (int i : nums) {
            shift = i < shift ? i : shift;
            max_val = i > max_val ? i : max_val;
        }
        
        FenwickTree fT(max_val - shift + 1);
        
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = fT.find(nums[i] - shift);
            fT.add(nums[i] - shift + 1);
        }

        return ans;
    }
};

int main() {

    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> resultado = sol.countSmaller(nums);

    cout << "Output\n";
    for (int i = 0; i < n; i++) {
        cout << resultado[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}