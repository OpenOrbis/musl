#ifndef _SYS_PTRACE_H
#define _SYS_PTRACE_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// Updated with BSD header.
#define PT_TRACE_ME     0       /* child declares it's being traced */
#define PT_READ_I       1       /* read word in child's I space */
#define PT_READ_D       2       /* read word in child's D space */
/* was  PT_READ_U       3        * read word in child's user structure */
#define PT_WRITE_I      4       /* write word in child's I space */
#define PT_WRITE_D      5       /* write word in child's D space */
/* was  PT_WRITE_U      6        * write word in child's user structure */
#define PT_CONTINUE     7       /* continue the child */
#define PT_KILL         8       /* kill the child process */
#define PT_STEP         9       /* single step the child */

#define PT_ATTACH       10      /* trace some running process */
#define PT_DETACH       11      /* stop tracing a process */
#define PT_IO           12      /* do I/O to/from stopped process. */
#define PT_LWPINFO      13      /* Info about the LWP that stopped. */
#define PT_GETNUMLWPS   14      /* get total number of threads */
#define PT_GETLWPLIST   15      /* get thread list */
#define PT_CLEARSTEP    16      /* turn off single step */
#define PT_SETSTEP      17      /* turn on single step */
#define PT_SUSPEND      18      /* suspend a thread */
#define PT_RESUME       19      /* resume a thread */

#define PT_TO_SCE       20
#define PT_TO_SCX       21
#define PT_SYSCALL      22

#define PT_FOLLOW_FORK  23

#define PT_GETREGS      33      /* get general-purpose registers */
#define PT_SETREGS      34      /* set general-purpose registers */
#define PT_GETFPREGS    35      /* get floating-point registers */
#define PT_SETFPREGS    36      /* set floating-point registers */
#define PT_GETDBREGS    37      /* get debugging registers */
#define PT_SETDBREGS    38      /* set debugging registers */

#define PT_VM_TIMESTAMP 40      /* Get VM version (timestamp) */
#define PT_VM_ENTRY     41      /* Get VM map (entry) */

#define PT_FIRSTMACH    64      /* for machine-specific requests */

#include <bits/ptrace.h>
#include <signal.h>

#define __NEED_size_t
#define __NEED_sigset_t
#include <bits/alltypes.h>

struct ptrace_io_desc {
        int     piod_op;        /* I/O operation */
        void    *piod_offs;     /* child offset */
        void    *piod_addr;     /* parent offset */
        size_t  piod_len;       /* request length */
};

/*
 * Operations in piod_op.
 */
#define PIOD_READ_D     1       /* Read from D space */
#define PIOD_WRITE_D    2       /* Write to D space */
#define PIOD_READ_I     3       /* Read from I space */
#define PIOD_WRITE_I    4       /* Write to I space */

#define MAXCOMLEN       19              /* max command name remembered */

/* Argument structure for PT_LWPINFO. */
struct ptrace_lwpinfo {
        int     pl_lwpid;       /* LWP described. */
        int     pl_event;       /* Event that stopped the LWP. */
#define PL_EVENT_NONE   0
#define PL_EVENT_SIGNAL 1
        int     pl_flags;       /* LWP flags. */
#define PL_FLAG_SA      0x01    /* M:N thread */
#define PL_FLAG_BOUND   0x02    /* M:N bound thread */
#define PL_FLAG_SCE     0x04    /* syscall enter point */
#define PL_FLAG_SCX     0x08    /* syscall leave point */
#define PL_FLAG_EXEC    0x10    /* exec(2) succeeded */
#define PL_FLAG_SI      0x20    /* siginfo is valid */
#define PL_FLAG_FORKED  0x40    /* new child */
        sigset_t        pl_sigmask;     /* LWP signal mask */
        sigset_t        pl_siglist;     /* LWP pending signal */
        struct __siginfo pl_siginfo;    /* siginfo for signal */
        char            pl_tdname[MAXCOMLEN + 1]; /* LWP name */
        int             pl_child_pid;   /* New child pid */
};

/* Argument structure for PT_VM_ENTRY. */
struct ptrace_vm_entry {
        int             pve_entry;      /* Entry number used for iteration. */
        int             pve_timestamp;  /* Generation number of VM map. */
        unsigned long   pve_start;      /* Start VA of range. */
        unsigned long   pve_end;        /* End VA of range (incl). */
        unsigned long   pve_offset;     /* Offset in backing object. */
        unsigned int    pve_prot;       /* Protection of memory range. */
        unsigned int    pve_pathlen;    /* Size of path. */
        long            pve_fileid;     /* File ID. */
        uint32_t        pve_fsid;       /* File system ID. */
        char            *pve_path;      /* Path name of object. */
};

int ptrace(int _request, pid_t _pid, void* _addr, int _data);

#ifdef __cplusplus
}
#endif
#endif
