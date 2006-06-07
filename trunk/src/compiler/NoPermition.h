
#ifndef __NO_PERMITION_H__
#define __NO_PERMITION_H__ __NO_PERMITION_H__

#include "ErrorBase.h"

class NoPermition : public ErrorBase
{
public:
	NoPermition() throw();
	virtual ~NoPermition() throw();

	virtual const char *what() const throw();
};

#endif
