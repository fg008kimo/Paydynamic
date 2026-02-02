OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/ZPQChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libZPQChannel.so
SOOBJS = ZPQChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
