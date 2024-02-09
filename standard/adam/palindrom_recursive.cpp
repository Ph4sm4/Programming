#include <iostream>
#include <string>
using namespace std;

// Function to check if a string is a palindrome recursively
bool isPalindrome(const string &str, int start, int end)
{
    // Base case: if start and end indices cross each other
    if (start >= end)
        return true;
    // Check if characters at start and end positions are equal
    if (str[start] != str[end])
        return false;
    // Recursively check the substring excluding the start and end characters
    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str, 0, str.length() - 1))
    {
        cout << str << " is a palindrome." << endl;
    }
    else
    {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}
