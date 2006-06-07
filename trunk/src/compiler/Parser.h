
#ifndef __PARSER_H__
#define __PARSER_H__ __PARSER_H__

#include "BrainfuckCode.h"
#include "InvalidCode.h"

class Parser
{
public:
	Parser();
	Parser(const BrainfuckCode &code);
	virtual ~Parser();

	void parse() throw (InvalidCode);

	void addError(int characterPos);

private:
	BrainfuckCode code;

	int instructionCount;
	int loopCount;
	int characterCount;
	int loopsCBNOCount;

	InvalidCode errors;
};

#endif
