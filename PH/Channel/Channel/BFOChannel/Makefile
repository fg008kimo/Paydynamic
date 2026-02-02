OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/BFOChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libBFOChannel.so
SOOBJS = BFOChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
