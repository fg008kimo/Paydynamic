OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/XpqMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libXpqMsg.so
SOOBJS = XpqMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz  -ljson-c

all	: $(COMPSO)
