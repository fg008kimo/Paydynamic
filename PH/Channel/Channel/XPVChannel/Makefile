OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/XPVChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libXPVChannel.so
SOOBJS = XPVChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
