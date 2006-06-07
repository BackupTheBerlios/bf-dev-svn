
#include "ErrorBase.h"

ErrorBase::ErrorBase() throw()
{

}

ErrorBase::~ErrorBase() throw()
{

}

const char *ErrorBase::what() const throw()
{
	return NULL;
}
