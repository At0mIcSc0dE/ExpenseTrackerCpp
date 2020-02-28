#include "JSON.h"


JSON::JSON(const char* path, const char* startDocument)
	:path(path)
{
	//check if file exists, this is a fast way acording to stackoverflow
	//create it and parse startDocument
	struct stat buffer;
	if (stat(path, &buffer) != 0) {
		std::ofstream st(path);
		st.close();
		
		d.Parse(startDocument);  //first parse any string and write it then
		write();
	}

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
}


void JSON::write() {

	//output to file
	FILE* fp = fopen(path, "wb"); // write

	char writeBuffer[65536];
	FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));

	Writer<FileWriteStream> writer(os);
	d.Accept(writer);

	fclose(fp);
}