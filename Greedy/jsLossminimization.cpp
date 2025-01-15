#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int loss;
    int time;
};

bool compareLoss(Job a, Job b) 
{
    return a.loss > b.loss;
}

void jobSequencing(vector<Job>& jobs, int n) 
{
    // Sort jobs by loss in descending order
    sort(jobs.begin(), jobs.end(), compareLoss);

    int totalTime = 0;
    int totalLoss = 0;

    cout << "Job sequence for minimum loss: ";

    for (int i = 0; i < n; i++) 
    {
        totalTime += jobs[i].time;
        int delay = totalTime - jobs[i].time;
        totalLoss += delay * jobs[i].loss;

        // Output the job id in the sequence
        cout << jobs[i].loss << " ";
    }

    cout << endl;
    cout << "Total Loss: " << totalLoss << endl;
}

int main() 
{
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; i++) 
    {
        cout << "loss per day: ";
        cin >> jobs[i].loss;
        cout << "time required: ";
        cin >> jobs[i].time;
    }

    jobSequencing(jobs, n);

    return 0;
}
