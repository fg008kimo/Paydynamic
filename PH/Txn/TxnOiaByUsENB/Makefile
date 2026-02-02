OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOiaByUsENB
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOiaByUsENB.so
SOOBJS = TxnOiaByUsENB.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
