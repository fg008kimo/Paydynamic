OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/MGTChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libMGTChannel.so
SOOBJS = MGTChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
