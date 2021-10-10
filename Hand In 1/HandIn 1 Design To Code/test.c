#pragma
#include <stdlib.h>
#include "test.h"

static item itm;

item getItmA() {
	itm.number = 5;
	itm.string = "horse";
	return itm;
}

item getItmB() {
	itm.number = 7;
	itm.string = "pig";
	return itm;
}

item getItmC() {
	itm.number = 2;
	itm.string = "cricke";
	return itm;
}

item getItmD() {
	itm.number = 1000;
	itm.string = "dragon";
	return itm;
}

item getItmE() {
	itm.number = 11;
	itm.string = "cow";
	return itm;
}