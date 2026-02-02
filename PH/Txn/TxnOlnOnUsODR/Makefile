OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOlnOnUsODR
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOlnOnUsODR.so
SOOBJS = TxnOlnOnUsODR.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
