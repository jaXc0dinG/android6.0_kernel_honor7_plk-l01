
#ifndef __BST_APP_HEARTBEAT_H__
#define __BST_APP_HEARTBEAT_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/

#include "BST_CORE_RegistryDefine.h"
#include "BST_OS_Memory.h"
#include "BST_APP_Define.h"
#include "BST_LIB_String.h"
#include "BST_CORE_NPTask.h"

#if (BST_OS_VER == BST_HISI_VOS)
#pragma pack(4)
#elif(BST_OS_VER == BST_WIN32)
#pragma pack(push, 4)
#endif

/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define BST_HB_MAX_CONFIG_BYTES         ( 32 )

#if ( BST_OS_VER == BST_WIN32 && BST_VER_TYPE == BST_DBG_VER )
#define BST_HB_IsBaseCfged( enFlag )    ( ( ( enFlag ) & ( BST_CFGFLG_ADDR | BST_CFGFLG_CYCL |  BST_CFGFLG_TYPE ) ) \
                                                      == ( BST_CFGFLG_ADDR | BST_CFGFLG_CYCL |  BST_CFGFLG_TYPE ) )
#else
#define BST_HB_IsBaseCfged( enFlag )    ( ( ( enFlag ) & ( BST_CFGFLG_ADDR | BST_CFGFLG_CYCL |  BST_CFGFLG_TYPE | BST_CFGFLG_PRTY ) ) \
                                                      == ( BST_CFGFLG_ADDR | BST_CFGFLG_CYCL |  BST_CFGFLG_TYPE | BST_CFGFLG_PRTY ) )
#endif

#define BST_HB_IsHbSnUsed( HbPktInfo )  ( BST_TRUE == (HbPktInfo)->bSnUsed )
#define BST_HB_DEFAULT_RETRY_TIMES      ( 1 )
#define BST_HB_INVALID_RETRY_TIMES      ( 0 )

#define BST_HB_U32TOU8(d0, d1, d2, d3, ipaddr)     BST_IP_GetU8Addr(d0, d1, d2, d3, ipaddr)

#define BST_HB_IsHbSeqValid( SerNum, HbSnInfo )    ( ( (HbSnInfo)->ulSnBegin <= (HbSnInfo)->ulSnMax )  \
                                                     && ( (HbSnInfo)->ulSnBegin >= (HbSnInfo)->ulSnMin )\
                                                     && ( (SerNum) <= (HbSnInfo)->ulSnMax)              \
                                                     && ( (SerNum) >= (HbSnInfo)->ulSnMin) )
#define BST_HB_CLONE_SOCKET(ErrMsg, RtnPtr )        if ( BST_IsIpBaseCfged ( ulBaseCfged ) ){\
                                                    (ErrMsg)              = m_pSocket->Clone();          \
                                                    if ( BST_IP_ERR_OK != (ErrMsg) ){                    \
                                                        (RtnPtr)             = BST_NULL_PTR;             \
                                                    } }

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
/*****************************************************************************
 ö����    : HB_CHECK_TYPE_ENUM
 Э�����  :
 ASN.1���� :
 ö��˵��  : Modem֧�ֵ�У������
*****************************************************************************/
enum BST_APP_HB_CHECK_TYPE_ENUM
{
    BST_APP_HB_INVALID_CHK_TYPE         = 0,            /* �Ƿ�У������ */
    BST_APP_HB_NO_CHK_TYPE,                             /* ��У�� */
    BST_APP_HB_CHKSUM_TYPE,                             /* checksumУ�� */
    BST_APP_HB_CHKCRC_TYPE,                             /* CRCУ�� */
    BST_APP_HB_CHK_TYPE_BUTT
} ;
typedef BST_UINT32                       BST_APP_HB_CHECK_TYPE_ENUM_UINT32;

/*****************************************************************************
   4 STRUCT����
*****************************************************************************/
/*****************************************************************************
 �ṹ��    : SERNO_HB_INFO_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : ����Ӧ����������seq�ֶ�
*****************************************************************************/
typedef struct
{
    BST_UINT32                          ulSnBegin;     /* ������seq�ֶεĿ�ʼֵ */
    BST_UINT32                          ulSnStep;      /* ������seq�ֶεĲ��� */
    BST_UINT32                          ulSnMin;       /* ����seq�ֶε���Сֵ  */
    BST_UINT32                          ulSnMax;       /* ����seq�ֶε����ֵ */
} SERNO_HB_INFO_STRU;

/*****************************************************************************
 �ṹ��    : HB_PCKT_CONTENT_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : Ӧ��������������
*****************************************************************************/
typedef struct
{
    BST_LIB_StrStru                    *pRespContent;  /* �����ظ��������� */
    BST_LIB_StrStru                    *pFixedContent; /* �������̶��ֶε����� */
    BST_LIB_StrStru                    *pCipherKey;    /* ������ */
    BST_BOOL                            bSnUsed;       /* ����������ֶ��Ƿ����� */
    SERNO_HB_INFO_STRU                 *pstSnInfoPkt;  /* ������seq�ֶε����� */
    BST_APP_ENCRP_MODE_ENUM_UINT32      enSecMode;     /* ����ģʽ */
    BST_APP_HB_CHECK_TYPE_ENUM_UINT32   enCheckType;   /* У������ */
    BST_UINT16                          usHbPktLength; /* ���������ܳ��� */
} HB_PCKT_CONTENT_STRU;

/*****************************************************************************
   5 �ඨ��
*****************************************************************************/
class HeartBeat: BST_PUBLIC BST_IP_CNetRcver, BST_PUBLIC BST_CORE_CNPTask,
    BST_PUBLIC BST_OS_CTimerCb
{
BST_PUBLIC:
    HeartBeat( BST_PROCID_T usInProcID, BST_TASKID_T usInTaskID );
    ~HeartBeat( BST_VOID );

BST_PRIVATE:
    BST_BOOL                 InitHeartBeat( BST_VOID );

    BST_BOOL                 InitRegedit( BST_VOID );

    BST_VOID                 Entry( BST_VOID );

    BST_BOOL                 SendHbPkt( BST_VOID );

    BST_IP_ERR_T             Connectd( BST_FD_T fd );

    BST_IP_PKTPROC_MODE_ENUM Received(
        BST_FD_T                    fd,
        const BST_UINT8            *const pucData,
        const BST_UINT16            usLength );
    BST_VOID                 Closed ( BST_FD_T fd );

    BST_VOID                 ErrClosed(
        BST_FD_T                    fd,
        BST_IP_ERR_T                enIpErr );

    BST_ERR_ENUM_UINT8       ParsePkt(
        const BST_UINT8            *pucRcvData,
        const BST_UINT16            usLength );

    BST_UINT8               *ComposeHbPkt(
        BST_UINT8                  *pucCmpsData,
        BST_UINT16                 *pusSndLen,
        BST_UINT16                  usCmpsLen );

    BST_BOOL                 IsRespPkt(
        const BST_UINT8            *pucData,
        BST_UINT8                  *pRespData,
        BST_UINT16                  usDataLen,
        BST_UINT16                  usRespLen ) const;

    BST_BOOL                 IsConfigOk( BST_VOID ) const;

    BST_VOID                 TimerExpired(
        BST_OS_TIMERID_T            ulId,
        BST_VOID                   *pvPara );

    BST_UINT16               PidInquired(
        BST_CORE_PID_ENUM_UINT16    enParamId,
        BST_UINT16                  usDataSize,
        BST_VOID *const             pData );

    /* ���½ӿ���������AP���·���������Ϣ */
    BST_ERR_ENUM_UINT8       PidConfiged(
        BST_CORE_PID_ENUM_UINT16    enParamId,
        BST_UINT16                  usLen,
        const BST_VOID             *const pData,
        BST_UINT32                  ulBaseCfged,
        BST_UINT8                 **pucNewAddr );

    BST_BOOL                 SetSocketInfo( BST_SCKT_TYPE_ENUM_UINT32 enSocketType );

    BST_UINT8               *ConfigType(
        const BST_VOID             *const pData,
        BST_UINT16                  usLen );

    BST_UINT8               *SetHbSnInfo(
        const BST_VOID             *const pData,
        BST_UINT16                  usLen );

    BST_UINT8               *SetCipherKey(
        BST_UINT8                  *pucCipherKey,
        BST_UINT16                  usLength );

    BST_UINT8               *SetEncrypType(
        BST_UINT8                  *pData,
        BST_UINT16                  usLen );

    BST_UINT8               *SetCheckType(
        BST_UINT8                  *pData,
        BST_UINT16                  usLen );

    BST_UINT8               *SetFixedContent(
        BST_UINT8                  *pucFixContent,
        BST_UINT16                  usFixLength );

    BST_UINT8               *SetRespContent(
        BST_UINT8                  *pucRespContent,
        BST_UINT16                  usRespLength );

    BST_UINT8               *SetAppTxRetry(
        const BST_VOID             *const pData,
        BST_UINT16                  usLen );

    HeartBeat(const HeartBeat& hearbeat);
    HeartBeat& operator = ( const HeartBeat& hearbeat );
    HB_PCKT_CONTENT_STRU     *m_pstHbPktContent;
    BST_UINT32                m_ulHbSerNum;
    TX_HB_RETRY_TIMER_STRU    m_stHbTxRetry;
};

/*****************************************************************************
  6 OTHERS����
*****************************************************************************/

#if (BST_OS_VER == BST_HISI_VOS)
#pragma pack()
#elif(BST_OS_VER == BST_WIN32)
#pragma pack(pop)
#endif

#endif