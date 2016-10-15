#include "User.h"


User::User(std::string& strName, std::string& strSecondName, std::string& strGroup)
{
	this->strName = strName;
	this->strSecondName = strSecondName;
	this->strGroup = strGroup;
}

User::~User(){}

std::string User::GetUsersName() const
{
	return this->strName; 
}

std::string User::GetUsersSecondName() const
{
	return this->strSecondName; 
}

std::string User::GetUsersGroup() const
{
	return this->strGroup; 
}
