OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/DPYChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDPYChannel.so
SOOBJS = DPYChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
