#include "SetCalculator.h"

void SetCalculator::free()
{
	delete expression;
}

void SetCalculator::copy(const SetCalculator& other)
{
	expression = other.expression->clone();
}

SetExpression* SetCalculator::parse(const std::string& str) const
{
	if (str.size() == 1)
		return new SetValue(str[0]);

	size_t count = 0;

	std::string exprNoBrakets = str.substr(1, str.size() - 2);

	for (size_t i = 0; i < exprNoBrakets.size(); i++)
	{
		if (exprNoBrakets[i] == '(')
			count++;

		if (exprNoBrakets[i] == ')')
			count--;

		if (isOperator(exprNoBrakets[i]) && count == 0)
		{
			if (exprNoBrakets[i] == NEG)
				return new UnaryOperator(NEG, parse(exprNoBrakets.substr(i + 1)));
			else
				return new BinaryOperator(
					exprNoBrakets[i],
					parse(exprNoBrakets.substr(0, i)),
					parse(exprNoBrakets.substr(i+1))
				);
		}
	}


	return nullptr;
}

bool SetCalculator::isOperator(char ch) const
{
	return ch == AND
		|| ch == OR
		|| ch == IMPL
		|| ch == BIMPL
		|| ch == NEG
		|| ch == XOR
		|| ch == DIFF;
}

bool SetCalculator::elementIn(const SetElement& el) const
{
	return expression->elementIn(el);
}

SetCalculator::SetCalculator(const std::string& str)
{
	expression = parse(str);
}

SetCalculator::SetCalculator(const SetCalculator& other)
{
	copy(other);
}

SetCalculator& SetCalculator::operator=(const SetCalculator& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

SetCalculator::~SetCalculator()
{
	free();
}
