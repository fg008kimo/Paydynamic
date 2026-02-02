OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/ECMChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libECMChannel.so
SOOBJS = ECMChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
