#pragma once
#include "User.h"
class ProUser : public User
{
public:
	ProUser(const std::string& name, const std::string& password, unsigned subPrice);
	bool isPaidSubcriber() const override;
	User* clone() const override;
};

