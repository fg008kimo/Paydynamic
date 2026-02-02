OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Channel/SMSChannel
COMPLIBHOME = $(HOME)/lib/Channel
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libSMSChannel.so
SOOBJS = SMSChannel.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset  -liconv

all	: $(COMPSO)
