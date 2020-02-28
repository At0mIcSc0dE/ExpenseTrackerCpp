#include "JSON.h"

JSON::JSON(const char* path)
	:path(path)
{
	read();
}

JSON::~JSON() {

}


void JSON::read() {
	FILE* fp = fopen(path, "rb");

	char readBuffer[65536];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	d.ParseStream(is);

	fclose(fp);

	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	d.Accept(writer);

}