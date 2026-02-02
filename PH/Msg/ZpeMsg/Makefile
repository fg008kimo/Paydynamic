OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/ZpeMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libZpeMsg.so
SOOBJS = ZpeMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz -ljson-c

all	: $(COMPSO)
