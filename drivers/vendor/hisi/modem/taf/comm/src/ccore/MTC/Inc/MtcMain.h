

#ifndef __MTCMAIN_H__
#define __MTCMAIN_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/

/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/

/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/

/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/

/*****************************************************************************
  7 STRUCT����
*****************************************************************************/

typedef VOS_VOID (*MTC_MSG_PROC_FUNC)(VOS_VOID* pMsg);


typedef struct
{
    VOS_UINT32                          ulMsgType;                              /* MTC������ϢID */
    MTC_MSG_PROC_FUNC                   pProcMsgFunc;
}MTC_MSG_PROC_STRU;
/*****************************************************************************
  8 UNION����
*****************************************************************************/

/*****************************************************************************
  9 OTHERS����
*****************************************************************************/

/*****************************************************************************
  10 ��������
*****************************************************************************/
VOS_UINT32 MTC_SearchMsgProcTab(
    VOS_UINT32                          ulMsgCnt,
    VOS_VOID                           *pstMsg,
    const MTC_MSG_PROC_STRU            *pstMsgProcTab
);

VOS_VOID MTC_RcvModem0MmaMsg(struct MsgCB *pstMsg);

VOS_VOID MTC_RcvModem1MmaMsg(struct MsgCB *pstMsg);

VOS_VOID MTC_RcvModem0TafMsg(struct MsgCB *pstMsg);

VOS_VOID MTC_RcvModem1TafMsg(struct MsgCB *pstMsg);

VOS_VOID MTC_RcvModem1GasMsg(struct MsgCB *pstMsg);

VOS_VOID MTC_RcvModem0TdsMsg(struct MsgCB *pstMsg);

VOS_VOID MTC_RcvModem0LteMsg(struct MsgCB *pstMsg);

VOS_VOID MTC_RcvModem0GasMsg(struct MsgCB *pstMsg);

VOS_VOID MTC_RcvModem0WasMsg(struct MsgCB *pstMsg);

VOS_VOID MTC_RcvCbpcaMsg(struct MsgCB *pstMsg);

/* Added by wx270776 for tas loop test, 2015-5-9, begin */
VOS_VOID MTC_RcvModem0TcMsg(
    struct MsgCB                       *pstMsg
);
VOS_VOID MTC_RcvModem1TcMsg(
    struct MsgCB                       *pstMsg
);
VOS_VOID MTC_RcvModem0ETcMsg(
    struct MsgCB                       *pstMsg
);
/* Added by wx270776 for tas loop test, 2015-5-9, end */

VOS_VOID MTC_ProcMsg(MsgBlock* pMsg);



#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of MtcMain.h */