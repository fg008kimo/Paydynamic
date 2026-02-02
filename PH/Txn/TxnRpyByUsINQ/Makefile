OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnRpyByUsINQ
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnRpyByUsINQ.so
SOOBJS = TxnRpyByUsINQ.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
