OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/XyqMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libXyqMsg.so
SOOBJS = XyqMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz  -ljson-c

all	: $(COMPSO)
