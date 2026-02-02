OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/BFVChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libBFVChannel.so
SOOBJS = BFVChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
