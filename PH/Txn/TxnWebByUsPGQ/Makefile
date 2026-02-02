OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnWebByUsPGQ
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnWebByUsPGQ.so
SOOBJS = TxnWebByUsPGQ.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
