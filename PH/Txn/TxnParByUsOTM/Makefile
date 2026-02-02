OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnParByUsOTM
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnParByUsOTM.so
SOOBJS = TxnParByUsOTM.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
