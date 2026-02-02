OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/GPEChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libGPEChannel.so
SOOBJS = GPEChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
