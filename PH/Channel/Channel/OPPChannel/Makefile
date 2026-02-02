OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/OPPChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libOPPChannel.so
SOOBJS = OPPChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
