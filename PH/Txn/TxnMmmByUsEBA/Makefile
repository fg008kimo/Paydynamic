OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmmByUsEBA
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmmByUsEBA.so
SOOBJS = TxnMmmByUsEBA.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
