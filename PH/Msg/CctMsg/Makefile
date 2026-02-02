OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/CctMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libCctMsg.so
SOOBJS = CctMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
