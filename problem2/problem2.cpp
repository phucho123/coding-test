#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is a valid alphanumeric character (0-9 or a-z)
bool checkValid(char ch)
{
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')) // Check if digit or lowercase letter
        return true;
    return false;
}

// Function to solve the problem of checking if a string is a valid palindrome
bool solve(string s)
{
    int l = 0, r = s.size() - 1; // Initialize left and right pointers

    while (l < r)
    {
        char ch1 = tolower(s[l]); // Convert character to lowercase
        char ch2 = tolower(s[r]); // Convert character to lowercase

        // Move left pointer to the next valid alphanumeric character
        while (l < r && !checkValid(ch1))
        {
            l++;
            ch1 = tolower(s[l]);
        }

        // Move right pointer to the previous valid alphanumeric character
        while (l < r && !checkValid(ch2))
        {
            r--;
            ch2 = tolower(s[r]);
        }

        // If characters at left and right pointers are not equal, it's not a palindrome
        if (ch1 != ch2)
            return false;

        l++; // Move left pointer forward
        r--; // Move right pointer backward
    }

    return true; // If all checks pass, it's a valid palindrome
}

int main()
{
    // Test the solve function with a sample string
    cout << solve("A man, a plan, a canal, Panama");
    return 0;
}
