
#ifndef __LINKER_H__
#define __LINKER_H__ __LINKER_H__

#include <string>

#include "NasmNotFound.h"
#include "Architecture.h"

class Linker
{
public:
	Linker();
	Linker(std::string file, Architecture &arch);
	virtual ~Linker();

	void link() throw(NasmNotFound);

private:
	std::string file;
	Architecture *arch;
};

#endif
