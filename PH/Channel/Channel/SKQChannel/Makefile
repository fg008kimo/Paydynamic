OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/SKQChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libSKQChannel.so
SOOBJS = SKQChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
