// Here are common settings of the TestSession application 
// User can change them without losses of functionality  

#pragma once 

#include <iostream> 
#include <vector>
#include <string>

// The type of marking source for reading into following structures:  
//<num>4
//<question>
//Члены класса, объявленные в секции public
//1. Доступны только глобальным функциям
//2. Доступны только извне
//3. Доступны всем
//4. Доступны только в методах данного класса
//5. Правильного ответа нет
//<answer>1

// Declaration of structure which will save inforamtion of each question in CPP TestSession
struct TestDataCPP 
{
	int iNumQuestion;			// number of question 
	std::string strQuestion;	// body of test question with options 
	int iRightAnswer;			// number of right answer 
	TestDataCPP(int &iNum, std::string &strQ, int &iRight) :iNumQuestion(iNum), strQuestion(strQ), iRightAnswer(iRight){}; 
};


