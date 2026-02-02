OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/YpmMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libYpmMsg.so
SOOBJS = YpmMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
