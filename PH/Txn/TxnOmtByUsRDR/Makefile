OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOmtByUsRDR
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOmtByUsRDR.so
SOOBJS = TxnOmtByUsRDR.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
