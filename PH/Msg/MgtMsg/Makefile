OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/MgtMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libMgtMsg.so
SOOBJS = MgtMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz -lexpat

all	: $(COMPSO)
