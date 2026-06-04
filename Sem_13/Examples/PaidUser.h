#pragma once
#include "User.h"
class PaidUser : public User
{
public:
	PaidUser(const std::string& name, const std::string& password, unsigned subPrice);
	bool isPaidSubcriber() const override;
	User* clone() const override;
};

