OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/EPTChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libEPTChannel.so
SOOBJS = EPTChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
