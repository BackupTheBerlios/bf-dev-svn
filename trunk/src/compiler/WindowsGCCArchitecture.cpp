
#include "WindowsGCCArchitecture.h"

WindowsGCCArchitecture::WindowsGCCArchitecture()
{

}

WindowsGCCArchitecture::~WindowsGCCArchitecture()
{

}

std::string WindowsGCCArchitecture::getAsmStatement(BfCharacter code) const
{
	switch (code)
	{
	case Architecture::NEXT_CELL:
		return "++pos;\nif (pos >= 30000) pos = 0;\n";
	case Architecture::PREV_CELL:
		return "--pos;\nif (pos <= -1) pos = 29999;\n";
	case Architecture::INC:
		return "++ptr[pos];\n";
	case Architecture::DEC:
		return "--ptr[pos];\n";
	case Architecture::START_LOOP:
		return "while (ptr[pos]) {\n";
	case Architecture::END_LOOP:
		return "}\n";
	case Architecture::OUTPUT:
		return "putchar(ptr[pos]);\nfflush(stdout);\n";
	case Architecture::INPUT:
		return "fflush(stdin); ptr[pos] = getchar();\n";
	case Architecture::INIT:
		return "#include <stdio.h>\n#include <stdlib.h>\nint main(int argc, char **argv) {\n\
				 signed char *ptr;\nsigned int pos;\nptr = (signed char *)malloc(30000 * sizeof(signed char));\n\
				 pos = 0;\n{\nint i;\nfor (i = 0; i < 30000; ++i) ptr[i] = 0;\n}\n";
	case Architecture::END:
		return "return 0;\n}\n";
	}
}

std::string WindowsGCCArchitecture::getAsmSystemCall() const
{
	char call[256];

	sprintf(call, "gcc -o %s %s", this->oFilename.c_str(), this->iFilename.c_str());
											  
	return *new std::string(call);
}
