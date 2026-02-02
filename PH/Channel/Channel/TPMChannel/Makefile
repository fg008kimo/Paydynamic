OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/TPMChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTPMChannel.so
SOOBJS = TPMChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
