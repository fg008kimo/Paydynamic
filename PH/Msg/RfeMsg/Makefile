OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/RfeMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libRfeMsg.so
SOOBJS = RfeMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz

all	: $(COMPSO)
