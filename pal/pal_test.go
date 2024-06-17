package pal

import "testing"

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
