#pragma once

#include "ITestSourceData.h"
#include "TestDataCppFromFile.h"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

// Class Test Service Interface
class TestSI
{
	// Array of structrures with questions
	std::vector<TestDataCPP> ArrayOfQuestions; 
public:
	TestSI();
	TestSI(TestSI&); 
	TestSI(std::string&, int &); 
	const TestSI&operator=(const TestSI&); 

	virtual ~TestSI();

	// Setting time
	void SetTime()const throw();

	// Method receives number of question and returns its body 
	std::string GetCurrentQuestion(int &)const throw();

	// Method receives string inputed by user 
	// Returns index of users command 
	const int GetUsersAnswer(std::string &)const;		

	// Method receives index of users command 
	// Returns true or false - can we put mark or cant do this 
	bool IsAnswerPermittedToGetMark(int &)const throw(); 

	// Returns amount if questions in array 
	int GetSizeOfData() const;

	// Returns ID of current question
	int GetCurrentNumQuest(int &)const; 

	// Returns true answer on current question 
	const int GetCurrentiRight(int &)const; 

	// Returns all questions in variant 
	const std::vector<TestDataCPP> GetAllQuestions()const; 

};

