/*.h file for JSON class, inherits from Document
 *Library used: Rapidjson*/

#ifndef JSON_H
#define JSON_H

#include <rapidjson/filereadstream.h>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/filewritestream.h>
#include <sstream>
#include <iomanip>

#include <qmessagebox.h>
#include "Declarations.h"
#include "listbox.h"


using namespace rapidjson;

class JSON : public Document
{
public:
	const char* path;
	
	Document d;
	Document::AllocatorType& alloc = d.GetAllocator();

	//StringBuffer buffer;
	//Writer<StringBuffer> writer(buffer);
	//d.Accept(writer);

	JSON(const char* path, const char* startDocument);

	~JSON();


	void read();
	void write();
	void updateIndex(const char* userID, short unsigned int indexOfDeletedElement, const char* expTime, unsigned short int addOrDelete = ADDEXP);
	void changeMemberName(const char* userID, const char* expTime, unsigned int i, unsigned short int addOrDelete);
	void insertItemsToListbox(Listbox* lstbox, const char* userID, const char* expTime, const char* currency);

private:

};


#endif