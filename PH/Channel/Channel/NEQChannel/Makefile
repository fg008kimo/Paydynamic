OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/NEQChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libNEQChannel.so
SOOBJS = NEQChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
