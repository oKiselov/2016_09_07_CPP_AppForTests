#pragma once

#include "TestSI.h"
#include "User.h"
#include "SettingStatistics.h"

// Class of Business Logic 
class TestSession
{
	TestSI currentTest; 
	User currentUser; 
	Statistics currentStat; 

public:
	TestSession(TestSI&, User&);
	virtual ~TestSession(){};
	
	// Returns amount of tests in current session 
	int GetSizeOfData()const throw(); 

	// Access to object User 
	const User& GetUser()const throw(); 

	// Access to object TestSI 
	const TestSI& GetTestSI()const throw(); 

	// Setting of answer 
	void SetCurrentUsersAnswer(int&); 

	// Returns users answer 
	int GetCurrentUsersAnswer(int&); 

	// Setting true answer 
	void SetCurrentRightAnswer(const int&);

	// Returns true abswer 
	int GetCurrentRightAnswer(int&); 

	// Operations with rating 
	void IncreaseRating(bool); 

	// returns current rating of current user 
	const int GetCurrentRating(void)const throw(); 

	// Checking of answer 
	void PermittedAnswerCkecking(int, int&);

	// Applications Behavior after users command "end" 
	void EndTestSession(int &); 
};

