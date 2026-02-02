OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/AWCChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libAWCChannel.so
SOOBJS = AWCChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
