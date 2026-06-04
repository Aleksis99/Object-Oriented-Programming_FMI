#include "PaidUser.h"


PaidUser::PaidUser(const std::string& name, const std::string& password, unsigned subPrice)
	: User(name, password, subPrice)
{
}

bool PaidUser::isPaidSubcriber() const
{
	return true;
}

User* PaidUser::clone() const
{
	return new PaidUser(*this);
}
