OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/EEPChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libEEPChannel.so
SOOBJS = EEPChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
