#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &v, int step)
{
    vector<int> v2;
    vector<int> index;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != -1)
        {
            v2.push_back(v[i]);
            index.push_back(i);
        }
    }

    int n = v2.size();

    vector<int> res;
    for (int i = 0; i < v2.size(); i++)
    {
        int new_index = (i + n - step) % n;
        int cur_index = index[new_index] - 1;
        while (cur_index >= 0 && v[cur_index] == -1)
        {
            res.push_back(-1);
            cur_index--;
        }
        res.push_back(v2[(i + n - step) % n]);
    }

    return res;
}
int main()
{
    vector<int> v = {1, -1, 2, -1, 3};
    vector<int> res = solve(v, 2);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i < res.size() - 1)
            cout << ", ";
    }
    cout << "]";
    return 0;
}