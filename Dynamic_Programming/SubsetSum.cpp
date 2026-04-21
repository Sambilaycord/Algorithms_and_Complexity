#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(vector<int>& nums, int target, vector<int>& subset) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base case: if target is 0, then it's always possible (with an empty subset)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j < nums[i - 1]) {
                // If the current number is greater than the target, exclude it
                dp[i][j] = dp[i - 1][j];
            } else {
                // Either include the current number or exclude it
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    // Backtrack to find the subset
    if (dp[n][target]) {
        int i = n, j = target;
        while (j > 0) {
            if (dp[i - 1][j]) {
                i--;
            } else {
                subset.push_back(nums[i - 1]);
                j -= nums[i - 1];
                i--;
            }
        }
    }

    return dp[n][target];
}

int main() {
    vector<int> nums = {3, 2, 7};
    int target = 5;
    vector<int> subset;

    cout << "Set: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "\nTarget sum: " << target << "\nResult: " << (subsetSum(nums, target, subset) ? "True" : "False");

    if (!subset.empty()) {
        cout << " (Subset: [";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "])";
    }
    cout << endl;

    return 0;
}