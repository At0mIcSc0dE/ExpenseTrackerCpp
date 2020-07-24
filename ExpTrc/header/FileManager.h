#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <ostream>
#include <vector>
#include <unordered_map>

#include "Declarations.h"

struct ExpenseData
{
	std::string Name;
	double Price;
	std::string Info;
	int Day;
	int Month;
	int Year;
};

struct GeneralData
{
	unsigned int CurrOneTimeExpCount;
	unsigned int CurrMonthlyExpCount;
	unsigned int CurrOneTimeTakCount;
	unsigned int CurrMonthlyTakCount;

	unsigned int userID;
	unsigned int groupID;
	double balance;
};


class FileManager
{
public:
	FileManager(const std::string& filePath1, const std::string& filePath2, const std::string& filePath3, const std::string& filePath4, const std::string& filePathG);

	ExpenseData ReadExpense(const int expID, const int expType);
	void WriteExpense(const int expType, const ExpenseData& data);
	void DeleteExpense(const int expID, const int expType);

	const GeneralData& ReadGeneral();
	void WriteGeneral(const GeneralData& data);
	
	void UpdateIndices(unsigned short index, unsigned short expTime, unsigned short addOrDelete);

	const GeneralData& GetGeneralData() const { return m_GeneralData; }

private:
	std::unordered_map<int, std::vector<std::string>> m_OneTimeExpData;
	std::unordered_map<int, std::vector<std::string>> m_MonthlyExpData;
	std::unordered_map<int, std::vector<std::string>> m_OneTimeTakData;
	std::unordered_map<int, std::vector<std::string>> m_MonthlyTakData;

	GeneralData m_GeneralData = {};

	const std::string m_FilePath1;
	const std::string m_FilePath2;
	const std::string m_FilePath3;
	const std::string m_FilePath4;
	const std::string m_FilePathG;

private:
	void Read(const std::string& filePath, std::unordered_map<int, std::vector<std::string>>& data);
	void Write(const std::string& filePath, std::unordered_map<int, std::vector<std::string>>& data);
	void AddDataToMap(const ExpenseData& data, std::unordered_map<int, std::vector<std::string>>& map);
	void RemoveFromMap(const int expID, std::unordered_map<int, std::vector<std::string>>& map);
};


#endif

