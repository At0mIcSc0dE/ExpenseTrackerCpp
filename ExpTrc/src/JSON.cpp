/*.cpp file for JSON class*/

#include "JSON.h"
#include <fstream>

JSON::JSON() { }


void JSON::setPath(const char* path) {
	this->path = path;
}


void JSON::setStartDocument(const char* msg) {
	this->startDocument = msg;
	writeStartDocument();
	read();
}


void JSON::writeStartDocument() {

	//check if file exists, this is a fast way acording to stackoverflow
	//create it and parse startDocument
	struct stat buffer;
	if (stat(path, &buffer) != 0) {
		std::ofstream st(path);
		st.close();

		d.Parse(startDocument);  //first parse any string and write it then
		write();
	}
}


JSON::JSON(const char* path, const char* startDocument)
	:path(path), d(kObjectType), startDocument(startDocument)
{
	read();
	writeStartDocument();
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


void JSON::updateIndex(const char* userID, short unsigned int indexOfDeletedElement, const char* expTime, unsigned short int addOrDelete) {

	TIMER("");

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

	short unsigned int nextID = d["General"]["expID"][userID][expTime].GetInt();
	Value::MemberIterator itrFindNextID = d[expTime][userID].FindMember(Value().SetString(TOCHARPTR(nextID), alloc));
	
	if (addOrDelete == DELEXP/* && itrFindNextID != d[expTime][userID].MemberEnd()*/) {
		for (unsigned int i = indexOfDeletedElement + 1; i <= d["General"]["expID"][userID][expTime].GetInt() + 1; ++i) {
			changeMemberName(userID, expTime, i, addOrDelete);
		}
	}
	else if(addOrDelete == ADDEXP/* && itrFindNextID != d[expTime][userID].MemberEnd()*/) {
		for (unsigned int i = 0; i < nextID; ++i) {
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


void JSON::insertItemsToListbox(Listbox* lstbox, const char* userID, const char* expTime, const char* currency) {

	TIMER("");

	Value::MemberIterator itrFindExpID = d[expTime][userID].FindMember("1");
	if (itrFindExpID == d[expTime][userID].MemberEnd())
		return;

	const char* expName;
	double expPrice;

	double durationTotal = 0;
	
	QStringList lst;

	for (int i = d["General"]["expID"][userID][expTime].GetInt(); i != 0 ; --i) {

		expName = d[expTime][userID][TOCHARPTR(i)]["expName"].GetString();
		expPrice = d[expTime][userID][TOCHARPTR(i)]["expPrice"].GetDouble();
		
		std::ostringstream streamObj;
		streamObj << std::fixed;
		streamObj << std::setprecision(2);
		streamObj << expPrice;

		lst.append(QString::fromLocal8Bit((std::string(expName) + " || " + streamObj.str() + currency).c_str()));
	}
	lstbox->insertItems(0, lst);
	std::cout << "Total duration: " << timer.duration << "ms";
}
