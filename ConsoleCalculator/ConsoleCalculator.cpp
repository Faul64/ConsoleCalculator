#include <iostream>
#include "Calculator.h"

int main()
{
	DemoConsoleCalculator();

#if 0
	// This code will not be included in the executable file
	to stop the programand see the result :
	we display the message how to complete
		We are waiting for input
#endif

    std::cout << "\n\t Press Enter to escape";
	std::cin.ignore(10, '\n');
	std::cin.get();
	return 0;
}