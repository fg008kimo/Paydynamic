OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/UNWChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libUNWChannel.so
SOOBJS = UNWChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
