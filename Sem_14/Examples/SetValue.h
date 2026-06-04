#pragma once
#include "SetExpression.h"
class SetValue : public SetExpression
{
private:
	char value;

public:

	SetValue(char value);
	bool elementIn(const SetElement& el) const override;
	SetExpression* clone() const override;
};

