OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/SkeMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libSkeMsg.so
SOOBJS = SkeMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash -lz

all	: $(COMPSO)
