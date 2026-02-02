OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/BankMapping
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBBankMapping.so
SOOBJS =  BankMapping.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
