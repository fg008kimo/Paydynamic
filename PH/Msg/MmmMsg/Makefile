OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/MmmMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libMmmMsg.so
SOOBJS = MmmMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz -lexpat

all	: $(COMPSO)
