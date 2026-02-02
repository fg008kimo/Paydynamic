OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/MMMChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libMMMChannel.so
SOOBJS = MMMChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
