
#ifndef __BRAINFUCK_CODE_H__
#define __BRAINFUCK_CODE_H__ __BRAINFUCK_CODE_H__

#include <iostream>
#include <fstream>

class BrainfuckCode
{
public:
	BrainfuckCode();
	BrainfuckCode(const std::ifstream &source);
	BrainfuckCode(const std::string &source);
	virtual ~BrainfuckCode();

	void reset();
	char current() const;
	char next(bool moveFilePointer);
	char prev(bool moveFIlePointer);

	std::string getCode() const;
	int getLines() const;

private:
	std::string bfCode;
	int pos;
	int lines;
};

#endif
