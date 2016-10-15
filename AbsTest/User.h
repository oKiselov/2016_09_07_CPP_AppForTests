#pragma once

#include "Settings.h"

// Class describes one User 
class User
{
	std::string strName;
	std::string strSecondName;
	std::string strGroup;

public:
	User(std::string &strName, std::string &strSecondName, std::string &strGroup); 
	virtual ~User();

	// Returns current Users Name
	std::string GetUsersName()const throw(); 

	// Returns current Users Sec Name
	std::string GetUsersSecondName()const throw(); 

	// Returns current Users Group 
	std::string GetUsersGroup()const throw(); 
}; 

