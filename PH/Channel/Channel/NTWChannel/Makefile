OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/NTWChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libNTWChannel.so
SOOBJS = NTWChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
