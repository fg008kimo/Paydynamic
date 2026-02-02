OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/BankFeeMapping
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBBankFeeMapping.so
SOOBJS =  BankFeeMapping.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
