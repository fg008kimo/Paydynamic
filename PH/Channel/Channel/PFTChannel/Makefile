OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/PFTChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libPFTChannel.so
SOOBJS = PFTChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
