
#include "Linker.h"

Linker::Linker(std::string file, Architecture &arch)
{
	this->file = file;
	this->arch = &arch;
}

Linker::~Linker()
{

}

Linker::Linker()
{

}

void Linker::link() throw (NasmNotFound)
{

}
