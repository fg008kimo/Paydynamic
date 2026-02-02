OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMinByUsHDR
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMinByUsHDR.so
SOOBJS = TxnMinByUsHDR.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
