#include "SetElement.h"

bool SetElement::get(char el) const
{
    if (el < 'A' || el > 'Z')
        throw "Invalid set element";

    return vars[(int)(el - 'A')];
}

void SetElement::set(char el, bool value)
{
    if (el < 'A' || el > 'Z')
        throw "Invalid set element";

    vars[(int)(el - 'A')] = value;
}
