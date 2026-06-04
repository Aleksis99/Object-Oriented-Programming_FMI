#include "BinaryOperator.h"

void BinaryOperator::copy(const BinaryOperator& other)
{
	operation = other.operation;
	left = other.left->clone();
	right = other.right->clone();
}

void BinaryOperator::free()
{
	delete left;
	delete right;
}

BinaryOperator::BinaryOperator(char operation, const SetExpression* left, const SetExpression* right)
	: operation(operation)
{
	this->left = left->clone();
	this->right = right->clone();
}

BinaryOperator::BinaryOperator(const BinaryOperator& other)
{
	copy(other);
}

BinaryOperator& BinaryOperator::operator=(const BinaryOperator& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

BinaryOperator::~BinaryOperator()
{
	free();
}

bool BinaryOperator::elementIn(const SetElement& el) const
{
	switch (operation)
	{
	case AND:
		return left->elementIn(el) && right->elementIn(el);
	case OR:
		return left->elementIn(el) || right->elementIn(el);
	case IMPL:
		return !left->elementIn(el) || right->elementIn(el);
	case BIMPL:
		return left->elementIn(el) == right->elementIn(el);
	case XOR:
		return left->elementIn(el) != right->elementIn(el);
	case DIFF:
		return left->elementIn(el) && !right->elementIn(el);
	default:
		break;
	}

	return false;
}

SetExpression* BinaryOperator::clone() const
{
	return new BinaryOperator(*this);
}
