#include "TestSI.h"

TestSI::TestSI()
{
}


TestSI::~TestSI()
{
}


TestSI::TestSI(TestSI&TSI)
{
	for (auto it = TSI.ArrayOfQuestions.cbegin(); it != TSI.ArrayOfQuestions.cend(); ++it)
	{
		this->ArrayOfQuestions.push_back(*it); 
	}
}


TestSI::TestSI(std::string&strAllQuest, int &iQuantity_quest_variant)
{
	try
	{
		std::vector<TestDataCPP>ArrayOfQuestions;

		strAllQuest.erase(0, strAllQuest.find("<num>") + sizeof("<num>") - 1);
		int iPos_Num = strAllQuest.find("<question>");

		if (iPos_Num == strAllQuest.npos)
		{
			throw "Error occured with file or marking";
		}

		while (iPos_Num != strAllQuest.npos)
		{
			// Find questions number in order 
			std::string strNumQuest = strAllQuest.substr(0, iPos_Num);
			int iNumQuestion = std::stoi(strNumQuest);
			strAllQuest.erase(0, iPos_Num + sizeof("<question>") - 1);

			// Find the body of test question 
			int iPos_Answer = strAllQuest.find("<answer>");
			std::string strQuestion = strAllQuest.substr(0, iPos_Answer);
			strAllQuest.erase(0, iPos_Answer + sizeof("<answer>") - 1);

			// Find next questions number in order 
			iPos_Num = strAllQuest.find("<num>");
			int iAnswer = 0;
			if (iPos_Num != strAllQuest.npos)
			{
				std::string strAnswer = strAllQuest.substr(0, iPos_Num);
				iAnswer = std::stoi(strAnswer);
				strAllQuest.erase(0, iPos_Num + sizeof("<num>") - 1);
			}

			if (iPos_Num == strAllQuest.npos)
			{
				iAnswer = std::stoi(strAllQuest);
			}

			this->ArrayOfQuestions.push_back(TestDataCPP{ iNumQuestion, strQuestion, iAnswer });
		}

		// Variable - for aborting ability of repeatedly receiving random int   
		bool equal = false;
		// temporary vector of qstns numbers  
		std::vector<int> Variant;
		srand(time(NULL));
		for (size_t i = 0; i < iQuantity_quest_variant; i++)
		{
			equal = false;
			int temp_num = rand() % this->ArrayOfQuestions.size();
			for (size_t j = 0; j < Variant.size(); j++)
			{
				if (temp_num == Variant[j])
				{
					i--;
					j = Variant.size();
					equal = true;
				}
			}
			if (equal != true)
			{
				Variant.push_back(temp_num);
			}
		}

		std::vector <TestDataCPP> tempTestDataVector;

		for (int i = 0; i < Variant.size(); i++)
		{
			int temp = Variant[i];
			tempTestDataVector.push_back(this->ArrayOfQuestions[temp]);
		}

		this->ArrayOfQuestions.swap(tempTestDataVector);
	}
	catch (char *msg)
	{
		std::cout << msg << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unhandled exception" << std::endl;
	}
}

const TestSI& TestSI::operator=(const TestSI&TSI)
{
	for (int i = 0; i < TSI.ArrayOfQuestions.size(); i++)
	{
		this->ArrayOfQuestions.push_back(TSI.ArrayOfQuestions[i]);
	}
	return *this; 
}

void TestSI::SetTime()const throw()
{
	srand(time(NULL));
	return;
}

std::string TestSI::GetCurrentQuestion(int&iNum_of_Quest) const
{
	return this->ArrayOfQuestions[iNum_of_Quest].strQuestion; 
}
//
const int TestSI::GetUsersAnswer(std::string &strUser_answer)const
{
	int iUser_answer; // returned value 
	// to many letters 
	if (strUser_answer.size() > 1)
	{
		iUser_answer = 6;
		return iUser_answer;
	}
	strUser_answer[0] = char(tolower(strUser_answer[0]));

	// quit
	if (strUser_answer == "q")
	{
		iUser_answer = 9;
	}
	// end 
	else if (strUser_answer == "e")
	{
		iUser_answer = 8;
	}
	// options 
	else if (strUser_answer == "1")
	{
		iUser_answer = 1;
	}
	else if (strUser_answer == "2")
	{
		iUser_answer = 2;
	}
	else if (strUser_answer == "3")
	{
		iUser_answer = 3;
	}
	else if (strUser_answer == "4")
	{
		iUser_answer = 4;
	}
	else if (strUser_answer == "5")
	{
		iUser_answer = 5;
	}
	else
	{
		iUser_answer = 7;
	}

	return iUser_answer;
}

bool TestSI::IsAnswerPermittedToGetMark(int&iUser_answer) const
{
	bool bRet=false; 
	if (iUser_answer<6 && iUser_answer>0)
	{
		bRet = true; 
	}
	else if (iUser_answer<1 && iUser_answer>5)
	{
		bRet = false; 
	}
	return bRet; 
}

int TestSI::GetSizeOfData() const
{
	return this->ArrayOfQuestions.size();
}

int TestSI::GetCurrentNumQuest(int &iNum_of_quest) const
{
	return this->ArrayOfQuestions[iNum_of_quest].iNumQuestion; 
}

const int TestSI::GetCurrentiRight(int&iNum_of_quest) const
{
	return this->ArrayOfQuestions[iNum_of_quest].iRightAnswer; 
}

const std::vector<TestDataCPP> TestSI::GetAllQuestions() const
{
	return this->ArrayOfQuestions; 
}
