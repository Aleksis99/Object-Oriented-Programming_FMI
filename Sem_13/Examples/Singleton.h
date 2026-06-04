#pragma once
#include<string>
#include<iostream>

class Singleton
{
private:

	std::string data;
protected:

	Singleton();

public:

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton& getInstance();
	void setData(const std::string& data);
	const std::string& getData() const;
	~Singleton();
};

