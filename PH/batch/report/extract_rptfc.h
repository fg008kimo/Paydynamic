#ifndef	_EXTRACT_RPTFC_H_
#define	_EXTRACT_RPTFC_H_

#define	PD_EOD_RPT002	"RPT002"
#define	PD_EOD_RPT003	"RPT003"
#define	PD_EOD_RPT004	"RPT004"
#define	PD_EOD_RPT005	"RPT005"
#define	PD_EOD_RPT006	"RPT006"
#define	PD_EOD_RPT007	"RPT007"
#define	PD_EOD_RPT008	"RPT008"
#define	PD_EOD_RPT009	"RPT009"
#define	PD_EOD_RPT010	"RPT010"
#define	PD_EOD_RPT011	"RPT011"
#define	PD_EOD_RPT012	"RPT012"
#define	PD_EOD_RPT013	"RPT013"
#define	PD_EOD_RPT014	"RPT014"
#define	PD_EOD_RPT015	"RPT015"
#define	PD_EOD_RPT016	"RPT016"
#define	PD_EOD_RPT017	"RPT017"

#define PD_ADJ_TYPE_DEBIT_DESC	"DEBIT" 
#define PD_ADJ_TYPE_CREDIT_DESC	"CREDIT" 

#ifdef __cplusplus
extern "C" {
#endif

int RPT015(const char* csPath,const char* csDate);
int RPT016(const char* csPath,const char* csDate);
int RPT017(const char* csPath,const char* csDate);

#ifdef __cplusplus
}
#endif

#endif

