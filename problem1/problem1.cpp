#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem
void solve(int x, int y)
{
    // Loop through numbers from 1 to 100
    for (int i = 1; i <= 100; i++)
    {
        // Check if current number is divisible by both x and y
        if (i % x == 0 && i % y == 0)
        {
            cout << "FooBar" << endl; // Print "FooBar"
        }
        // Check if current number is divisible by x only
        else if (i % x == 0)
        {
            cout << "Foo" << endl; // Print "Foo"
        }
        // Check if current number is divisible by y only
        else if (i % y == 0)
        {
            cout << "Bar" << endl; // Print "Bar"
        }
        // Otherwise, print the current number
        else
        {
            cout << i << endl; // Print the number itself
        }
    }
}

// Main function
int main()
{
    solve(3, 5); // Call the solve function with x = 3 and y = 5
    return 0;
}
