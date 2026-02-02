OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/MmsMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libMmsMsg.so
SOOBJS = MmsMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
