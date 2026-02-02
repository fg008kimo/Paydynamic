OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/ESYChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libESYChannel.so
SOOBJS = ESYChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
