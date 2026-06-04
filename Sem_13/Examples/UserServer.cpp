#include "UserServer.h"

void UserServer::free()
{
	for (size_t i = 0; i < MAX_USERS; i++)
	{
		if (users[i] != nullptr)
			delete users[i];
	}
}

void UserServer::init()
{
	for (size_t i = 0; i < MAX_USERS; i++)
	{
		users[i] = nullptr;
	}
}

void UserServer::copy(const UserServer& other)
{
	size = other.size;

	for (size_t i = 0; i < MAX_USERS; i++)
	{
		if (other.users[i] != nullptr)
			users[i] = other.users[i]->clone();
		else
			users[i] = nullptr;
	}
}

UserServer::UserServer()
{
	init();
}

UserServer::UserServer(const UserServer& other)
{
	copy(other);
}

UserServer& UserServer::operator=(const UserServer& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

UserServer::~UserServer()
{
	free();
}

const size_t& UserServer::getUsersCount() const
{
	return size;
}

void UserServer::addUser(const std::string& name, const std::string& password, UserType type)
{
	if (size >= MAX_USERS)
		throw "Server is full";

	size++;

	for (size_t i = 0; i < MAX_USERS; i++)
	{
		if (users[i] == nullptr)
		{
			users[i] = UserFactory::createUser(name, password, type);
			return;
		}
	}
}

bool UserServer::deleteUserByID(const size_t id)
{
	for (size_t i = 0; i < MAX_USERS; i++)
	{
		if (users[i] != nullptr && users[i]->getId() == id)
		{
			delete users[i];
			users[i] = nullptr;
			size--;

			return true;
		}
	}

	return false;
}

size_t UserServer::getTotatalMonthlyRevenue() const
{
	size_t result = 0;

	for (size_t i = 0; i < MAX_USERS; i++)
	{
		if (users[i] != nullptr)
		{
			result += users[i]->getSubPrice();
		}
	}

	return result;
}
