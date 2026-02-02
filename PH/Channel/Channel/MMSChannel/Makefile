OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/MMSChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libMMSChannel.so
SOOBJS = MMSChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
