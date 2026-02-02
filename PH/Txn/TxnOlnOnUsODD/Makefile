OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOlnOnUsODD
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOlnOnUsODD.so
SOOBJS = TxnOlnOnUsODD.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
