OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/EcpMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libEcpMsg.so
SOOBJS = EcpMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
