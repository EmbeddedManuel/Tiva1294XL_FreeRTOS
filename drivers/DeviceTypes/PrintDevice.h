
#include "StreamDevice.h"

class PrintDevice : public StreamDevice 
{
public:
	enum BASES {BIN = 2, OCT = 8, DEC = 10, HEX = 16};

	static constexpr char LF = '\n';
	static constexpr char CR = '\r';
	static constexpr const char* CRLF = "\r\n";

	int print(const char* buf, int len) {
		return write(buf, len);
	}

	int print(char c) {
		return write(c);
	}

	int print(const char* str);

	int print(int num);
	int print(unsigned int num, unsigned int base = DEC);

	int newline();
	int println(const char* buf, int len);
	int println(char c);
	int println(const char* str);

	int println(int num);
	int println(unsigned int num);
	int println(unsigned int num, unsigned int base);

private:
	static constexpr int INT_MAX_DIGITS = 10; // int_max = 4,294,967,295, which is 10-digits wide

	#ifdef LOWERCASE_HEX
		static constexpr char* convtable = "0123456789abcdef";
	#else
		static constexpr const char* convtable = "0123456789ABCDEF";
	#endif
};
