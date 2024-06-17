// By Thom Troy
// see https://github.com/ttroy50/cmake-examples/tree/master/05-unit-testing/google-test-download
// https://github.com/ttroy50/cmake-examples/blob/master/LICENSE

#include "Palindrome.h"

bool Palindrome::isPalindrome(const std::string& toCheck)
{
    return (toCheck == std::string(toCheck.rbegin(), toCheck.rend()));
}
