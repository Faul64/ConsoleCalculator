#include "Calculator.h"
#include <string>
#include <unordered_map>


//macros:
#define SUCCESS std::cout << " Success" << std::endl;
#define INVALIDARGUMENT std::cout << " Invalid Argument " << std::endl;
#define INVALIDOPERATOR std::cout << " Invalid Operator " << std::endl;
// to reset flags and input errors, and also Clear the input buffer
#define CLEAR_INPUT std::cin.clear(); \
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


template<typename TArgumentType>
MayConsoleCalculator<TArgumentType>::MayConsoleCalculator() : argument1(0), argument2(0), operation(Operator::ADDITION)
{}

//MayConsoleCalculator::MayConsoleCalculator(MayConsoleCalculator& ConsoleCalculato){}

template<typename TArgumentType>
MayConsoleCalculator<TArgumentType>::~MayConsoleCalculator() {}


//TODO: 
// bug 1: "-8+1"
// bug 2: "1.7"
template<typename TArgumentType>
void MayConsoleCalculator<TArgumentType>::CinArgument()
{
	while (true) {
		std::cout << "Enter First Argument  : ";
		std::cin >> this->argument1;
		if (std::cin.fail()) {
			INVALIDARGUMENT;
			CLEAR_INPUT;
		}
		else {
			SUCCESS;
			break; 
		}
	}
	
	while (true) {
		std::cout << "Enter Second Argument : ";
		std::cin >> this->argument2;

		if (std::cin.fail()) {
			INVALIDARGUMENT;
			CLEAR_INPUT;
		}
		else {
			SUCCESS;
			break;
		}
	}	
}

//TODO: add throw std::invalid_argument("Invalid operator");
template<typename TArgumentType>
Operator MayConsoleCalculator<TArgumentType>::ÑonvertToEnumOperator(char op)
{
	static const std::unordered_map<char, Operator> operatorMap = {
	{'+', Operator::ADDITION},
	{'-', Operator::SUBTRACTION},
	{'*', Operator::MULTIPLICATION},
	{'/', Operator::DIVISION},
	{'%', Operator::REMAINDER}
//TODO: NEW OPERATORS (2/4)
	};

	auto it = operatorMap.find(op);
	if (it != operatorMap.end()) {
		return it->second;
	}
	else {
		throw std::invalid_argument("Invalid operator");
	}
}

template<typename TArgumentType>
char MayConsoleCalculator<TArgumentType>::getCharOperator()
{
	switch (this->operation)
	{
	case Operator::ADDITION:
		return '+';
		break;

	case Operator::SUBTRACTION:
		return '-';
		break;

	case Operator::MULTIPLICATION:
		return '*';
		break;

	case Operator::DIVISION:
		return '/';
		break;

	case Operator::REMAINDER:
		return '%';
		break;
//TODO: NEW OPERATORS (3/4)
	default:
		return 0;
		break;
	}
}

//TODO: 
// bug 1: "-8" -> "-"
template<typename TArgumentType>
void MayConsoleCalculator<TArgumentType>::CinOperation()
{
	char userInput;
	while (true) {
		std::cout << "Enter an operator ( +, -, *, /, % ) : ";
		std::cin >> userInput;

		try {
			this->operation = ÑonvertToEnumOperator(userInput);
			SUCCESS;
			break;
		}
		catch (const std::invalid_argument& e) {
			INVALIDOPERATOR;
			CLEAR_INPUT;
		}
	}
}

template<typename TArgumentType>
TArgumentType MayConsoleCalculator<TArgumentType>::Calcul()
{
	switch (this->operation)
	{
		case Operator::ADDITION:
			return this->argument1 + this->argument2;
			break;

		case Operator::SUBTRACTION:
			return this->argument1 - this->argument2;
			break;

		case Operator::MULTIPLICATION:
			return this->argument1 * this->argument2;
			break;

		case Operator::DIVISION:
			return this->argument1 / this->argument2;
			break;

		case Operator::REMAINDER:
			return this->argument1 % this->argument2;
			break;
//TODO: NEW OPERATORS (4/4)
		default:
			throw std::out_of_range("Error");
			return 0;
			break;
	}
}

template<typename TArgumentType>
void MayConsoleCalculator<TArgumentType>::FormulaAndResult()
{
	std::cout << this->argument1 << " " << this->getCharOperator() << " " << this->argument2
				<< " = " << this->Calcul() << std::endl;
}

void DemoConsoleCalculator()
{
	MayConsoleCalculator<int32_t> DemoCalcul;
	DemoCalcul.CinArgument();
	DemoCalcul.CinOperation();
	DemoCalcul.FormulaAndResult();
}
