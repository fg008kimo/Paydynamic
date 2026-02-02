OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/OflComChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libOflComChannel.so
SOOBJS = OflComChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset 

all     : $(COMPSO)
