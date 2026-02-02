OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/SFEChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libSFEChannel.so
SOOBJS = SFEChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
