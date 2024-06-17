#include <iostream>
#include "pal/Palindrome.h"
#include "rev/Reverse.h"

int main(int argc, char *argv[])
{
	Palindrome pally;
	std::cout << "mum" << pally.isPalindrome("mum") << std::endl;
	std::cout << "mother" << pally.isPalindrome("mother") << std::endl;

    std::string msg = "Hello world!";
    Reverse rever;
    std::cout << msg << " " << rever.reverse(msg) << std::endl;

    return 0;
}
