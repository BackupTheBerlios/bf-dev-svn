
#include "InvalidCode.h"

InvalidCode::InvalidCode() throw()
{
	this->errors = *new std::vector<std::string>;
}

InvalidCode::~InvalidCode() throw()
{

}

const char *InvalidCode::what() const throw()
{
	return NULL;
}

std::vector<std::string> InvalidCode::getList() const throw()
{
	return this->errors;
}

int InvalidCode::getNumberOfListElements() const throw()
{
	return this->errors.size();
}

void InvalidCode::addError(const std::string e) throw()
{
	this->errors.push_back(e);	
}

std::string InvalidCode::getError(int i) const throw()
{
	return this->errors.at(i);
}
