#include <unistd.h>
#include "myio.h"

enum {
	NBUF = 128,
};

static char buf[NBUF];
static int idx;

static int
append(char c) {
	if(idx == NBUF) {
		write(1, buf, idx);
		idx = 0;
	}
	buf[idx] = c;
	idx++;
	return 1;
}

static int
handlefmt(char spec, int val) {
	char digits[10];
	int digidx;
	int n;

	switch(spec) {
	case 'd':
		if(val == 0) {
			return append('0');
		}
		digidx = 0;
		while(val > 0) {
			digits[digidx] = val % 10 +'0';
			digidx++;
			val /= 10;
		}
		n = 0;
		while(digidx > 0) {
			digidx--;
			n += append(digits[digidx]);
		}
		return n;
	}
}
	
int
print(char *fmt, int val) {
	char *p;
	int num;

	num = 0;
	idx = 0;
	for(p = fmt; *p != '\0'; ++p) {
		if(*p == '%') {
			p++;
			num += handlefmt(*p, val);
		}
		else {
			num += append(*p);
		}
	}
	if(idx > 0) {
		write(1, buf, idx);
	}
	return num;
}

