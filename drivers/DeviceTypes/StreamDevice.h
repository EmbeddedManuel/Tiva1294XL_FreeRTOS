
#include <stdint.h>

class StreamDevice
{
public:
	virtual int write(uint8_t byte) = 0;
	virtual int write(const uint8_t* buf, int len) = 0;

	virtual int read(uint8_t byte) = 0;
	virtual int read(uint8_t* buf, int len) = 0;

//	virtual int readuntil(uint8_t match, uint8_t* buf, int maxLen) = 0;


	int write(const char* buf, int len) {
		return write((const uint8_t*)buf, len);
	}

	int read(char* buf, int len) {
		return read((uint8_t*)buf, len);
	}

//	int readuntil(char match, char* buf, int maxLen) {
//		return readuntil((uint8_t)match, (uint8_t*)buf, maxLen);
//	}
};
