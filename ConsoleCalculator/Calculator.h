#pragma once
#include <iostream>
#include <stdint.h>

//TODO! XML-tegs
/// <summary>
///  Demonstrates the operation of the calculator, you can use several operators ( +, -, *, /, % ) 
/// </summary>
void DemoConsoleCalculator();

enum class Operator {
	ADDITION = '+',
	SUBTRACTION = '-',
	MULTIPLICATION = '*',
	DIVISION = '/',
	REMAINDER = '%'
//TODO: NEW OPERATORS (1/4)
};

/// <summary>
///  Template argument must be int, float, double, or int32_t
/// </summary>
template <typename TArgumentType>
class MayConsoleCalculator {
	// at the compilation stage, we will check the type
	static_assert(std::is_same<TArgumentType, int>::value ||
					std::is_same<TArgumentType, float>::value ||
					std::is_same<TArgumentType, double>::value || 
					std::is_same<TArgumentType, int32_t>::value,
	// new types can be added here, but it's worth checking that they support operations: +, -, *, /, % 
					"Template argument must be int, float, or double");
private:
	TArgumentType argument1;
	TArgumentType argument2;
	Operator operation;

	/// <summary>
	///  A function for getting an operator from a symbol ( +, -, *, /, % ) 
	/// </summary>
	Operator ÑonvertToEnumOperator(char op);
	char getCharOperator();

public:
	MayConsoleCalculator();
	//MayConsoleCalculator(MayConsoleCalculator& ConsoleCalculato);
	~MayConsoleCalculator();

//TODO: void CinArgument(int argument1, int argument2);
	void CinArgument();
	void CinOperation();
	TArgumentType Calcul();
	void FormulaAndResult();
	
};


