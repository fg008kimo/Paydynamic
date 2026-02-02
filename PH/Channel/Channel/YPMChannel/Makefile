OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/YPMChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libYPMChannel.so
SOOBJS = YPMChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
