OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmsByUsIPM
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmsByUsIPM.so
SOOBJS = TxnMmsByUsIPM.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
