OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/MmcMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libMmcMsg.so
SOOBJS = MmcMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz -lexpat

all	: $(COMPSO)
