OBJHOME = $(HOME)/obj
COMPHOME = $(HOME)/src/BO/BOIpRegion
COMPLIBHOME = $(HOME)/lib/BO
CPPFLAGS += -I$(COMPHOME)
COMPOBJHOME = $(COMPHOME)/obj
COMPSO = libBOIpRegion.so
SOOBJS = BOIpRegion.o

include $(HOME)/config/Make.rules

LDLIBS +=  -lIP2Location

all     : $(COMPSO)
