OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmmByUsCEE
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmmByUsCEE.so
SOOBJS = TxnMmmByUsCEE.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
