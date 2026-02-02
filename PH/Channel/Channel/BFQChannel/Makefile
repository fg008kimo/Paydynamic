OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/BFQChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libBFQChannel.so
SOOBJS = BFQChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
