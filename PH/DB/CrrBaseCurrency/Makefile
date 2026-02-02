OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/CrrBaseCurrency
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBCrrBaseCurrency.so
SOOBJS =  CrrBaseCurrency.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
