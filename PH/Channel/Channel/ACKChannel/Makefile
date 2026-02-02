OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/ACKChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libACKChannel.so
SOOBJS = ACKChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
