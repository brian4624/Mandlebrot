CXX = g++
AR = ar
GCOV = gcov
CFLAGS += -MMD
LDFLAGS =

ifeq ($(OS), Windows_NT)
    EXT = .exe
    RM = del
    CFLAGS += -std=c++11
	CFLAGS += -I/usr/local/include
	LDFLAGS += -lfreeglut -lglu32 -lopengl32 -Wl,--subsystem,windows
    CXX = g++
    PREFIX = 
else
    EXT =
    PREFIX = ./
    RM = rm -f
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S), Linux)
        CFLAGS += 
    endif
    ifeq ($(UNAME_S), Darwin)
        CFLAGS += -Wno-deprecated-declarations
		LDFLAGS += -framework OpenGL -framework GLUT
    endif
endif

