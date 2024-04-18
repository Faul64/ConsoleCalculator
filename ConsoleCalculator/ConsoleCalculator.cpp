#include <iostream>
#include "Calculator.h"

int main()
{
	DemoConsoleCalculator();

#if 0
	// Этот код не будет включен в исполняемый файл
	чтобы остановить программу и посмотреть рузультат:
		выводим сообщение, как завершить
		ожидаем ввод
#endif

    std::cout << "\n\t Press Enter to escape";
	std::cin.ignore(10, '\n');
	std::cin.get();
	return 0;
}