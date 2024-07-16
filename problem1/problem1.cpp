#include <bits/stdc++.h>
using namespace std;

void solve(int x, int y)
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % x == 0 && i % y == 0)
        {
            cout << "FooBar" << endl;
        }
        else if (i % x == 0)
        {
            cout << "Foo" << endl;
        }
        else if (i % y == 0)
        {
            cout << "Bar" << endl;
        }
        else
            cout << i << endl;
    }
}
int main()
{
    solve(3, 5);
    return 0;
}