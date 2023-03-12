#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int> arr1, vector<int> arr2, int k)
{

    int i = 0;
    int j = arr2.size() - 1;
    int max_sum = INT_MIN;
    int max_pair;
    while (i < arr1.size() && j >= 0)
    {
        int current_sum = arr1[i] + arr2[j];
        if (current_sum > k)
        {
            j--;
        }
        else
        {
            if (current_sum > max_sum)
            {
                max_sum = current_sum;
                max_pair = arr1[i] + arr2[j];
            }

            i++;
        }
    }
    return max_pair;
}

int main()
{
    int budget, kSize, dSize;
    cin >> budget >> kSize >> dSize;

    vector<int> keyBoard(kSize), drivers(dSize);
    for (auto &i : keyBoard)
        cin >> i;
    for (auto &i : drivers)
        cin >> i;

    sort(keyBoard.begin(), keyBoard.end());
    sort(drivers.begin(), drivers.end());

    if (keyBoard[0] + drivers[0] > budget)
        cout << -1;
    else
        cout << getMax(keyBoard, drivers, budget);

    return 0;
}
