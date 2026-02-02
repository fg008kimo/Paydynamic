OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/XjpMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libXjpMsg.so
SOOBJS = XjpMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
