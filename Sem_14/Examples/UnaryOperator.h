#pragma once
#include "SetExpression.h"
class UnaryOperator : public SetExpression
{
private:

	SetExpression* expression;
	char operation;

	void copy(const UnaryOperator& other);
	void free();


public:

	UnaryOperator(char operation, const SetExpression* expression);
	UnaryOperator(const UnaryOperator& other);
	UnaryOperator& operator=(const UnaryOperator& other);
	~UnaryOperator();

	bool elementIn(const SetElement& el) const override;
	SetExpression* clone() const override;
};

