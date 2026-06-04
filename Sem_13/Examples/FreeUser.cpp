#include "FreeUser.h"

FreeUser::FreeUser(const std::string& name, const std::string& password)
	: User(name, password, 0)
{
}

bool FreeUser::isPaidSubcriber() const
{
	return false;
}

User* FreeUser::clone() const
{
	return new FreeUser(*this);
}
