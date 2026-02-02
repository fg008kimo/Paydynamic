OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOlnByUsSCK
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOlnByUsSCK.so
SOOBJS = TxnOlnByUsSCK.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
