OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/GPYChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libGPYChannel.so
SOOBJS = GPYChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
