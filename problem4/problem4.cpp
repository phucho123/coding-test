#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &v, int step)
{
    vector<int> v2;    // Vector to store non-default values from v
    vector<int> index; // Vector to store indices of non-default values in v

    // Iterate through v to collect non-default values and their indices
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != -1)
        {
            v2.push_back(v[i]); // Store non-default value
            index.push_back(i); // Store index of non-default value
        }
    }

    int n = v2.size(); // Number of non-default values in v

    vector<int> res; // Result vector to store rotated array

    // Iterate through v2 to determine the new positions after rotation
    for (int i = 0; i < v2.size(); i++)
    {
        // Calculate the new index after rotating to the right
        int new_index = (i + n - step) % n;

        // Adjust the current index to account for default values before v2[new_index]
        int cur_index = index[new_index] - 1;

        // Add default values (-1) before v2[new_index] to the result vector
        while (cur_index >= 0 && v[cur_index] == -1)
        {
            res.push_back(-1);
            cur_index--;
        }

        // Add v2[new_index] to the result vector
        res.push_back(v2[new_index]);
    }

    return res; // Return the rotated array
}

int main()
{
    // Use -1 instead of None
    vector<int> v = {1, -1, 2, -1, 3};
    vector<int> res = solve(v, 2);

    // Print the result in the required format
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
