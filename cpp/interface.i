%module cpp
%include "std_string.i"

%{
#include <string>
#include "Reverse.h"
#include "Palindrome.h"
%}

// %include <string>
%include "Reverse.h"
%include "Palindrome.h"
