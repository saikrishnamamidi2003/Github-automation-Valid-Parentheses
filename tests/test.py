import sys
import os

# Ensure the parent directory is in the Python path
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from solutions.solution import Solution


def run_test_case(s, expected, passed_count, total):
    total[0] += 1
    solution = Solution()  # Create an instance of Solution
    actual = solution.isValid(s)  # Call the instance method

    if actual == expected:
        passed_count[0] += 1
        print(f"\n✅ {passed_count[0]}")
    else:
        print("\n❌ Test failed for input:", s)
        print(f"Actual: {actual}, Expected: {expected}")

# ✅ Main function to run all test cases
def main():
    passed_count = [0]
    total = [0]

    # ✅ Basic Cases
    run_test_case("()", True, passed_count, total)
    run_test_case("()[]{}", True, passed_count, total)
    run_test_case("(]", False, passed_count, total)
    run_test_case("([)]", False, passed_count, total)
    run_test_case("{[]}", True, passed_count, total)

    # ✅ Edge Cases
    run_test_case("", True, passed_count, total)  # Empty string is valid
    run_test_case("(((((((((())))))))))", True, passed_count, total)
    run_test_case("(((((((()", False, passed_count, total)
    run_test_case("]}", False, passed_count, total)
    run_test_case("(((((((((()))))))))))", False, passed_count, total)

    # ✅ Summary
    print(f"\nPassed {passed_count[0]} / {total[0]} test cases!")
    if passed_count[0] != total[0]:
        raise AssertionError("Some test cases failed!")

if __name__ == "__main__":
    main()
