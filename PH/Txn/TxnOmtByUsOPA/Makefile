OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOmtByUsOPA
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOmtByUsOPA.so
SOOBJS = TxnOmtByUsOPA.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
