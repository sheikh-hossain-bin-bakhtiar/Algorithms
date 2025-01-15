#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findLCS(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    // Create a DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int lcsLength = dp[m][n];
    cout << "Length of LCS: " << lcsLength << endl;

    // Reconstruct the LCS
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "LCS: \"" << lcs << "\"" << endl;
}

int main() {
    string string1, string2;

    cout << "Enter first string: ";
    cin >> string1;

    cout << "Enter second string: ";
    cin >> string2;

    findLCS(string1, string2);

    return 0;
}
