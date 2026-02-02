OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMinByUsVPS
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMinByUsVPS.so
SOOBJS = TxnMinByUsVPS.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
