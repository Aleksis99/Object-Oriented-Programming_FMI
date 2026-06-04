#pragma once
#include "UserFactory.h"

class UserServer
{
private:

	static const size_t MAX_USERS = 10000;
	User* users[MAX_USERS];
	size_t size = 0;

	void free();
	void init();
	void copy(const UserServer& other);

public:

	UserServer();
	UserServer(const UserServer& other);
	UserServer& operator=(const UserServer& other);
	~UserServer();

	const size_t& getUsersCount() const;
	void addUser(const std::string& name, const std::string& password, UserType type);
	bool deleteUserByID(const size_t id);
	size_t getTotatalMonthlyRevenue() const;
};

