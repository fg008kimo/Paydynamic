OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/OPLChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libOPLChannel.so
SOOBJS = OPLChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
