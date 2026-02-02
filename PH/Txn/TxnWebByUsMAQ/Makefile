OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnWebByUsMAQ
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnWebByUsMAQ.so
SOOBJS = TxnWebByUsMAQ.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
