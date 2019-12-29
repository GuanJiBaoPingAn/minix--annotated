#ifndef _I386_IPCCONST_H_
#define _I386_IPCCONST_H_

#define KERVEC_INTR 32     /* syscall trap to kernel 系统调用陷入内核 */
#define IPCVEC_INTR 33     /* ipc trap to kernel ipc 陷入内核 */

#define KERVEC_UM 34     /* syscall trap to kernel, user-mapped code */
#define IPCVEC_UM 35     /* ipc trap to kernel, user-mapped code  */

#define IPC_STATUS_REG		bx

#endif  /* _I386_IPCCONST_H_ */
