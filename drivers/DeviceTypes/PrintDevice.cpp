
#include <stdio.h>
#include <string.h>
#include "PrintDevice.h"

#include "driverlib/debug.h"

int PrintDevice::print(const char* str) {
	ASSERT(str != NULL);
	return write(str, strlen(str));
}

int PrintDevice::print(int num) {
	if (num < 0) {
		write('-');
		num = -num;
	};

	return print((unsigned int)num, DEC);
}

int PrintDevice::print(unsigned int num, unsigned int base) {
	ASSERT(base == BIN || base == OCT || base == DEC || base == HEX);

	char buf[INT_MAX_DIGITS + 1];	// +1 for null-termination

	char* str = &buf[INT_MAX_DIGITS];	// go to the end of the buffer
	*str = '\0';

	do {
		int c = num % base;
		num /= base;

		*--str = convtable[c];
	}
	while (num);

	return print(str);
}

int PrintDevice::newline() {
	return print(CRLF);
}

int PrintDevice::println(const char* buf, int len) {
	int retval = write(buf, len);
	retval += newline();

	return retval;
}

int PrintDevice::println(char c) {
	int retval = write(c);
	retval += newline();

	return retval;
}

int PrintDevice::println(const char* str) {
	int retval = print(str);
	retval += newline();

	return retval;
}

int PrintDevice::println(int num) {
	int retval = print(num);
	retval += newline();

	return retval;
}

int PrintDevice::println(unsigned int num, unsigned int base) {
	int retval = print(num, base);
	retval += newline();

	return retval;
}
