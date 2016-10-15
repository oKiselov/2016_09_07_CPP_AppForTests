#include "TestDataCppFromFile.h"
#include "TestSI.h"
#include "TestUI.h"
#include "ITestUI.h"
#include "User.h"
#include "TestSession.h"
#include "SettingsMaxOptions.h"

inline std::string& StrCheck(std::string &strTemp)
{
	while (strTemp == "\0")
	{
		std::getline(std::cin, strTemp);
	}
	return strTemp; 
}

int main()
{
	TestUI TUI; 
	ITestUI &currUserInterface=TUI;

	currUserInterface.ShowForRegister(); 
	// Inputing of information about Name
	std::string strName;
	std::getline(std::cin, strName);
	strName = StrCheck(strName);

	// Inputing of information about SecondName
	std::string strSecondName;
	std::getline(std::cin, strSecondName);
	strSecondName = StrCheck(strSecondName);

	// Inputing of information about Group
	std::string strGroup;
	std::getline(std::cin, strGroup);
	strGroup = StrCheck(strGroup);

	// Creating of User object 
	User currUser(strName, strSecondName, strGroup);

	// Initialization of reference type variable of base abstract class with object of class-inheritor 
	TestDataCppFromFile curTestCPP;
	ITestSourceData &curTest = curTestCPP;

	// Reading datasource and transforming it into string 
	std::string strData=curTest.GetData(0); 

	// Constructor of class service interface: string of questions and number of variants 
	TestSI currServiceInterface(strData, maxQuantQuest);

	// Constructor of MAIN class - Business Logic. 
	TestSession currTestSession(currServiceInterface, currUser); 

	// Welcome to testSession
	currUserInterface.ShowWelcome(currTestSession.GetUser().GetUsersName()
		, currTestSession.GetUser().GetUsersSecondName(), currTestSession.GetUser().GetUsersGroup());

	// Time Setting 
	currTestSession.GetTestSI().SetTime(); 

	// Loop with number of test questions 
	for (int i = 0; i < currTestSession.GetSizeOfData(); i++)
	{
		int tempRate = currTestSession.GetCurrentRating(); 
		currUserInterface.ShowTest(i, tempRate, currTestSession.GetTestSI().GetCurrentQuestion(i));

		std::string strUsersAnswer; 
		std::getline(std::cin, strUsersAnswer); 
		int iTempAnswer=currTestSession.GetTestSI().GetUsersAnswer(strUsersAnswer); 

		if (currTestSession.GetTestSI().IsAnswerPermittedToGetMark(iTempAnswer))
		{
			currTestSession.PermittedAnswerCkecking(i, iTempAnswer); 
		}
		else
		{
			// Incorrect symbol or command
			if (iTempAnswer == 7||iTempAnswer==6)
			{
				i--;
				currUserInterface.ShowInfoOfIncorrectAnswer(); 
			}
			// Press e to end the test 
			if (iTempAnswer == 8)
			{
				currTestSession.EndTestSession(i); 
				break; 
			}
			// Press q to quit the test
			if (iTempAnswer == 9)
			{
				return 0; 
			}
		}
	}

	// Total scoring and closing of application 
	std::cout << "\n\nTotal score: " << std::endl; 
	currUserInterface.ShowForName(currTestSession.GetUser().GetUsersName()); 
	currUserInterface.ShowForSecondName(currTestSession.GetUser().GetUsersSecondName()); 
	currUserInterface.ShowForGroup(currTestSession.GetUser().GetUsersGroup()); 
	currUserInterface.ShowForResults((currTestSession.GetCurrentRating())*100/maxQuantQuest);
	currUserInterface.ShowFinish(); 
	
	return 0;
}