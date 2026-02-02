OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/ALPChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libALPChannel.so
SOOBJS = ALPChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
