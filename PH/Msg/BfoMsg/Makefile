OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/BfoMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libBfoMsg.so
SOOBJS = BfoMsg.o 

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz

all	: $(COMPSO)
