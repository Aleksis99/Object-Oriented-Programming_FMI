#include "SetValue.h"

SetValue::SetValue(char value) : value(value)
{
}

bool SetValue::elementIn(const SetElement& el) const
{
	return el.get(value);
}

SetExpression* SetValue::clone() const
{
	return new SetValue(*this);
}
