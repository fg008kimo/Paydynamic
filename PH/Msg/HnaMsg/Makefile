OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/HnaMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libHnaMsg.so
SOOBJS = HnaMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
