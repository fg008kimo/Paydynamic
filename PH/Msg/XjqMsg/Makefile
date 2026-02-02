OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/XjqMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libXjqMsg.so
SOOBJS = XjqMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz  -ljson-c

all	: $(COMPSO)
