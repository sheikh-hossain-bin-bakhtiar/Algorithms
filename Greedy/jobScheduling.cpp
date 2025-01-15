#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Jobs
{
    char jid;
    int profit, deadline;
};

bool compareProfit(Jobs a, Jobs b)
{
    return a.profit > b.profit;
}

int maxDeadline(vector<Jobs> &jobs)
{
    int maxDeadline = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }
    return maxDeadline;
}


void jobScheduling(vector<Jobs> &jobs, int n)
{
    
    sort(jobs.begin(), jobs.end(), compareProfit);

    int deadline = maxDeadline(jobs);

    vector<char> ganttChart(deadline, '-');

    for (int i = 0; i < jobs.size(); i++)
    {
        int slot = min(jobs[i].deadline - 1, deadline - 1);

        while (slot >= 0 && ganttChart[slot] != '-')
        {
            slot--;
        }

        if (slot >= 0)
        {
            ganttChart[slot] = jobs[i].jid;
        }
    }

    
    for (int i = 0; i < deadline; i++)
    {
        if (ganttChart[i] != '-')
        {
            cout << ganttChart[i];
            if (i < deadline - 1) 
            {
                cout << ", ";
            }
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Number of Jobs: ";
    cin >> n;

    vector<Jobs> jobs(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Job Id: ";
        cin >> jobs[i].jid;
        cout << "Profit: ";
        cin >> jobs[i].profit;
        cout << "Deadline: ";
        cin >> jobs[i].deadline;
    }

    jobScheduling(jobs, n);

    return 0;
}
