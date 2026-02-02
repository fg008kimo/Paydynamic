OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnOplByUsSCK
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnOplByUsSCK.so
SOOBJS = TxnOplByUsSCK.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
