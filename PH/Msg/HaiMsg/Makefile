OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/HaiMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libHaiMsg.so
SOOBJS = HaiMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
