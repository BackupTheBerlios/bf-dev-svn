
#ifndef __INVALID_CODE_H__
#define __INVALID_CODE_H__ __INVALID_CODE_H__

#include <vector>
#include <string>

#include "ErrorBase.h"

class InvalidCode : public ErrorBase
{
public:
	InvalidCode() throw();
	virtual ~InvalidCode() throw();

	virtual const char *what() const throw();
	std::vector<std::string> getList() const throw();
	int getNumberOfListElements() const throw();
	void addError(std::string e) throw();
	std::string getError(int i) const throw();

private:
	std::vector<std::string> errors;
};

#endif
