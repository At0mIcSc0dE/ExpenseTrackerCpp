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

	//FILE* fp = fopen(path, "wb"); // write-byte

	//char writeBuffer[65536];
	//FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));

	//Writer<FileWriteStream> writer(os);
	//d.Accept(writer);

	//fclose(fp);


	std::ofstream ofs(path);
	OStreamWrapper osw(ofs);

	Writer<OStreamWrapper> writer(osw);
	d.Accept(writer);

}


void JSON::addExpMember(const char* expType, const char* userID, Value& entry) {
	
	
	if (!d.HasMember(expType)) {
		Value table(kObjectType);
		Value UserID(kArrayType);

		table.AddMember(Value().SetString(userID, alloc), UserID, alloc);
		d.AddMember(Value().SetString(expType, alloc), table, alloc);
	}

	if (d[expType][userID].IsArray()) {
		d[expType][userID].PushBack(entry, alloc);
	}
}