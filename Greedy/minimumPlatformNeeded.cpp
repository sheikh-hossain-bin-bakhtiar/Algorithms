#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of platforms required
int findPlatform(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platform_needed = 1, result = 1;
    int i = 1, j = 0;

    //200 210 300 320 350 500
    //230 320 340 400 430 520


    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platform_needed++;
            i++;
        } else {
            platform_needed--;
            j++;
        }
        result = max(result, platform_needed);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    int arr[n], dep[n];

    cout << "Arrival: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Departure: ";
    for(int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }
    cout << findPlatform(arr, dep, n);
    return 0;
}
