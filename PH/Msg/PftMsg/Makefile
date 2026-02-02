OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/PftMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libPftMsg.so
SOOBJS = PftMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
