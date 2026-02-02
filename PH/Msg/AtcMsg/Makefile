OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/AtcMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libAtcMsg.so
SOOBJS = AtcMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
