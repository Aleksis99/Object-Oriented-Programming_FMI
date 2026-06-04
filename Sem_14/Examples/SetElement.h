#pragma once

class SetElement
{
private:
	char vars[26] {false};

public:

	bool get(char el) const;
	void set(char el, bool value);
};

