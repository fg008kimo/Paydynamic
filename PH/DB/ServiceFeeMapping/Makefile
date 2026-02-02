OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/ServiceFeeMapping
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBServiceFeeMapping.so
SOOBJS =  ServiceFeeMapping.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
