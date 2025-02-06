package contacts

import (
	"testing"
	"time"
)

func TestContact(t *testing.T) {
	d := NewDate()
	defer DeleteDate(d)

	d.SetYear(2001)
	d.SetMonth(int(time.November))
	d.SetDay(22)

	s1 := d.String()
	if s1 != "2001-11-22" {
		t.Errorf("got %q, want %q", s1, "2001-11-22")
	}

	d.SetYear(1991)
	d.SetMonth(int(time.February))
	d.SetDay(7)

	s2 := d.String()
	if s2 != "1991-02-07" {
		t.Errorf("got %q, want %q", s2, "1991-02-07")
	}
}
