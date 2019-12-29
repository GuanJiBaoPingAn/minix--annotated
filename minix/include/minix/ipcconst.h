#ifndef _IPC_CONST_H
#define _IPC_CONST_H

#include <machine/ipcconst.h>

 /* 系统调用时的状态 System call numbers that are passed when trapping to the kernel. */
#define SEND		   1	/* blocking send 阻塞发送 */
#define RECEIVE		   2	/* blocking receive 同步接收 */
#define SENDREC	 	   3  	/* SEND + RECEIVE 发送和接收 */
#define NOTIFY		   4	/* asynchronous notify 异步通知 */
#define SENDNB             5    /* nonblocking send 非阻塞发送 */
#define MINIX_KERNINFO     6    /* request kernel info structure 请求内核消息结果 */
#define SENDA		   16	/* asynchronous send 异步发送 */
#define IPCNO_HIGHEST	SENDA
/* Check that the message payload type doesn't grow past the maximum IPC payload size.
 * This is a compile time check. */
#define _ASSERT_MSG_SIZE(msg_type) \
    typedef int _ASSERT_##msg_type[/* CONSTCOND */sizeof(msg_type) == 56 ? 1 : -1]

/* Macros for IPC status code manipulation. */
#define IPC_STATUS_CALL_SHIFT	0
#define IPC_STATUS_CALL_MASK	0x3F
#define IPC_STATUS_CALL(status)	\
	(((status) >> IPC_STATUS_CALL_SHIFT) & IPC_STATUS_CALL_MASK)
#define IPC_STATUS_CALL_TO(call) \
	(((call) & IPC_STATUS_CALL_MASK) << IPC_STATUS_CALL_SHIFT)

#define IPC_FLG_MSG_FROM_KERNEL	1 /* this message originated in the kernel on
				     behalf of a process, this is a trusted
				     message, never reply to the sender
				 */
#define IPC_STATUS_FLAGS_SHIFT	16
#define IPC_STATUS_FLAGS(flgs)	((flgs) << IPC_STATUS_FLAGS_SHIFT)
#define IPC_STATUS_FLAGS_TEST(status, flgs)	\
		(((status) >> IPC_STATUS_FLAGS_SHIFT) & (flgs))
#endif /* IPC_CONST_H */
