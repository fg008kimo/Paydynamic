OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmsByUs2Node
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmsByUs2Node.so
SOOBJS = TxnMmsByUs2Node.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
