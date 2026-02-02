OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/TPEChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTPEChannel.so
SOOBJS = TPEChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
