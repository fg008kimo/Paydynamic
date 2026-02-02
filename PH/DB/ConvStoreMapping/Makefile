OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/ConvStoreMapping
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBConvStoreMapping.so
SOOBJS =  ConvStoreMapping.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
