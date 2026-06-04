#include "UnaryOperator.h"

void UnaryOperator::copy(const UnaryOperator& other)
{
	operation = other.operation;
	expression = other.expression->clone();
}

void UnaryOperator::free()
{
	delete expression;
}

UnaryOperator::UnaryOperator(char operation, const SetExpression* expression)
	: operation(operation)
{
	this->expression = expression->clone();
}

UnaryOperator::UnaryOperator(const UnaryOperator& other)
{
	copy(other);
}

UnaryOperator& UnaryOperator::operator=(const UnaryOperator& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

UnaryOperator::~UnaryOperator()
{
	free();
}

bool UnaryOperator::elementIn(const SetElement& el) const
{
	if (operation == NEG)
	{
		return !expression->elementIn(el);
	}


	return false;
}

SetExpression* UnaryOperator::clone() const
{
	return new UnaryOperator(*this);
}
