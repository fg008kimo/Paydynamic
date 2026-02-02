OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMinByUsVPT
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMinByUsVPT.so
SOOBJS = TxnMinByUsVPT.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
