// By Thom Troy
// see https://github.com/ttroy50/cmake-examples/tree/master/05-unit-testing/google-test-download
// https://github.com/ttroy50/cmake-examples/blob/master/LICENSE

#ifndef __PALINDROME_H__
#define __PALINDROME_H__

#include <string>

/**
 * Trivial class to check if a string is a palindrome.
 */
class Palindrome
{
public:
    bool isPalindrome(const std::string& toCheck);
};

#endif
