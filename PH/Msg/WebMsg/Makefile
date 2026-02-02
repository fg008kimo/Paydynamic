OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/WebMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libWebMsg.so
SOOBJS = WebMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
