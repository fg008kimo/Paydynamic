OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/HpyMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libHpyMsg.so
SOOBJS = HpyMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
