OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/ZPEChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libZPEChannel.so
SOOBJS = ZPEChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
