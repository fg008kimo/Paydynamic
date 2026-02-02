OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnAlpByUsINQ
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnAlpByUsINQ.so
SOOBJS = TxnAlpByUsINQ.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
