OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/GPVChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libGPVChannel.so
SOOBJS = GPVChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
