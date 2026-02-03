#include <vector>
#include <iostream>
#include <vector>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    double r1=(double)a.first/a.second;
    double r2=(double)b.first/b.second;
    return r1>r2; //for descending order
}
int main()
{
    int n;
    cout << "Enter number of weights: ";
    cin >> n;
    int capacity, weight, value;
    cout << "Enter maximum capacity: ";
    cin >> capacity;
    vector <pair <int, int>> vec;
    cout << "Enter the weight - value pairs: \n";
    for(int i=0; i<n; i++)
    {
        cin >> weight;
        cin >> value;
        vec.push_back(make_pair(value, weight));
    }
    sort(vec.begin(), vec.end(), cmp);
    double currc=0.0, currv=0.0;
    for(int i=0; i<n; i++)
    {
        if(currc+vec[i].second<=capacity)
        {
            currv+=vec[i].first;
            currc+=vec[i].second;
        }
        else
        {
            double rem=capacity-currc;
            currv+=rem*(double)(vec[i].first/vec[i].second);
            break;
        }
    }
    cout << "Maximum value: "<<currv;
}
