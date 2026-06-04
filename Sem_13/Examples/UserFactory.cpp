#include "UserFactory.h"

size_t UserFactory::paidUsers = 0;
size_t UserFactory::proUsers = 0;

User* UserFactory::createUser(const std::string& name, const std::string& password, UserType type)
{
	if (type == UserType::Free)
	{
		return new FreeUser(name, password);
	}

	if (type == UserType::Paid)
	{
		paidUsers++;

		if (paidUsers % 10 == 0)
		{
			return new PaidUser(name, password, paidPrice / 2);
		}

		return new PaidUser(name, password, paidPrice);
	}

	if (type == UserType::Pro)
	{
		proUsers++;

		if (proUsers % 100 == 0)
		{
			return new PaidUser(name, password, proPrice / 2);
		}

		return new PaidUser(name, password, proPrice);
	}

	throw "Invalid User type";

	return nullptr;
}
