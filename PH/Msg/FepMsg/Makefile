OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/FepMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libFepMsg.so
SOOBJS = FepMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
