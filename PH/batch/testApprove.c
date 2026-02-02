#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "queue_utility.h"
#include "mydb.h"
#include "dbutility.h"
#include "myhash.h"
#include "myrecordset.h"
#include "ObjPtr.h"
#include "gateway.h"
#include "internal.h"


char            csHandler[PD_TMP_BUF_LEN + 1];
static int parse_arg(int argc,char **argv);

OBJPTR(Txn);

int main(int argc, char **argv)
{
        int     iRet;

	if (argc < 2) {
                fprintf(stderr, "Usage : testApprove -h Handler\n");
                exit(1);
        }

        if (parse_arg(argc, argv) != PD_OK) {
                exit(1);
        }

	hash_t  *hContext;
	hash_t  *hRequest;
	hash_t  *hResponse;

	hContext = (hash_t*) malloc (sizeof(hash_t));
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext,0);
	hash_init(hRequest,0);
	hash_init(hResponse,0);

	ConnectDB();

	TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
	if (TxnObjPtr) {
		iRet = (unsigned long) (*TxnObjPtr)(hContext,hRequest,hResponse);
	}
	else {
		fprintf(stderr,"Error Create Object\n");
	}

	if (iRet == PD_OK) {
		fprintf(stderr,"Command Sent\n");
	}
	else {
		fprintf(stderr,"Error Sending Command\n");
                TxnAbort();
	}

	DisconnectDB();
	hash_destroy(hContext);
        hash_destroy(hRequest);
        hash_destroy(hResponse);
        FREE_ME(hContext);
        FREE_ME(hRequest);
        FREE_ME(hResponse);


	return iRet;


}

int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(csHandler,"");

        while ((c = getopt(argc,argv,"h:")) != EOF) {
                switch (c) {
                        case 'h':
                                strcpy(csHandler, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(csHandler,""))
                return FAILURE;

        return SUCCESS;
}

