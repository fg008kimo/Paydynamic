OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/YpyMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libYpyMsg.so
SOOBJS = YpyMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
