#pragma once

#include "ITestUI.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <ctime>

// Class Test User Interface which is connected only with console 
class TestUI:public ITestUI
{
public:
	TestUI(){};
	virtual ~TestUI(){};

	void ShowForRegister()const throw()override; 
	void ShowForName(std::string&)const throw()override; 
	void ShowForSecondName(std::string&)const throw()override;
	void ShowForGroup(std::string&)const throw()override;
	void ShowForResults(const int&)const throw()override; 
	void ShowWelcome(std::string&, std::string&, std::string&)override; 

	void ShowTest(int&, int&, std::string&)const throw() override;
	void ShowInfoOfIncorrectAnswer()const throw() override; 
	void ShowFinish()const throw()override; 
};

