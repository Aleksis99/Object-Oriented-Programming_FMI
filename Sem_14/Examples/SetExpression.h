#pragma once
#include "SetElement.h"

const char OR  ='v';	//- union
const char AND	='^';		//- intersection
const char DIFF ='/';	//- set difference
const char NEG	='!';		//- complement
const char XOR	='x';		//- relative complement
const char IMPL ='>';	//- implication
const char BIMPL ='=';	//- biimplication

class SetExpression
{
public:

	virtual bool elementIn(const SetElement& el) const = 0;
	virtual SetExpression* clone() const = 0;
	virtual ~SetExpression() = default;
};

