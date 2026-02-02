OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnParByUsMTO
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnParByUsMTO.so
SOOBJS = TxnParByUsMTO.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
