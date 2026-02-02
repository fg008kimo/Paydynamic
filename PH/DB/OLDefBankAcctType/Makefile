OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/OLDefBankAcctType
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBOLDefBankAcctType.so
SOOBJS =  OLDefBankAcctType.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
