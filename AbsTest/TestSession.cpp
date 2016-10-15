#include "TestSession.h"

TestSession::TestSession(TestSI&currentTest, User&currentUser) :currentTest(currentTest),
currentUser(currentUser.GetUsersName(), currentUser.GetUsersSecondName(), currentUser.GetUsersGroup()) 
{
}

int TestSession::GetSizeOfData() const
{
	return this->currentTest.GetSizeOfData(); 
}

const User &TestSession::GetUser() const
{
	return this->currentUser; 
}

const TestSI& TestSession::GetTestSI() const
{
	return this->currentTest; 
}

void TestSession::SetCurrentUsersAnswer(int&iCurrAnswer)
{
	this->currentStat.iAnswers.push_back(iCurrAnswer); 
}

int TestSession::GetCurrentUsersAnswer(int&iNum_of_quest)
{
	return this->currentStat.iAnswers[iNum_of_quest]; 
}

void TestSession::SetCurrentRightAnswer(const int&iRightAnswer)
{
	this->currentStat.iRightAnswers.push_back(iRightAnswer); 
}

int TestSession::GetCurrentRightAnswer(int&iNum_of_quest)
{
	return this->currentStat.iRightAnswers[iNum_of_quest]; 
}

void TestSession::IncreaseRating(bool bRat)
{
	if (bRat == true)
	{
		this->currentStat.iCurrRating++;
	}
	return;
}

const int TestSession::GetCurrentRating()const throw()
{
	return this->currentStat.iCurrRating; 
}

void TestSession::PermittedAnswerCkecking(int iNum_in_loop, int &iCurrAnswer)
{
	this->SetCurrentUsersAnswer(iCurrAnswer);
	this->SetCurrentRightAnswer(this->GetTestSI().GetCurrentiRight(iNum_in_loop)); 
	if (this->currentStat.iRightAnswers[iNum_in_loop] == this->currentStat.iAnswers[iNum_in_loop])
	{
		IncreaseRating(true);
	}
	else
	{
		IncreaseRating(false);
	}
	return; 
}

void TestSession::EndTestSession(int &iNum_in_loop)
{
	int iCurrAnswer = 0;
	for (int j = currentTest.GetSizeOfData(); j > iNum_in_loop; j--)
	{
		SetCurrentUsersAnswer(iCurrAnswer); 
	}
}
