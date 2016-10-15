#pragma once

#include "Settings.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>


// Abstract class for working with data-source 
class ITestSourceData
{
public:
	ITestSourceData(){};
	virtual ~ITestSourceData(){};

	// Pure virtual Method which receives the path 
	// To read and get Data 
	// Method returns string from file / dataBase / website / etc 
	virtual std::string GetData(int TestID) = 0;

};

