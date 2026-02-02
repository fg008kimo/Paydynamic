OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOlnByUsACK
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOlnByUsACK.so
SOOBJS = TxnOlnByUsACK.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
