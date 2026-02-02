OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/HhpMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libHhpMsg.so
SOOBJS = HhpMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
