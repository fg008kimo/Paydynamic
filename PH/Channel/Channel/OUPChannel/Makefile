OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/OUPChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libOUPChannel.so
SOOBJS = OUPChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
