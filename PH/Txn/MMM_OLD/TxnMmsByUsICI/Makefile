OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMmsByUsICI
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMmsByUsICI.so
SOOBJS = TxnMmsByUsICI.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
