
#include "BrainfuckCode.h"

BrainfuckCode::BrainfuckCode(const std::ifstream &source)
{
	
}

BrainfuckCode::BrainfuckCode(const std::string &source)
{
	this->bfCode = source;
	this->lines = 0;
	this->pos = 0;
}

BrainfuckCode::~BrainfuckCode()
{

}

BrainfuckCode::BrainfuckCode()
{

}

void BrainfuckCode::reset()
{
	this->pos = 0;
}

char	BrainfuckCode::current() const
{
	return this->bfCode.at(pos);
}

char BrainfuckCode::next(bool moveFilePointer)
{
	if (pos >= this->bfCode.size() - 1)
	{
		return '\0';
	}
	else 
	{
		return this->bfCode.at(++pos);
	}
}

char BrainfuckCode::prev(bool moveFIlePointer)
{
	if (pos <= 0)
	{
		return '\0';
	}
	else 
	{
		return this->bfCode.at(--pos);
	}
}

std::string BrainfuckCode::getCode() const
{
	return this->bfCode;
}

int BrainfuckCode::getLines() const
{
	return 0;
}
