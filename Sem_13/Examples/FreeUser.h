#pragma once
#include "User.h"
class FreeUser : public User
{
public:

	FreeUser(const std::string& name, const std::string& password);
	bool isPaidSubcriber() const override;
	User* clone() const override;
};

