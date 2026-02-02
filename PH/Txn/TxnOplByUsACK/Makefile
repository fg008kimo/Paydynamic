OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOplByUsACK
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOplByUsACK.so
SOOBJS = TxnOplByUsACK.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
