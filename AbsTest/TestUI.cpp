#include "TestUI.h"

void TestUI::ShowForRegister() const
{
	std::cout << "Please, enter your name, second name and group: " << std::endl; 
}

void TestUI::ShowForName(std::string&strName) const
{
	std::cout << "Name: " << strName<< std::endl;
}

void TestUI::ShowForSecondName(std::string&strSecondName) const
{
	std::cout << "Second Name: " <<strSecondName<< std::endl;
}

void TestUI::ShowForGroup(std::string&strGroup) const
{
	std::cout << "Group: " << strGroup << std::endl;
}

void TestUI::ShowForResults(const int&iRating) const
{
	std::cout << "Rating: " << iRating << "%"<<std::endl; 
}


void TestUI::ShowWelcome(std::string&Name, std::string&SecondName, std::string&Group)
{
	std::cout << "\n\nHello, " << Name << "\n" << SecondName
		<< "\n" << Group << "\n\nPress Enter to start the test: " << std::endl;
	std::string strTemp;
	std::getline(std::cin, strTemp);
	while (strTemp != "\0")
	{
		std::getline(std::cin, strTemp);
	}
}

void TestUI::ShowTest(int&iNum_in_loop, int&iRating, std::string&strQuestion)const throw()
{
	system("CLS");
	setlocale(LC_ALL, "Russian");
	std::cout << "Number of question: " << iNum_in_loop + 1 << std::endl;
	std::cout << "You have got: " << iRating << " correct answer(-s)" << std::endl;
	int iSpentTime = clock() / 60000; 
	std::cout << std::endl;
	std::cout << "You have spent: " << clock() / 60000 << " min." << std::endl;
	std::cout << " 	 ENTER - Aprove    Q - Quit     E - End  " << std::endl;
	std::cout << std::endl;
	std::cout << strQuestion << std::endl;
	std::cout << "Enter your answer or special command: " << std::endl;
	return;
}

void TestUI::ShowInfoOfIncorrectAnswer() const throw()
{
	std::cout << "You have put incorrect answer. Try again" << std::endl;
	std::cout << "\n\nPress Enter to continue " << std::endl;
	std::string strTemp; 
	std::getline(std::cin, strTemp);
	while (strTemp != "\0")
	{
		std::getline(std::cin, strTemp);
	}
}

void TestUI::ShowFinish() const
{
	std::cout << "\n\nPress Enter to end the test: " << std::endl;
	std::string strTemp;
	std::getline(std::cin, strTemp);
	while (strTemp != "\0")
	{
		std::getline(std::cin, strTemp);
	}
}
