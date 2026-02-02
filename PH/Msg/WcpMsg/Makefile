OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/WcpMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libWcpMsg.so
SOOBJS = WcpMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
