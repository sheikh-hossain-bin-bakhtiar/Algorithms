#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int> &coins, int sum)
{
    // sort in descending order
    sort(coins.begin(), coins.end(), greater<>());

    int ta = sum;
    int ra = ta;
    int minCoin = 0;

    for(int i = 0; i < coins.size(); i++)
    {
        while(ra >= coins[i])
        {
            ra -= coins[i];
            minCoin++;
        }
    }
    return minCoin;
}

int main() {

    int n;
    cout << "Total coins: ";
    cin >> n;

    int value;
    cout << "Sum: ";
    cin >> value;

    vector<int> coins(n);

    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Minimum coin needed: " << coinChange(coins, value) << endl;
    
    return 0;
}
