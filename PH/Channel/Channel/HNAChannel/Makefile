OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/HNAChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libHNAChannel.so
SOOBJS = HNAChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
