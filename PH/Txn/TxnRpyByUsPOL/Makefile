OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnRpyByUsPOL
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnRpyByUsPOL.so
SOOBJS = TxnRpyByUsPOL.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
