OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/ATMChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libATMChannel.so
SOOBJS = ATMChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
