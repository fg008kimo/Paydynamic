OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/CpeMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libCpeMsg.so
SOOBJS = CpeMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz -ljson-c

all	: $(COMPSO)
