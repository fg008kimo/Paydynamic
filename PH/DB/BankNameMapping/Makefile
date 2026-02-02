OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/BankNameMapping
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBBankNameMapping.so
SOOBJS =  BankNameMapping.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
