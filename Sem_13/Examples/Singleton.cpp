#include "Singleton.h"

Singleton::Singleton()
{
    std::cout << "Singleton Const" << std::endl;
}

Singleton& Singleton::getInstance()
{
    static Singleton s;
    return s;
}

void Singleton::setData(const std::string& data)
{
    this->data = data;
}

const std::string& Singleton::getData() const
{
    return data;
}

Singleton::~Singleton()
{
    std::cout << "Singleton Dest" << std::endl;
}
