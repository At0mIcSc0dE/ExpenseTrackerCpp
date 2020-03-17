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


void JSON::updateIndex(const char* userID, short unsigned int indexOfDeletedElement, const char* expTime, unsigned short int addOrDelete) {

	if (addOrDelete == DELEXP) {
		//-1 from expTime index
		d["General"]["expID"][userID][expTime] = Value().SetInt(d["General"]["expID"][userID][expTime].GetInt() - 1);

		//check if expTime only has one member
		if (d[expTime][userID].FindMember(TOCHARPTR(indexOfDeletedElement + 1)) == d[expTime][userID].MemberEnd())
			return;
	}


	std::vector<int> listOfAllIndices;
	for (unsigned int i = 0; i < d["General"]["expID"][userID]["OneTimeExpense"].GetInt(); ++i) {
		listOfAllIndices.emplace_back(i);
	}

	std::reverse(listOfAllIndices.begin(), listOfAllIndices.end());

	if (addOrDelete == DELEXP) {
		for (unsigned int i = indexOfDeletedElement + 1; i <= d["General"]["expID"][userID][expTime].GetInt() + 1; ++i) {
			changeMemberName(userID, expTime, i, addOrDelete);
		}
	}
	else {
		for (unsigned int i = 0; i < d["General"]["expID"][userID][expTime].GetInt(); ++i) {
			changeMemberName(userID, expTime, i, addOrDelete);
		}
	}
	write();

}


void JSON::changeMemberName(const char* userID, const char* expTime, unsigned int i, unsigned short int addOrDelete) {
	Value::MemberIterator itrExpID = d[expTime][userID].FindMember(Value().SetString(TOCHARPTR(i), alloc));

	Value copyAttrVal(kObjectType);

	copyAttrVal.AddMember("expName", Value().SetString(d[expTime][userID][TOCHARPTR(i)]["expName"].GetString(), alloc), alloc);
	copyAttrVal.AddMember("expPrice", Value().SetDouble(d[expTime][userID][TOCHARPTR(i)]["expPrice"].GetDouble()), alloc);
	copyAttrVal.AddMember("expInfo", Value().SetString(d[expTime][userID][TOCHARPTR(i)]["expInfo"].GetString(), alloc), alloc);
	copyAttrVal.AddMember("expDay", Value().SetInt(d[expTime][userID][TOCHARPTR(i)]["expDay"].GetInt()), alloc);
	copyAttrVal.AddMember("expMonth", Value().SetInt(d[expTime][userID][TOCHARPTR(i)]["expMonth"].GetInt()), alloc);
	copyAttrVal.AddMember("expYear", Value().SetInt(d[expTime][userID][TOCHARPTR(i)]["expYear"].GetInt()), alloc);
	copyAttrVal.AddMember("expCat", Value().SetString(d[expTime][userID][TOCHARPTR(i)]["expCat"].GetString(), alloc), alloc);

	//Replace member by removing it first and adding it witch the correct index
	d[expTime][userID].RemoveMember(itrExpID);

	if (addOrDelete == DELEXP)
		d[expTime][userID].AddMember(Value().SetString(TOCHARPTR(i - 1), alloc), copyAttrVal, alloc);
	else
		d[expTime][userID].AddMember(Value().SetString(TOCHARPTR(i + 1), alloc), copyAttrVal, alloc);
}
