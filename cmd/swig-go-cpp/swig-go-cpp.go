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
	fmt.Println("mum", pally.IsPalindrome("mum"))
	fmt.Println("mother", pally.IsPalindrome("mother"))

	rever := rev.NewReverse()
	defer rev.DeleteReverse(rever)
	gsm := rever.Reverse(&msg)
	fmt.Println(gsm)
}
