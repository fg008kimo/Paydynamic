OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/PsvMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libPsvMsg.so
SOOBJS = PsvMsg.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz  -ljson-c  -lexpat

all	: $(COMPSO)
