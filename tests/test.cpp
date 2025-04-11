#include <bits/stdc++.h>
#include "../solutions/solution.cpp"  // Include your solution file

using namespace std;

// Function to run individual test cases
void runTestCase(string s, bool expected, int *passedCount, int *total)
{
    (*total)++;
    Solution solution;
    bool actual = solution.isValid(s);

    if (actual == expected)
    {
        (*passedCount)++;
        cout << "\n✅ " << *passedCount;
    }
    else
    {
        cout << "\n❌ Test failed for input: \"" << s << "\"";
        cout << "\nActual: " << actual << ", Expected: " << expected << endl;
    }
}

// ✅ Main function to run all test cases
int main()
{
    int passedCount = 0;
    int total = 0;

    // ✅ Basic Cases
    runTestCase("()", true, &passedCount, &total);
    runTestCase("()[]{}", true, &passedCount, &total);
    runTestCase("(]", false, &passedCount, &total);
    runTestCase("([)]", false, &passedCount, &total);
    runTestCase("{[]}", true, &passedCount, &total);

    // ✅ Edge Cases
    runTestCase("", true, &passedCount, &total);         // Empty string
    runTestCase("(", false, &passedCount, &total);       // Single open
    runTestCase(")", false, &passedCount, &total);       // Single close
    runTestCase("(((((((((())))))))))", true, &passedCount, &total); // Deep nesting

    // ✅ Invalid combinations
    runTestCase("([]", false, &passedCount, &total);
    runTestCase("{[()()]}", true, &passedCount, &total);

    // ✅ Summary
    cout << "\n\nPassed " << passedCount << " / " << total << " test cases!" << endl;
    if (passedCount != total)
    {
        assert(false);
    }

    return 0;
}
