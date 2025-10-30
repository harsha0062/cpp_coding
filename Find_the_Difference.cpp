#include <iostream>
#include <string>
using namespace std;

// Function to find the extra character added in string t
char findTheDifference(string s, string t)
{
    int sum_s = 0, sum_t = 0;

    // Calculate sum of ASCII values of all characters in s
    for (char c : s)
    {
        sum_s += c;
    }

    // Calculate sum of ASCII values of all characters in t
    for (char c : t)
    {
        sum_t += c;
    }

    // The difference will give the added character
    return char(sum_t - sum_s);
}

int main()
{
    // Example input strings where t contains all characters of s plus one extra
    string s = "abcd";
    string t = "abcde";

    // Call the function and output the result
    char result = findTheDifference(s, t);
    cout << "The extra character is: " << result << endl;

    return 0;
}
