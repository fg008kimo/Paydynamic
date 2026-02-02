OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/YseMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libYseMsg.so
SOOBJS = YseMsg.o  YseXml.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz -lexpat

all	: $(COMPSO)
