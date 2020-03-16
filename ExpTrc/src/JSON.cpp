/*.cpp file for JSON class*/

#include "JSON.h"
#include <fstream>

JSON::JSON(const char* path, const char* startDocument)
	:path(path), d(kObjectType)
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

	FILE* fp = fopen(path, "wb");

	char writeBuffer[65536];
	FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));

	PrettyWriter<FileWriteStream> writer(os);
	d.Accept(writer);

	fclose(fp);

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


void JSON::updateIndex(short unsigned int userID, short unsigned int indexOfDeletedElement, const char* expTime) {

	std::vector<int> listOfAllIndices;
	for (unsigned int i = 0; i < d["General"]["expID"][TOCHARPTR(userID)]["OneTimeExpense"].GetInt(); ++i) {
		listOfAllIndices.emplace_back(i);
	}

	std::reverse(listOfAllIndices.begin(), listOfAllIndices.end());

	for (unsigned int i = indexOfDeletedElement; i < d["General"]["expID"][TOCHARPTR(userID)][expTime].GetInt(); ++i) {
		Value::MemberIterator itrExpID = d[expTime][TOCHARPTR(userID)].FindMember(Value().SetString(TOCHARPTR(i), alloc));

		Value copyAttrVal(kObjectType);

		//TODO: only works with one element(I beleave) and update d[expid][userid][expTime] index

		copyAttrVal.AddMember("expName", Value().SetString(d[expTime][TOCHARPTR(userID)][TOCHARPTR(i)]["expName"].GetString(), alloc), alloc);
		copyAttrVal.AddMember("expPrice", Value().SetDouble(d[expTime][TOCHARPTR(userID)][TOCHARPTR(i)]["expPrice"].GetDouble()), alloc);
		copyAttrVal.AddMember("expInfo", Value().SetString(d[expTime][TOCHARPTR(userID)][TOCHARPTR(i)]["expInfo"].GetString(), alloc), alloc);
		copyAttrVal.AddMember("expDay", Value().SetInt(d[expTime][TOCHARPTR(userID)][TOCHARPTR(i)]["expDay"].GetInt()), alloc);
		copyAttrVal.AddMember("expMonth", Value().SetInt(d[expTime][TOCHARPTR(userID)][TOCHARPTR(i)]["expMonth"].GetInt()), alloc);
		copyAttrVal.AddMember("expYear", Value().SetInt(d[expTime][TOCHARPTR(userID)][TOCHARPTR(i)]["expYear"].GetInt()), alloc);
		copyAttrVal.AddMember("expCat", Value().SetString(d[expTime][TOCHARPTR(userID)][TOCHARPTR(i)]["expCat"].GetString(), alloc), alloc);

		//Replace member by removing it first and adding it witch the correct index
		d[expTime][TOCHARPTR(userID)].RemoveMember(itrExpID);

		d[expTime][TOCHARPTR(userID)].AddMember(Value().SetString(TOCHARPTR(i - 1), alloc), copyAttrVal, alloc);
	}
	write();

}