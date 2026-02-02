OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/TpyMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTpyMsg.so
SOOBJS = TpyMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
