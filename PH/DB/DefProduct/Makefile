OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/DB/DefProduct
COMPLIBHOME = $(HOME)/lib/DB
CPPFLAGS += -I$(COMPHOME) 
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libDBDefProduct.so
SOOBJS =  DefProduct.o

include $(HOME)/config/Make.rules

LDLIBS += -lmyrecordset

all	: $(COMPSO)
