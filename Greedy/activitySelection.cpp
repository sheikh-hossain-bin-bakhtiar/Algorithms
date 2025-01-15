#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Activity
{
    int start, end;
};

bool compareActivity(Activity a, Activity b)
{
    return a.end < b.end;
}

int activitySelection(vector<Activity> &activities, int n)
{
    sort(activities.begin(), activities.end(), compareActivity);

    int count = 1;
    int lastEnd = activities[0].end;

    // if the second element of start vector is greater than equal to the previously selected end`s activity then it will be counted
    for(int i = 1; i < activities.size(); i++)
    {
        if(activities[i].start >= lastEnd)
        {
            count++;
            lastEnd = activities[i].end;
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<Activity> activities(n);

    for(int i = 0; i < n; i++)
    {
        cin >> activities[i].start >> activities[i].end;
    }

    cout << activitySelection(activities, n) << endl;

    return 0;
}
