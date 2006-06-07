
#include "Parser.h"

Parser::Parser(const BrainfuckCode &code)
{
	this->code = code;
	this->instructionCount = 0;
	this->loopCount = 0;
	this->loopsCBNOCount = 0;
	this->characterCount = this->code.getCode().size();
	this->code.reset();
}

Parser::~Parser()
{
	
}

Parser::Parser()
{
	
}

void Parser::parse() throw (InvalidCode)
{
	char c;

	this->code.reset();

	for (int i = 0; i < this->characterCount; ++i)
	{
		if (i <= 0)
			c = this->code.current();
		else
			c = this->code.next(true);

		switch (c)
		{
		case '[':
			++(this->instructionCount);
			++(this->loopCount);
			break;
		case ']':
			++(this->instructionCount);
			--(this->loopCount);

			if (this->loopCount + this->loopsCBNOCount < 0)
			{
				this->addError(i + 1);

				++this->loopsCBNOCount;
			}

			break;
		case '>':
		case '<':
		case '+':
		case '-':
		case '.':
		case ',':
			++(this->instructionCount);
			break;
		}
	}

	for (int i = 0; i < this->loopCount + this->loopsCBNOCount; ++i)
	{
		addError(this->characterCount + 1);
	}

	if ((this->errors.getNumberOfListElements()) != 0)
	{
		throw this->errors;
	}
}

void Parser::addError(int characterPos)
{
	char s[256];

	sprintf(s, "Invalid Code at character %d", characterPos);
	this->errors.addError(s);
}
