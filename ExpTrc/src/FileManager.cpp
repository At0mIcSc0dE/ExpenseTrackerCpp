#include "FileManager.h"



FileManager::FileManager(const std::string& filePath1, const std::string& filePath2, const std::string& filePath3, const std::string& filePath4, const std::string& filePathG)
	: m_FilePath1(filePath1), m_FilePath2(filePath2), m_FilePath3(filePath3), m_FilePath4(filePath4), m_FilePathG(filePathG)
{
	Read(filePath1, m_OneTimeExpData);
	Read(filePath2, m_MonthlyExpData);
	Read(filePath3, m_OneTimeTakData);
	Read(filePath4, m_MonthlyTakData);
	ReadGeneral();

}

ExpenseData FileManager::ReadExpense(const int expID, const int expType)
{
	ExpenseData expData{};

	switch (expType)
	{
	case ONETIME:
		expData.Name = m_OneTimeExpData[expID][0];
		expData.Price = std::stod(m_OneTimeExpData[expID][1]);
		expData.Info = m_OneTimeExpData[expID][2];
		expData.Day = std::stoi(m_OneTimeExpData[expID][3]);
		expData.Month = std::stoi(m_OneTimeExpData[expID][4]);
		expData.Year = std::stoi(m_OneTimeExpData[expID][5]);

		break;
	case MONTHLY:
		expData.Name = m_MonthlyExpData[expID][0];
		expData.Price = std::stod(m_MonthlyExpData[expID][1]);
		expData.Info = m_MonthlyExpData[expID][2];
		expData.Day = std::stoi(m_MonthlyExpData[expID][3]);
		expData.Month = std::stoi(m_MonthlyExpData[expID][4]);
		expData.Year = std::stoi(m_MonthlyExpData[expID][5]);

		break;
	case ONETIME_T:
		expData.Name = m_OneTimeTakData[expID][0];
		expData.Price = std::stod(m_OneTimeTakData[expID][1]);
		expData.Info = m_OneTimeTakData[expID][2];
		expData.Day = std::stoi(m_OneTimeTakData[expID][3]);
		expData.Month = std::stoi(m_OneTimeTakData[expID][4]);
		expData.Year = std::stoi(m_OneTimeTakData[expID][5]);

		break;
	case MONTHLY_T:
		expData.Name = m_MonthlyTakData[expID][0];
		expData.Price = std::stod(m_MonthlyTakData[expID][1]);
		expData.Info = m_MonthlyTakData[expID][2];
		expData.Day = std::stoi(m_MonthlyTakData[expID][3]);
		expData.Month = std::stoi(m_MonthlyTakData[expID][4]);
		expData.Year = std::stoi(m_MonthlyTakData[expID][5]);

		break;
	default:
		throw std::invalid_argument("Invalid argument");
	}

	return expData;
}

void FileManager::WriteExpense(const int expType, const ExpenseData& data)
{
	//USER CALLED

	switch (expType)
	{
	case ONETIME:
		AddDataToMap(data, m_OneTimeExpData);
		Write(m_FilePath1, m_OneTimeExpData);
		break;
	case MONTHLY:
		AddDataToMap(data, m_MonthlyExpData);
		Write(m_FilePath2, m_MonthlyExpData);
		break;
	case ONETIME_T:
		AddDataToMap(data, m_OneTimeTakData);
		Write(m_FilePath3, m_OneTimeTakData);
		break;
	case MONTHLY_T:
		AddDataToMap(data, m_MonthlyTakData);
		Write(m_FilePath4, m_MonthlyTakData);
		break;
	}
}

void FileManager::DeleteExpense(const int expID, const int expType)
{
	//USER CALLED
	switch (expType)
	{
	case ONETIME:
		RemoveFromMap(expID, m_OneTimeExpData);
		Write(m_FilePath1, m_OneTimeExpData);
		break;
	case MONTHLY:
		RemoveFromMap(expID, m_MonthlyExpData);
		Write(m_FilePath2, m_MonthlyExpData);
		break;
	case ONETIME_T:
		RemoveFromMap(expID, m_OneTimeTakData);
		Write(m_FilePath3, m_OneTimeTakData);
		break;
	case MONTHLY_T:
		RemoveFromMap(expID, m_MonthlyTakData);
		Write(m_FilePath4, m_MonthlyTakData);
		break;
	}
}

const GeneralData& FileManager::ReadGeneral()
{
	std::ifstream stream(m_FilePathG);

	std::string line;
	int i = 0;
	while (getline(stream, line))
	{
		switch (i)
		{
		case 0:
			m_GeneralData.CurrOneTimeExpCount = std::stoi(line);
			break;
		case 1:
			m_GeneralData.CurrMonthlyExpCount = std::stoi(line);
			break;
		case 2:
			m_GeneralData.CurrOneTimeTakCount = std::stoi(line);
			break;
		case 3:
			m_GeneralData.CurrMonthlyTakCount = std::stoi(line);
			break;
		case 4:
			m_GeneralData.userID = std::stoi(line);
			break;
		case 5:
			m_GeneralData.groupID = std::stoi(line);
			break;
		case 6:
			m_GeneralData.balance = std::stod(line);
			break;
		default:
			break;
		}
		++i;

	}

	return m_GeneralData;
}

void FileManager::WriteGeneral(const GeneralData& data)
{
	std::ofstream stream(m_FilePathG);

	stream << data.CurrOneTimeExpCount << '\n';
	stream << data.CurrMonthlyExpCount << '\n';
	stream << data.CurrOneTimeTakCount << '\n';
	stream << data.CurrMonthlyTakCount << '\n';
	stream << data.userID << '\n';
	stream << data.groupID << '\n';
	stream << data.balance << '\n';
	stream.close();

	m_GeneralData = data;
}

void FileManager::Read(const std::string& filePath, std::unordered_map<int, std::vector<std::string>>& data)
{
	//INTERNAL
	std::ifstream reader(filePath);

	std::string line;
	int index = -1;
	while (getline(reader, line))
	{
		if (line.find("#") != std::string::npos)
		{
			index = std::stoi(line.replace(0, 1, ""));
			data.insert({ index, {} });
		}
		else
		{
			data[index].emplace_back(line);
		}
	}
	reader.close();
}

void FileManager::Write(const std::string& filePath, std::unordered_map<int, std::vector<std::string>>& data)
{
	//INTERNAL
	std::ofstream writer(filePath);

	for (int i = 1; i < data.size() + 1; ++i)
	{
		writer << '#' << i << '\n';
		for (int j = 0; j < data[i].size(); ++j)
		{
			if (data[i][j] == "")
			{
				writer << "NULL" << '\n';
				continue;
			}

			writer << data[i][j] << '\n';
		}
	}
	writer.close();
}


void FileManager::AddDataToMap(const ExpenseData& data, std::unordered_map<int, std::vector<std::string>>& map)
{
	//INTERNAL
	int nextIndex = map.size() + 1;
	map.insert({ nextIndex, { data.Name, std::to_string(data.Price), data.Info, std::to_string(data.Day), std::to_string(data.Month), std::to_string(data.Year)} });
}

void FileManager::RemoveFromMap(const int expID, std::unordered_map<int, std::vector<std::string>>& map)
{
	//INTERNAL

	map.erase(expID);

	for (int i = expID + 1; i < map.size() + 2; ++i)
	{
		auto nodeHandler = map.extract(i);
		nodeHandler.key() = i - 1;
		map.insert(std::move(nodeHandler));
	}

}



