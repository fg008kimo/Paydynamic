OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/DPQChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDPQChannel.so
SOOBJS = DPQChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
