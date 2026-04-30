#pragma once
class ObjectCounter
{
private:
	size_t id;
	static size_t count;
	static size_t currCount;

public:
	ObjectCounter();
	~ObjectCounter();
	size_t getId() const;
	static size_t getCount();
	static size_t getCurrCount();
};
