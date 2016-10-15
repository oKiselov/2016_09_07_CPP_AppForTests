#pragma once

#include "ITestSourceData.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

// Class for working with data-source - file with cpp tests 
class TestDataCppFromFile : public ITestSourceData
{
public:
	TestDataCppFromFile(){};
	virtual ~TestDataCppFromFile(){};

	// Method which receives the path 
	// To read and get Data
	// Method returns string from file / dataBase / website / etc 
	std::string GetData(int TestID) override; 

};

