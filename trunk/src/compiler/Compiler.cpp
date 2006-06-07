
#include "Compiler.h"

Compiler::Compiler(const BrainfuckCode &code, std::string dest, Architecture &arch)
{
	this->bfCode = code;
	this->dest = dest;

	this->arch = &arch;

	this->tempFileName = *new std::string("temp.c");
	//this->temp = *new std::ofstream(this->tempFileName.c_str());
	//this->temp = *new std::ofstream("./temp.c");
	//std::ofstream os(this->tempFileName.c_str());
	//this->temp = *new std::ofstream(this->tempFileName.c_str());
}

Compiler::~Compiler()
{

}

void Compiler::compile() throw(InvalidCode)
{
	parser = *new Parser(this->bfCode);

	std::ofstream temp(this->tempFileName.c_str());          

	try
	{
		parser.parse();
	}
	catch (const InvalidCode &e)
	{
		throw e;
		return;
	}

	char c;

	this->bfCode.reset();

	temp << this->arch->getAsmStatement(Architecture::INIT);
	
	for (int i = 0; i < this->bfCode.getCode().size(); ++i)
	{
		if (i <= 0)
			c = this->bfCode.current();
		else
			c = this->bfCode.next(true);

		switch (c)
		{
		case '[':
			temp << this->arch->getAsmStatement(Architecture::START_LOOP);
			break;
		case ']':
			temp << this->arch->getAsmStatement(Architecture::END_LOOP);
			break;
		case '>':
			temp << this->arch->getAsmStatement(Architecture::NEXT_CELL);
			break;
		case '<':
			temp << this->arch->getAsmStatement(Architecture::PREV_CELL);
			break;
		case '+':
			temp << this->arch->getAsmStatement(Architecture::INC);
			break;
		case '-':
			temp << this->arch->getAsmStatement(Architecture::DEC);
			break;
		case '.':
			temp << this->arch->getAsmStatement(Architecture::OUTPUT);
			break;
		case ',':
			temp << this->arch->getAsmStatement(Architecture::INPUT);
			break;
		}
	}

	temp << this->arch->getAsmStatement(Architecture::END);

	temp.flush();
	
	this->arch->setIFilename(this->tempFileName);
	this->arch->setOFilename(this->dest);

	system(this->arch->getAsmSystemCall().c_str());
}

void Compiler::link()
{

}

void Compiler::setDestination(const std::string dest) throw(NoPermition)
{
	this->dest = dest;
}
