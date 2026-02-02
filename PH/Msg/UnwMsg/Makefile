OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Msg/UnwMsg
COMPLIBHOME = $(HOME)/lib/Msg
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libUnwMsg.so
SOOBJS = UnwMsg.o UnwXml.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyhash  -lz  -ljson-c  -lexpat

all	: $(COMPSO)
