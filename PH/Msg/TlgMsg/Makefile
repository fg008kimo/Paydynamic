OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/TlgMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTlgMsg.so
SOOBJS = TlgMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
