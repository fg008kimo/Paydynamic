OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/IpyMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libIpyMsg.so
SOOBJS = IpyMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
