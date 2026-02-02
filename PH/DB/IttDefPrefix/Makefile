OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/IttDefPrefix
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBIttDefPrefix.so
SOOBJS =  IttDefPrefix.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
