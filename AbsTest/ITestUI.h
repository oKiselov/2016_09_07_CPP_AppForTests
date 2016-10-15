#pragma once

#include "Settings.h"

#include <iostream>

// Abstract class of user interface 
class ITestUI
{
public:
	ITestUI(){};
	virtual ~ITestUI(){};

	virtual void ShowForRegister()const throw()=0;
	virtual void ShowForName(std::string&)const throw()=0;
	virtual void ShowForSecondName(std::string&)const throw()=0;
	virtual void ShowForGroup(std::string&)const throw()=0;
	virtual void ShowForResults(const int&)const throw()=0;
	virtual void ShowWelcome(std::string&, std::string&, std::string&)=0;

	virtual void ShowTest (int&iNum_in_loop, int&iRating, std::string&strQuestion)const throw() = 0;
	virtual void ShowInfoOfIncorrectAnswer()const throw() = 0; 
	virtual void ShowFinish()const throw()=0;
};
