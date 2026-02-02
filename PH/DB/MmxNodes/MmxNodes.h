#ifndef _MMX_NODES_H_
#define _MMX_NODES_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Find(const unsigned char *csNodeId,
         char *cNodeType);

int GetAllNodesByType(const char cNodeType,
                   recordset_t* myRec);

int GetQByNode(const char *csNodeId, hash_t* hRec);
#ifdef __cplusplus
}
#endif

#endif
