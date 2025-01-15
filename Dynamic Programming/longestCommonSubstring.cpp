#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findLongestCommonSubstring(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    // DP table to store the length of the common substring
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0; // Length of the longest common substring
    int endIndex = 0;  // Ending index of the longest substring in s1

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1; // Update the end index
                }
            }
        }
    }

    // Extract the longest common substring
    string lcs = s1.substr(endIndex - maxLength + 1, maxLength);

    // Print the results
    cout << "Length of Longest Common Substring: " << maxLength << endl;
    cout << "Longest Common Substring: \"" << lcs << "\"" << endl;
}

int main() {
    string string1, string2;

    // Input the two strings
    cout << "Enter first string: ";
    cin >> string1;
    cout << "Enter second string: ";
    cin >> string2;

    findLongestCommonSubstring(string1, string2);

    return 0;
}
