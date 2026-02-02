OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/Txn/TxnMgtByUsHOD
COMPLIBHOME = $(HOME)/lib/Txn
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libTxnMgtByUsHOD.so
SOOBJS = TxnMgtByUsHOD.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lmyrecordset

all     : $(COMPSO)
