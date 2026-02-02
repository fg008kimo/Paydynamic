OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMinByUsVRI
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMinByUsVRI.so
SOOBJS = TxnMinByUsVRI.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
