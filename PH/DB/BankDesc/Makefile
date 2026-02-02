OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/BankDesc
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBBankDesc.so
SOOBJS =  BankDesc.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
