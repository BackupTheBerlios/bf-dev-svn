
#ifndef __ERROR_BASE_H__
#define __ERROR_BASE_H__ __ERROR_BASE_H__

#include <string>

class ErrorBase
{
public:
	ErrorBase() throw();
	virtual ~ErrorBase() throw() = 0;
	virtual const char *what() const throw() = 0;

private:
	std::string message;
};
		
#endif
