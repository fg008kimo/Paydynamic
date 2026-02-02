OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/CCTChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libCCTChannel.so
SOOBJS = CCTChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
