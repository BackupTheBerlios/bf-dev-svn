
#ifndef __COMPILER_H__
#define __COMPILER_H__ __COMPILER_H__

#include <iostream>
#include <fstream>
#include <string>

#include "Architecture.h"
#include "BrainfuckCode.h"
#include "Parser.h"
#include "Linker.h"
#include "NoPermition.h"
#include "InvalidCode.h"

class Compiler
{
public:
	Compiler(const BrainfuckCode &code, std::string dest, Architecture &arch);
	virtual ~Compiler();

	void compile() throw(InvalidCode);
	void link();

	void setDestination(const std::string dest) throw(NoPermition);
	
private:
	Parser parser;
	BrainfuckCode bfCode;
	Linker linker;
	Architecture *arch;

	std::string tempFileName;
	std::string dest;
};

#endif
