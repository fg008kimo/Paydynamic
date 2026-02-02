OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmmByUsCEA
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmmByUsCEA.so
SOOBJS = TxnMmmByUsCEA.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
