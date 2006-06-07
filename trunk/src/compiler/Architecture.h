
#ifndef __ARCHITECTURE_H__
#define __ARCHITECTURE_H__ __ARCHITECTURE_H__

#include <string>

class Architecture
{
public:
	enum BfCharacter
	{
		INIT,
		INC = '+',
		DEC = '-',
		INPUT = ',',
		OUTPUT = '.',
		NEXT_CELL = '>',
		PREV_CELL = '<',
		START_LOOP = '[',
		END_LOOP = ']',
		END
	};

	Architecture();
	virtual ~Architecture() = 0;

	virtual std::string getAsmStatement(BfCharacter code) const = 0;
	virtual std::string getAsmSystemCall() const = 0;

	void setIFilename(std::string fn);
	void setOFilename(std::string fn);

protected:
	std::string iFilename;
	std::string oFilename;
};

#endif
