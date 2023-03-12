#include <iostream>
using namespace std;

int minimumTurns(int n, int p)
{
    n /= 2;
    p = (p % 2 == 0 ? p : (p - 1)) / 2;

    return p < n - p ? p : n - p;
}

int main()
{
    int n, p;
    cin >> n >> p;
    cout << minimumTurns(n, p);

    return 0;
}