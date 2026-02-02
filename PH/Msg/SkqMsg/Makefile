OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/SkqMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libSkqMsg.so
SOOBJS = SkqMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz  -ljson-c

all	: $(COMPSO)
