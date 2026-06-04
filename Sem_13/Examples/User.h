#pragma once
#include <string>
class User
{
private:

	static size_t users;
	size_t id;
	std::string name;
	std::string password;
	unsigned subPrice;

public:

	User(const std::string& name, const std::string& password, unsigned subPrice);
	const std::string& getName() const;
	const std::string& getPassword() const;
	unsigned getSubPrice() const;
	const size_t& getId() const;
	virtual bool isPaidSubcriber() const = 0;


	virtual User* clone() const = 0;
	virtual ~User() = default;
};

