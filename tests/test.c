#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "../solutions/solution.c"  // Make sure isValid is in solution.c

// Function to run individual test cases
void runTestCase(char *s, bool expected, int *passedCount, int *total) {
    (*total)++;
    bool actual = isValid(s);

    if (actual == expected) {
        (*passedCount)++;
        printf("\n✅ %d", *passedCount);
    } else {
        printf("\n❌ Test failed for input: \"%s\"", s);
        printf("\nActual: %s, Expected: %s\n", actual ? "true" : "false", expected ? "true" : "false");
    }
}

// Main function to run all test cases
int main() {
    int passedCount = 0;
    int total = 0;

    // ✅ Basic Cases
    runTestCase("()", true, &passedCount, &total);
    runTestCase("()[]{}", true, &passedCount, &total);
    runTestCase("(]", false, &passedCount, &total);
    runTestCase("([)]", false, &passedCount, &total);
    runTestCase("{[]}", true, &passedCount, &total);

    // ✅ Edge Cases
    runTestCase("", true, &passedCount, &total); // Empty string is valid
    runTestCase("(", false, &passedCount, &total);
    runTestCase(")", false, &passedCount, &total);
    runTestCase("{", false, &passedCount, &total);
    runTestCase("}", false, &passedCount, &total);

    // ✅ Nested and complex cases
    runTestCase("((({[]})))", true, &passedCount, &total);
    runTestCase("[({(())}[()])]", true, &passedCount, &total);
    runTestCase("[({(())}[()])]}", false, &passedCount, &total);

    // ✅ Summary
    printf("\nPassed %d / %d test cases!\n", passedCount, total);
    if (passedCount != total) {
        assert(0); // Force failure if any test fails
    }

    return 0;
}
