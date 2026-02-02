OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/LkpMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libLkpMsg.so
SOOBJS = LkpMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
