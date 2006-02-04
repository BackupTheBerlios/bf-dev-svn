SOURCES += bfstudio.cpp \
           main.cpp
HEADERS += bfstudio.h
TEMPLATE = app
CONFIG += release \
          warn_on \
	  thread \
          qt
TARGET = ../bin/bfstudio
