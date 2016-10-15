#pragma once 

#include <iostream> 
#include <vector>

// Declaration of structure which will save info of current TestSession
struct Statistics
{
	std::vector<int>iAnswers;
	std::vector<int>iRightAnswers;
	int iCurrRating;
};