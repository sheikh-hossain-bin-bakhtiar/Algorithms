#include <iostream>
#include <vector>
using namespace std;

bool canMakeSum(vector<int>& coins, int K) {
    // Create a DP array to store whether a sum is possible
    vector<bool> dp(K + 1, false);
    dp[0] = true; // Base case: Sum 0 is always possible

    // Fill the DP table
    for (int coin : coins) {
        for (int j = coin; j <= K; j++) {
            if (dp[j - coin]) {
                dp[j] = true;
            }
        }
    }

    // Return whether K is possible
    return dp[K];
}

int main() {
    int n, K;

    // Input the number of coin types
    cout << "Enter the number of coin types: ";
    cin >> n;

    vector<int> coins(n);

    // Input the coin values
    cout << "Enter the coin values: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Input the target sum K
    cout << "Enter the target sum (K): ";
    cin >> K;

    // Check if it's possible to make the sum
    if (canMakeSum(coins, K)) {
        cout << "Yes, it is possible to generate " << K << " using the coins." << endl;
    } else {
        cout << "No, it is not possible to generate " << K << " using the coins." << endl;
    }

    return 0;
}
