OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnCctByUsACK
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnCctByUsACK.so
SOOBJS = TxnCctByUsACK.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
