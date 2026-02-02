OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/ESKChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libESKChannel.so
SOOBJS = ESKChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
