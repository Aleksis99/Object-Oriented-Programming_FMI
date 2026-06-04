#include <iostream>
#include <vector>
#include "SetCalculator.h"

bool isTautologyHelp(const std::string& expr,
	const SetCalculator& calc,
	const std::vector<int>& varsInExpr,
	SetElement& el,
	size_t index = 0)
{
	if (index > varsInExpr.size())
		return true;

	if (index == varsInExpr.size())
	{
		return calc.elementIn(el);
	}

	el.set(varsInExpr[index] + 'A', true);

	if (!isTautologyHelp(expr, calc, varsInExpr, el, index + 1))
		return false;

	el.set(varsInExpr[index] + 'A', false);

	return isTautologyHelp(expr, calc, varsInExpr, el, index + 1);
}

bool isTautology(const std::string& expr)
{
	bool vars[26]{ false };

	for (size_t i = 0; i < expr.size(); i++)
	{
		if (expr[i] >= 'A' && expr[i] <= 'Z')
		{
			vars[(int)expr[i] - 'A'] = true;
		}
	}

	std::vector<int> varsInExpr;

	for (size_t i = 0; i < 26; i++)
	{
		if (vars[i])
			varsInExpr.push_back(i);
	}

	SetElement el;
	SetCalculator calc(expr);

	return isTautologyHelp(expr, calc, varsInExpr, el, 0);
}

int main()
{

	SetCalculator s("(!(((A^B)vC)vX))");

	SetElement el;
	el.set('A', true); //element is in set A
	el.set('B', false); // element is NOT in set B
	el.set('C', false); // element is in set C

	//std::cout << s.elementIn(el);

	std::cout << isTautology("(AvA)");
}