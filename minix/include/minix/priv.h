/* Privilege-related definitions. 权限相关的定义 */

#ifndef _MINIX_PRIV_H
#define _MINIX_PRIV_H

#include <minix/com.h>
#include <minix/config.h>

/* Static privilege id definitions. */
#define NR_STATIC_PRIV_IDS         NR_BOOT_PROCS
#define is_static_priv_id(id)	   (id >= 0 && id < NR_STATIC_PRIV_IDS)
#define static_priv_id(n)          (NR_TASKS + (n))

/* Unprivileged user processes all share the privilege structure of the
 * user processesess.
 * This id must be fixed because it is used to check send mask entries.
 */
#define USER_PRIV_ID	static_priv_id(ROOT_USR_PROC_NR)
/* Specifies a null privilege id.
 */
#define NULL_PRIV_ID	(-1)

/* Allowed targets. */
#define NO_M      (-1)              /* no targets allowed */
#define ALL_M     (-2)              /* all targets allowed */

/* Allowed calls. */
#define NO_C      (-1)              /* no calls allowed */
#define ALL_C     (-2)              /* all calls allowed */
#define NULL_C    (-3)              /* null call entry */

/*
 * Default privilege settings used in the system
 */
/* privilege flags */
#define IDL_F     (SYS_PROC | BILLABLE) /* idle task is not preemptible as we
                                         * don't want it to interfere with the
                                         * timer tick interrupt handler code.
                                         * Unlike other processes idle task is
                                         * handled in a special way and is
                                         * preempted always if timer tick occurs
                                         * and there is another runnable process
                                         * idle flag 空闲标识
                                         */
#define TSK_F     (SYS_PROC)                       /* other kernel tasks task flag 其他内核任务标识 */
#define SRV_F     (SYS_PROC | PREEMPTIBLE)         /* system services service flag 系统服务标识 */
#define DSRV_F    (SRV_F | DYN_PRIV_ID)            /* dynamic system services 动态系统服务标识 */
#define RSYS_F    (SRV_F | ROOT_SYS_PROC)          /* root sys proc 系统根进程标识 */
#define VM_F      (SYS_PROC | VM_SYS_PROC)         /* vm VM 进程标识 */
#define USR_F     (BILLABLE | PREEMPTIBLE)         /* user processes 用户进程标识 */
#define IMM_F     (ROOT_SYS_PROC | VM_SYS_PROC | PREEMPTIBLE) /* immutable 不可变进程标识 */

/* init flags 初始化标识 */
#define TSK_I     0                               /* all kernel tasks 内核任务 */
#define SRV_I     0                               /* system services 系统服务 */
#define DSRV_I    0                               /* dynamic system services 动态系统服务 */
#define USR_I     0                               /* user processes 用户进程 */

/* allowed traps 允许陷阱 */
#define CSK_T     (1 << RECEIVE)                   /* clock and system 时钟和系统调用 */
#define TSK_T     0                                /* other kernel tasks 其他内核任务 */
#define SRV_T     (~0)                             /* system services 系统任务 */
#define DSRV_T    (~0)                             /* dynamic system services 动态系统任务 */
#define USR_T     (1 << SENDREC)                   /* user processes 用户进程 */

/* allowed targets 允许目标 */
#define TSK_M     NO_M                             /* all kernel tasks 允许所有内核任务 */
#define SRV_M     ALL_M                            /* system services 允许所有系统服务 */
#define DSRV_M    ALL_M                            /* dynamic system services 允许所有动态系统服务 */
#define USR_M     ALL_M                            /* user processes 允许所有用户进程 */

/* allowed kernel calls 允许的内核调用 */
#define TSK_KC    NO_C                             /* all kernel tasks 所有内核进程 */
#define SRV_KC    ALL_C                            /* dynamic system services 系统服务 */
#define DSRV_KC   ALL_C                            /* default sys proc 动态系统服务 */
#define USR_KC    NO_C                             /* user processes 用户进程 */

/* allowed vm calls 允许的VM 调用 */
#define SRV_VC    ALL_C                            /* dynamic system services */
#define DSRV_VC   ALL_C                            /* default sys proc */
#define USR_VC    ALL_C                            /* user processes */

/* signal manager 信号管理器 */
#define SRV_SM    ROOT_SYS_PROC_NR                 /* system services */
#define DSRV_SM   ROOT_SYS_PROC_NR                 /* dynamic system services */
#define USR_SM    PM_PROC_NR                       /* user processes */

/* scheduler 调度器 */
#define SRV_SCH   KERNEL                           /* system services */
#define DSRV_SCH  SCHED_PROC_NR                    /* dynamic system services */
#define USR_SCH   NONE                             /* user processes */

/* scheduling priority queue. 调度优先级队列 */
#define SRV_Q     USER_Q                           /* system services */
#define DSRV_Q    USER_Q                           /* dynamic system services */
#define USR_Q     USER_Q                           /* user processes */

/* scheduling quantum. 调度量 */
#define SRV_QT    USER_QUANTUM                     /* system services */
#define DSRV_QT   USER_QUANTUM                     /* dynamic system services */
#define USR_QT    USER_QUANTUM                     /* user processes */

/* default CPU 默认的CPU */
#define DSRV_CPU USER_DEFAULT_CPU

#endif /* _MINIX_PRIV_H */
