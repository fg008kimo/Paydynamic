OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOlnOnUsODI
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOlnOnUsODI.so
SOOBJS = TxnOlnOnUsODI.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
