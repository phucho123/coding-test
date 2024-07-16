#include <bits/stdc++.h>
using namespace std;

bool checkValid(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return true;
    return false;
}
bool solve(string s)
{
    int l = 0, r = s.size() - 1;

    while (l < r)
    {
        char ch1 = tolower(s[l]);
        char ch2 = tolower(s[r]);

        while (l < r && !checkValid(ch1))
        {
            l++;
            ch1 = tolower(s[l]);
        }

        while (l < r && !checkValid(ch2))
        {
            r--;
            ch2 = tolower(s[r]);
        }
        if (ch1 != ch2)
            return false;
        l++;
        r--;
    }

    return true;
}

int main()
{
    cout << solve("A man, a plan, a canal, Panama");
    return 0;
}