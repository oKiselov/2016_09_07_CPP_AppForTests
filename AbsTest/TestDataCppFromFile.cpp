#include "TestDataCppFromFile.h"
#include "SettingsTestID.h"

std::string TestDataCppFromFile::GetData(int TestID)
{
	try
	{
		std::string strPath(strSourceOfData[TestID]); 
		std::ifstream ifs;
		ifs.open(strPath);
		if (!ifs.is_open())
		{
			throw "Error opening file for reading";
			return strPath; 
		}

		ifs.seekg(0, std::ios::end);
		size_t sizeStr = ifs.tellg();
		ifs.seekg(0, std::ios::beg);

		std::string strAllQuest(sizeStr, '\0');

		ifs.read(&strAllQuest[0], sizeStr);
		ifs.close();

		return strAllQuest; 
	}
	catch (char *msg)
	{
		std::cout << msg << std::endl; 
	}
	catch (std::exception &ex) 
	{
		std::cout << ex.what() << std::endl; 
	}
	catch (...)
	{
		std::cout << "Unhandled exception" << std::endl; 
	}
}