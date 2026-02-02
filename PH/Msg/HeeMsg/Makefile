OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/HeeMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libHeeMsg.so
SOOBJS = HeeMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
