#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solve(vector<string> list)
{
    int n = list.size();
    unordered_map<string, vector<string>> map;
    vector<vector<string>> res;
    for (int i = 0; i < n; i++)
    {
        vector<int> cnt(26);
        for (char ch : list[i])
        {
            cnt[ch - 'a']++;
        }
        string cur = "";
        for (int j = 0; j < 26; j++)
        {
            cur += to_string(cnt[j]) + ",";
        }
        map[cur].push_back(list[i]);
    }
    for (auto &pair : map)
    {
        res.push_back(pair.second);
    }
    return res;
}
int main()
{
    vector<string> list = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = solve(list);
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