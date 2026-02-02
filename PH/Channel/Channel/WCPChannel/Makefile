OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/WCPChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libWCPChannel.so
SOOBJS = WCPChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
