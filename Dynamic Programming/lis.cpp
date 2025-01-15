#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    int maxLength = 0, lastIndex = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            lastIndex = i;
        }
    }

    vector<int> lis;
    for (int i = lastIndex; i >= 0; i = prev[i]) {
        lis.push_back(nums[i]);
    }
    reverse(lis.begin(), lis.end());

    cout << maxLength << endl;
    for (int i = 0; i < lis.size(); ++i) {
        cout << lis[i];
        if (i < lis.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    findLIS(nums);

    return 0;
}
