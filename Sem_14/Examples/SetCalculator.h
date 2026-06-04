#pragma once
#include "SetValue.h"
#include "BinaryOperator.h"
#include "UnaryOperator.h"
#include <string>
class SetCalculator
{
	SetExpression* expression;

	void free();
	void copy(const SetCalculator& other);
	SetExpression* parse(const std::string& str) const;
	bool isOperator(char ch) const;

public:
	SetCalculator(const std::string& str);
	SetCalculator(const SetCalculator& other);
	SetCalculator& operator=(const SetCalculator& other);
	~SetCalculator();
	
	bool elementIn(const SetElement& el) const;
};

