OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/MMCChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libMMCChannel.so
SOOBJS = MMCChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
