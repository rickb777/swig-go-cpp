package cpp

import "testing"

func TestSimpleReverse(t *testing.T) {
	rev := NewReverse()
	defer DeleteReverse(rev)

	msg := "Hello world!"
	gsm := rev.Reverse(&msg)
	if gsm != "!dlrow olleH" {
		t.Error("Got", gsm)
	}
}

func TestEmptyReverse(t *testing.T) {
	rev := NewReverse()
	defer DeleteReverse(rev)

	msg := ""
	gsm := rev.Reverse(&msg)
	if gsm != "" {
		t.Error("Got", gsm)
	}
}

func TestPalindrome(t *testing.T) {
	pally := NewPalindrome()
	defer DeletePalindrome(pally)

	if pally.IsPalindrome("foo") {
		t.Error("foo is not a palindrome")
	}

	if !pally.IsPalindrome("mum") {
		t.Error("mum is not a palindrome")
	}

	if !pally.IsPalindrome("") {
		t.Error("'' is not a palindrome")
	}
}
