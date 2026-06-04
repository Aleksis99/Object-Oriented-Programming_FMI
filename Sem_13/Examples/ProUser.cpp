#include "ProUser.h"

ProUser::ProUser(const std::string& name, const std::string& password, unsigned subPrice)
	: User(name, password, subPrice)
{

}

bool ProUser::isPaidSubcriber() const
{
	return true;
}

User* ProUser::clone() const
{
	return new ProUser(*this);
}
