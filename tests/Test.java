package tests; // ✅ Define package name

import solutions.Solution; // ✅ Import the Solution class

public class Test {
    private static int passed = 0;
    private static int total = 0;

    public static void runTestCase(String input, boolean expected) {
        total++;
        boolean actual = Solution.isValid(input);

        if (actual == expected) {
            passed++;
            System.out.println("✅ Test Passed");
        } else {
            System.out.println("❌ Test Failed for input: \"" + input + "\"");
            System.out.println("   Expected: " + expected);
            System.out.println("   Actual  : " + actual);
        }
    }

    public static void main(String[] args) {
        runTestCase("()", true);
        runTestCase("()[]{}", true);
        runTestCase("(]", false);
        runTestCase("([)]", false);
        runTestCase("{[]}", true);
        runTestCase("(", false);
        runTestCase("]", false);
        runTestCase("", true);
        runTestCase("{[()()]}", true);
        runTestCase("{[(])}", false);

        System.out.printf("\n✅ Passed %d / %d test cases!\n", passed, total);
        if (passed != total) {
            throw new AssertionError("Some test cases failed!");
        }
    }
}

