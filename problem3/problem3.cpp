#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem of grouping anagrams
vector<vector<string>> solve(vector<string> list)
{
    int n = list.size();                       // Number of strings in the list
    unordered_map<string, vector<string>> map; // Map to store groups of anagrams
    vector<vector<string>> res;                // Result vector of vectors to store grouped anagrams

    // Iterate through each string in the list
    for (int i = 0; i < n; i++)
    {
        vector<int> cnt(26); // Array to count occurrences of each character (a-z) in the current string

        // Count occurrences of each character in the current string
        for (char ch : list[i])
        {
            cnt[ch - 'a']++;
        }

        string cur = "";

        // Construct a key for the current string based on character counts
        for (int j = 0; j < 26; j++)
        {
            cur += to_string(cnt[j]) + ","; // Append the count of each character to the key
        }

        // Store the current string in the map under its key (anagram group)
        map[cur].push_back(list[i]);
    }

    // Store all anagram groups from the map into the result vector
    for (auto &pair : map)
    {
        res.push_back(pair.second);
    }

    return res; // Return the grouped anagrams
}

int main()
{
    vector<string> list = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = solve(list);

    // Print the result in the required format
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j < res[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i < res.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}
