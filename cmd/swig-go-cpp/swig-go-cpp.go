package main

import (
	"example.com/swig-essay/cpp"
	"fmt"
)

func main() {
	msg := "Hello world!"
	fmt.Println(msg)

	rev := cpp.NewReverse()
	defer cpp.DeleteReverse(rev)
	gsm := rev.Reverse(&msg)
	fmt.Println(gsm)
}
