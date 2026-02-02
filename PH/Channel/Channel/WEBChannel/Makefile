OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/WEBChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libWEBChannel.so
SOOBJS = WEBChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv
#CPPFLAGS += -D_SIMULATOR_

all	: $(COMPSO)
