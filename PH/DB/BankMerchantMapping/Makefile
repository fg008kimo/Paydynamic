OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/BankMerchantMapping
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBBankMerchantMapping.so
SOOBJS =  BankMerchantMapping.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
