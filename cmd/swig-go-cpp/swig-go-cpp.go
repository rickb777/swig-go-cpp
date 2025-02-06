// This calls the palindrome and reverse APIs from Go via Swig interfaces.

package main

import (
	"example.com/swig-essay/pal"
	"example.com/swig-essay/rev"
	"fmt"
)

func main() {
	msg := "Hello world!"
	fmt.Println(msg)

	pally := pal.NewPalindrome()
	defer pal.DeletePalindrome(pally)
	fmt.Println("mum ", pally.IsPalindrome("mum"))
	fmt.Println("mother ", pally.IsPalindrome("mother"))

	rever := rev.NewReverse()
	defer rev.DeleteReverse(rever)
	gsm := rever.Reverse(&msg)
	fmt.Println(gsm)
}
