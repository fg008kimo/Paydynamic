OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnCctByUsSCK
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnCctByUsSCK.so
SOOBJS = TxnCctByUsSCK.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
