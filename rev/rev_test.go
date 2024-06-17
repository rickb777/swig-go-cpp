package rev

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
