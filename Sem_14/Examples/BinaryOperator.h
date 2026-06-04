#pragma once
#include "SetExpression.h"

class BinaryOperator : public SetExpression
{
private:
	SetExpression* left;
	SetExpression* right;
	char operation;

	void copy(const BinaryOperator& other);
	void free();

public:
	BinaryOperator(char operation, const SetExpression* left, const SetExpression* right);
	BinaryOperator(const BinaryOperator& other);
	BinaryOperator& operator=(const BinaryOperator& other);
	~BinaryOperator();

	bool elementIn(const SetElement& el) const override;
	SetExpression* clone() const override;
};

