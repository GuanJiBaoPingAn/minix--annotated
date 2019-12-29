/* 该表为每个进程一个插槽。包含了每个进程的调度信息
 * This table has one slot per process.  It contains scheduling information
 * for each process.
 */
#include <limits.h>

#include <minix/bitmap.h>

/* EXTERN should be extern except in main.c, where we want to keep the struct */
#ifdef _MAIN
#undef EXTERN
#define EXTERN
#endif

#ifndef CONFIG_SMP
#define CONFIG_MAX_CPUS 1
#endif

/**
 * We might later want to add more information to this table, such as the
 * process owner, process group or cpumask.
 */

EXTERN struct schedproc {
	endpoint_t endpoint;	/* process endpoint id 进程端点 */
	endpoint_t parent;	/* parent endpoint id 父进程端点 */
	unsigned flags;		/* flag bits */

	/* User space scheduling */
	unsigned max_priority;	/* this process' highest allowed priority 该进程允许的最大优先级 */
	unsigned priority;		/* the process' current priority 进程的当前优先级 */
	unsigned time_slice;		/* this process's time slice 进程的时间片 */
	unsigned cpu;		/* what CPU is the process running on 进程在哪个cpu 上运行 */
	bitchunk_t cpu_mask[BITMAP_CHUNKS(CONFIG_MAX_CPUS)]; /* what CPUs is the
								process allowed
								to run on 该进程能在哪些cpu 上运行 */
} schedproc[NR_PROCS];

/* Flag values */
#define IN_USE		0x00001	/* set when 'schedproc' slot in use schedproc 插槽正在使用 */
