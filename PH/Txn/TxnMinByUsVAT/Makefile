OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMinByUsVAT
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMinByUsVAT.so
SOOBJS = TxnMinByUsVAT.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
