#include "ObjectCounter.h"

size_t ObjectCounter::count = 0;
size_t ObjectCounter::currCount = 0;

ObjectCounter::ObjectCounter()
{
	id = count;
	count++;
	currCount++;
}

ObjectCounter::~ObjectCounter()
{
	currCount--;
}

size_t ObjectCounter::getId() const
{
	return id;
}

size_t ObjectCounter::getCount()
{
	return count;
}

size_t ObjectCounter::getCurrCount()
{
	return currCount;
}
