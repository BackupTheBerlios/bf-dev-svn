
#ifndef __WINDOWS_GCC_ARCHITECTURE_H__
#define __WINDOWS_GCC_ARCHITECTURE_H__ __WINDOWS_GCC_ARCHITECTURE_H__

#include <string>
#include <cstdio>

#include "Architecture.h"

class WindowsGCCArchitecture  : public	Architecture
{
public:
	WindowsGCCArchitecture();
	virtual ~WindowsGCCArchitecture();

	std::string getAsmStatement(BfCharacter code) const;
	std::string getAsmSystemCall() const;
};

#endif
