#include "User.h"

size_t User::users = 0;

User::User(const std::string& name, const std::string& password, unsigned subPrice) 
	: name(name), password(password), subPrice(subPrice), id(users)
{
	users++;
}

const std::string& User::getName() const
{
	return name;
}

const std::string& User::getPassword() const
{
	return password;
}

unsigned User::getSubPrice() const
{
	return subPrice;
}

const size_t& User::getId() const
{
	return id;
}
