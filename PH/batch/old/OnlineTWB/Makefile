OBJHOME = $(HOME)/obj/BATCH
COMPHOME = $(HOME)/src/batch/OnlineWTB
COMPLIBHOME = $(HOME)/lib
COMPOBJHOME = $(COMPHOME)/obj
BIN_PATH=$(HOME)/bin/batch
LIB_PATH=/usr/lib64
SOAPCPP=/usr/local/bin/soapcpp2

include $(HOME)/config/Make.rules

CPPFLAGS += -I$(HOME)/src/MQ -I$(HOME)/src/Tools/Ndbm  -I..
LDLIBS +=   /usr/local/lib/libgsoapssl.a  -lutilitys -lprivatekey -ldbuser -ldbutility -lgsoap -lssl -lcrypto -lz  -DWITH_OPENSSL -DWITH_GZIP   -Wall -Werror -lmyrecordset
BIN	= OnlineWTBHaiPay.exec
.c.o:
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) -c $<
	mv $*.o $(OBJHOME)

all     : $(BIN)

OnlineWTBHaiPay.exec	: OnlineWTBHaiPay.o OnlineWTBHaiPayDB.o soapC.o soapClient.o
	$(CPP) $(OBJHOME)/OnlineWTBHaiPay.o $(OBJHOME)/OnlineWTBHaiPayDB.o $(OBJHOME)/soapC.o $(OBJHOME)/soapClient.o $(SHARED_LIB_OBJS) $(LDFLAGS) $(LDLIBS) -o $@
	mv $(BIN) $(BIN_PATH)


clean:
	rm -f $(BIN_PATH)/$(BIN)
	rm -f *.xml
	rm -f soap*
	rm -f *.nsmap

s2c     :
	$(SOAPCPP) -c haipay.h
