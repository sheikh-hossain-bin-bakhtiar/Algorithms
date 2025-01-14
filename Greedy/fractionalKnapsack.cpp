#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Item
{
    float profit, weight;
};

bool compareRatio(Item a, Item b)
{
    return (a.profit/a.weight) > (b.profit/b.weight);
}

float fractionalKnapsack(float w, vector<Item> &items)
{
    sort(items.begin(), items.end(), compareRatio);
    
    float currentWeight = 0.0;
    float maxProfit = 0.0;

    for(int i = 0; i < items.size(); i++)
    {
        if(currentWeight + items[i].weight <= w)
        {
            currentWeight += items[i].weight;
            maxProfit += items[i].profit;
        }
        else
        {
            float remainingWeight = w - currentWeight;
            maxProfit += items[i].profit * (remainingWeight/items[i].weight);
            break;
        }
    }
    return maxProfit;
}

int main()
{
    int n;
    cout << "Number of objects: ";
    cin >> n;

    float w;
    cout << "Capacity: ";
    cin >> w;

    vector<Item> items(n);

    for(int i = 0; i < n; i++)
    {
        cin >> items[i].profit >> items[i].weight; 
    }

    float maxProfit = fractionalKnapsack(w, items);

    cout << maxProfit << endl;

}