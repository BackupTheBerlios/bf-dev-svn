
#ifndef __NASM_NOT_FOUND_H__
#define __NASM_NOT_FOUND_H__ __NASM_NOT_FOUND_H__

#include "ErrorBase.h"

class NasmNotFound : public ErrorBase
{
public:
	NasmNotFound() throw();
	virtual ~NasmNotFound() throw();

	virtual const char *what() const throw();
};

#endif
