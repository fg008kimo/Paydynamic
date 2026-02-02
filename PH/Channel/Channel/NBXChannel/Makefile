OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/NBXChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libNBXChannel.so
SOOBJS = NBXChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
