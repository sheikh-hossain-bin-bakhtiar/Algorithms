#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>& nums, int n, int target) {
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if (!dp[n][target]) {
        cout << "No" << endl;
        return false;
    }

    vector<int> subset;
    int i = n, j = target;
    while (i > 0 && j > 0) {
        if (dp[i - 1][j]) {
            i--;
        } else {
            subset.push_back(nums[i - 1]);
            j -= nums[i - 1];
            i--;
        }
    }

    cout << "Yes" << endl;
    cout << "Subset: ";
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;

    return true;
}

int main() {
    int n, target;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cin >> target;

    isSubsetSum(nums, n, target);
    return 0;
}
