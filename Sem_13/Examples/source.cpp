
#include <iostream>
#include "Singleton.h"
#include "UserServer.h"


int main()
{

	//Singleton& s = Singleton::getInstance();

	//s.setData("My Data");
	//s.setData("My Data 2");
	//std::cout << s.getData() << std::endl;
	//s.setData("My Data 3");
	//std::cout << s.getData() << std::endl;

	UserServer server;

	server.addUser("Ivan", "pass123", UserType::Free);
	server.addUser("Gosho", "pass123", UserType::Paid);
	server.addUser("Petar", "pass123", UserType::Pro);

	server.deleteUserByID(1);

	std::cout << server.getTotatalMonthlyRevenue();
}
