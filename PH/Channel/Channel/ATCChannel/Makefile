OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/ATCChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libATCChannel.so
SOOBJS = ATCChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
