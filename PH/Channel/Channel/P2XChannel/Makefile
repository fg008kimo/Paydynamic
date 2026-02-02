OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/P2XChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libP2XChannel.so
SOOBJS = P2XChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
