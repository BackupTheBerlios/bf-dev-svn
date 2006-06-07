
#include "Architecture.h"

Architecture::Architecture()
{

}

Architecture::~Architecture()
{

}

std::string Architecture::getAsmStatement(BfCharacter code) const
{
	return *new std::string("Undefined Architecture");
}

std::string Architecture::getAsmSystemCall() const
{
	return *new std::string("Undefined Architecture");
}

void Architecture::setIFilename(std::string fn)
{
	this->iFilename = fn;
}

void Architecture::setOFilename(std::string fn)
{
	this->oFilename = fn;
}
