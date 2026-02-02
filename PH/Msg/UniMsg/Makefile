OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/UniMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libUniMsg.so
SOOBJS = UniMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
