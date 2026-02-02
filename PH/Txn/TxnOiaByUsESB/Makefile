OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOiaByUsESB
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOiaByUsESB.so
SOOBJS = TxnOiaByUsESB.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
