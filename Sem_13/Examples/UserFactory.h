#pragma once
#include "ProUser.h"
#include "PaidUser.h"
#include "FreeUser.h"

enum class UserType
{
	Free,
	Paid,
	Pro
};

class UserFactory
{
private:

	static const unsigned paidPrice = 10;
	static const unsigned proPrice = 100;

	static size_t proUsers;
	static size_t paidUsers;

public:

	static User* createUser(const std::string& name, const std::string& password, UserType type);
	UserFactory() = delete;
};

