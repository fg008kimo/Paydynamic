OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/SmsMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libSmsMsg.so
SOOBJS = SmsMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
