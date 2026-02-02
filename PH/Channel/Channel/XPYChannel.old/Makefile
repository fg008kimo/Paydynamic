OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/XPYChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libXPYChannel.so
SOOBJS = XPYChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all	: $(COMPSO)
