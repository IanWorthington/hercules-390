/* CHANNEL.H    (c) Copyright Roger Bowler, 1994-2012                */
/*              ESA/390 Data Areas                                   */
/*                                                                   */
/*   Released under "The Q Public License Version 1"                 */
/*   (http://www.hercules-390.org/herclic.html) as modifications to  */
/*   Hercules.                                                       */

#ifndef _CHANNEL_H
#define _CHANNEL_H

/* Platform-independent storage operand definitions */

#include "htypes.h"         // (need Hercules fixed-size data types)


/* Channel Report Word definitions */
#define CRW_FLAGS_MASK  0xF0C00000      /* Flags mask                */
//      (unassigned)    0x80000000      /* (unassigned)              */
#define CRW_SOL         0x40000000      /* Solicited CRW             */
#define CRW_OFLOW       0x20000000      /* Overflow, some CRW's lost */
#define CRW_CHAIN       0x10000000      /* More CRW's describe event */
#define CRW_RSC_MASK    0x0F000000      /* Reporting-Source Code mask*/
#define CRW_RSC_MONIT   0x02000000      /* Channel Monitor is source */
#define CRW_RSC_SUBCH   0x03000000      /* Subchannel is source      */
#define CRW_RSC_CHPID   0x04000000      /* Channel Path is source    */
#define CRW_RSC_CAF     0x09000000      /* Config. Alert Facility    */
#define CRW_RSC_CSS     0x0B000000      /* Channel subsys is source  */
#define CRW_AR          0x00800000      /* Ancillary Report indicator*/
//      (unassigned)    0x00400000      /* (unassigned)              */
#define CRW_ERC_MASK    0x003F0000      /* Error-Recovery Code mask  */
#define CRW_ERC_NULL    0x00000000      /* Event Information Pending */
#define CRW_ERC_AVAIL   0x00010000      /* Available                 */
#define CRW_ERC_INIT    0x00020000      /* Initialized, no parms chg.*/
#define CRW_ERC_TEMP    0x00030000      /* Temporary error           */
#define CRW_ERC_ALERT   0x00040000      /* Installed, parms changed  */
#define CRW_ERC_ABORT   0x00050000      /* Terminal                  */
#define CRW_ERC_ERROR   0x00060000      /* Perm. error, not init'ed  */
#define CRW_ERC_RESET   0x00070000      /* Perm. error, initialized  */
#define CRW_ERC_MODFY   0x00080000      /* PIM, PAM or CHPIDs changed*/
#define CRW_ERC_RSTRD   0x000A0000      /* PIM, PAM or CHPID restored*/
#define CRW_RSID_MASK   0x0000FFFF      /* Reporting-Source ID mask  */

/* Bit settings for channel id */
#define CHANNEL_TYPE    0xF0000000      /* Bits 0-3=Channel type...  */
#define CHANNEL_SEL     0x00000000      /* ...selector channel       */
#define CHANNEL_MPX     0x10000000      /* ...byte multiplexor       */
#define CHANNEL_BMX     0x20000000      /* ...block multiplexor      */
#define CHANNEL_MODEL   0x0FFF0000      /* Bits 4-15=Channel model   */
#define CHANNEL_MAXIOEL 0x0000FFFF      /* Bits 16-31=Max.IOEL length*/


/* Operation-Request Block (ORB) structure definition */
typedef struct _ORB {
        FWORD   intparm;                /* Interruption parameter    */
        BYTE    flag4;                  /* Flag byte 4               */
        BYTE    flag5;                  /* Flag byte 5               */
        BYTE    lpm;                    /* Logical path mask         */
        BYTE    flag7;                  /* Flag byte 7               */
        FWORD   ccwaddr;                /* CCW address               */
        BYTE    csspriority;            /* CSS Priority              */
        BYTE    reserved_byte_13;       /* Reserved for future use   */
        BYTE    cupriority;             /* CU Priority               */
        BYTE    reserved_byte_15;       /* Reserved for future use   */
        FWORD   reserved_word_4;        /* Reserved for future use   */
        FWORD   reserved_word_5;        /* Reserved for future use   */
        FWORD   reserved_word_6;        /* Reserved for future use   */
        FWORD   reserved_word_7;        /* Reserved for future use   */
    } ORB;

/* Bit definitions for ORB flag byte 4 */
#define ORB4_KEY        0xF0            /* Subchannel protection key */
#define ORB4_S          0x08            /* Suspend control           */
#define ORB4_C          0x04            /* Streaming mode (FICON)    */
#define ORB4_M          0x02            /* Modification (FICON)      */
#define ORB4_Y          0x01            /* Synchronization (FICON)   */

/* Bit definitions for ORB flag byte 5 */
#define ORB5_F          0x80            /* CCW format                */
#define ORB5_P          0x40            /* Prefetch                  */
#define ORB5_I          0x20            /* Initial status interrupt  */
#define ORB5_A          0x10            /* Address limit checking    */
#define ORB5_U          0x08            /* Suppress susp interrupt   */
#define ORB5_B          0x04            /* Channel Program Type      */
#define ORB5_H          0x02            /* Format-2 IDAW control     */
#define ORB5_T          0x01            /* 2K format-2 IDAW control  */

/* Bit definitions for ORB flag byte 7 */
#define ORB7_L          0x80            /* Suppress incorrect length */
#define ORB7_D          0x40            /* MIDAW control          @MW*/
#define ORB7_RESV       0x3E            /* Reserved - must be 0   @MW*/
#define ORB7_X          0x01            /* ORB extension control     */

/* Path management control word structure definition */
typedef struct _PMCW {
/*000*/ FWORD   intparm;                /* Interruption parameter    */
/*004*/ BYTE    flag4;                  /* Flag byte 4               */
/*005*/ BYTE    flag5;                  /* Flag byte 5               */
/*006*/ HWORD   devnum;                 /* Device number             */
/*008*/ BYTE    lpm;                    /* Logical path mask         */
/*009*/ BYTE    pnom;                   /* Path not operational mask */
/*00A*/ BYTE    lpum;                   /* Last path used mask       */
/*00B*/ BYTE    pim;                    /* Path installed mask       */
/*00C*/ HWORD   mbi;                    /* Measurement block index   */
/*00E*/ BYTE    pom;                    /* Path operational mask     */
/*00F*/ BYTE    pam;                    /* Path available mask       */
/*010*/ BYTE    chpid[8];               /* Channel path identifiers  */
/*018*/ BYTE    zone;                   /* SIE zone                  */
/*019*/ BYTE    flag25;                 /* Flag byte 25              */
/*01A*/ BYTE    flag26;                 /* Reserved byte - must be 0 */
/*01B*/ BYTE    flag27;                 /* Flag byte 27              */
    } PMCW;

/* Bit definitions for PMCW flag byte 4 */
#define PMCW4_Q         0x80            /* QDIO available            */
#define PMCW4_ISC       0x38            /* Interruption subclass     */
#define PMCW4_A         0x01            /* Alternate Block Control   */
#define PMCW4_RESV      0x46            /* Reserved bits - must be 0 */

/* Bit definitions for PMCW flag byte 5 */
#define PMCW5_E         0x80            /* Subchannel enabled        */
#define PMCW5_LM        0x60            /* Limit mode...             */
#define PMCW5_LM_NONE   0x00            /* ...no limit checking      */
#define PMCW5_LM_LOW    0x20            /* ...lower limit specified  */
#define PMCW5_LM_HIGH   0x40            /* ...upper limit specified  */
#define PMCW5_LM_RESV   0x60            /* ...reserved value         */
#define PMCW5_MM        0x18            /* Measurement mode enable...*/
#define PMCW5_MM_MBU    0x10            /* ...meas.block.upd enabled */
#define PMCW5_MM_DCTM   0x08            /* Dev.conn.time.meas enabled*/
#define PMCW5_D         0x04            /* Multipath mode enabled    */
#define PMCW5_T         0x02            /* Timing facility available */
#define PMCW5_V         0x01            /* Subchannel valid          */

/* Bit definitions for PMCW flag byte 25 */
#define PMCW25_VISC     0x07            /* Guest ISC                 */
#define PMCW25_TYPE     0xE0            /* Subchannel Type           */
#define PMCW25_TYPE_0   0x00            /* I/O Subchannel            */
#define PMCW25_TYPE_1   0x20            /* CHSC subchannel           */
#define PMCW25_TYPE_2   0x40            /* Message subchannel        */
#define PMCW25_TYPE_3   0x60            /* ADM subchannel            */
#define PMCW25_RESV     0x18            /* Reserved bits             */


/* Bit definitions for PMCW flag byte 27 */
#define PMCW27_I        0x80            /* Interrupt Interlock Cntl  */
#define PMCW27_S        0x01            /* Concurrent sense mode     */
#define PMCW27_RESV     0x7E            /* Reserved bits - must be 0 */

/* Extended-Status Word (ESW) structure definition */
typedef struct _ESW {
        BYTE    scl0;                   /* Subchannel logout byte 0  */
        BYTE    lpum;                   /* Last path used mask       */
        BYTE    scl2;                   /* Subchannel logout byte 2  */
        BYTE    scl3;                   /* Subchannel logout byte 3  */
        BYTE    erw0;                   /* Extended report word byte0*/
        BYTE    erw1;                   /* Extended report word byte1*/
        BYTE    erw2;                   /* Extended report word byte2*/
        BYTE    erw3;                   /* Extended report word byte3*/
        FWORD   failaddr;               /* Failing storage address   */
        FWORD   resv2;                  /* Reserved word - must be 0 */
        FWORD   resv3;                  /* Reserved word - must be 0 */
    } ESW;

/* Bit definitions for subchannel logout byte 0 */
#define SCL0_ESF        0x7F            /* Extended status flags...  */
#define SCL0_ESF_KEY    0x40            /* ...key check              */
#define SCL0_ESF_MBPGK  0x20            /* ...meas.block prog.check  */
#define SCL0_ESF_MBDCK  0x10            /* ...meas.block data check  */
#define SCL0_ESF_MBPTK  0x08            /* ...meas.block prot.check  */
#define SCL0_ESF_CCWCK  0x04            /* ...CCW check              */
#define SCL0_ESF_IDACK  0x02            /* ...IDAW check             */

/* Bit definitions for subchannel logout byte 2 */
#define SCL2_R          0x80            /* Ancillary report bit      */
#define SCL2_FVF        0x7C            /* Field validity flags...   */
#define SCL2_FVF_LPUM   0x40            /* ...LPUM valid             */
#define SCL2_FVF_TC     0x20            /* ...termination code valid */
#define SCL2_FVF_SC     0x10            /* ...sequence code valid    */
#define SCL2_FVF_USTAT  0x08            /* ...device status valid    */
#define SCL2_FVF_CCWAD  0x04            /* ...CCW address valid      */
#define SCL2_SA         0x03            /* Storage access code...    */
#define SCL2_SA_UNK     0x00            /* ...access type unknown    */
#define SCL2_SA_RD      0x01            /* ...read                   */
#define SCL2_SA_WRT     0x02            /* ...write                  */
#define SCL2_SA_RDBK    0x03            /* ...read backward          */

/* Bit definitions for subchannel logout byte 3 */
#define SCL3_TC         0xC0            /* Termination code...       */
#define SCL3_TC_HALT    0x00            /* ...halt signal issued     */
#define SCL3_TC_NORM    0x40            /* ...stop, stack, or normal */
#define SCL3_TC_CLEAR   0x80            /* ...clear signal issued    */
#define SCL3_TC_RESV    0xC0            /* ...reserved               */
#define SCL3_D          0x20            /* Device status check       */
#define SCL3_E          0x10            /* Secondary error           */
#define SCL3_A          0x08            /* I/O error alert           */
#define SCL3_SC         0x07            /* Sequence code             */

/* Bit definitions for extended report word byte 0 */
#define ERW0_RSV        0x80            /* (reserved)                */
#define ERW0_L          0x40            /* Request Logging Only      */
#define ERW0_E          0x20            /* Extended Logout Pending   */
#define ERW0_A          0x10            /* Authorization check       */
#define ERW0_P          0x08            /* Path verification required*/
#define ERW0_T          0x04            /* Channel path timeout      */
#define ERW0_F          0x02            /* Failing storage addr valid*/
#define ERW0_S          0x01            /* Concurrent sense          */

/* Bit definitions for extended report word byte 1 */
#define ERW1_C          0x80            /* 2ndary CCW Addr. Validity */
#define ERW1_R          0x40            /* Fail. Stor. Addr. Format  */
#define ERW1_SCNT       0x3F            /* Concurrent sense count    */

/* Subchannel status word structure definition */
typedef struct _SCSW
{
    union
    {
        U32     word[3];                /* Words 0-2 for zeroing     */
        struct
        {
            FWORD   word0;              /* Word 0                    */
            FWORD   word1;              /* Word 1                    */
            FWORD   word2;              /* Word 2                    */
        };
        struct
        {
            BYTE    flag0;              /* Flag byte 0               */
            BYTE    flag1;              /* Flag byte 1               */
            BYTE    flag2;              /* Flag byte 2               */
            BYTE    flag3;              /* Flag byte 3               */
            FWORD   ccwaddr;            /* CCW address               */
            BYTE    unitstat;           /* Device status             */
            BYTE    chanstat;           /* Subchannel status         */
            HWORD   count;              /* Residual byte count       */
        };
    };
} SCSW;

typedef enum                            /* SCSW Status types         */
{                                       /* ...                       */
    scsw_pci    = 2,                    /* PCI Status                */
    scsw_normal = 1,                    /* Normal Status             */
    scsw_attn   = 0                     /* Attention Status          */
} scsw_type;                            /* ...                       */

/* Bit definitions for SCSW flag byte 0 */
#define SCSW0_KEY       0xF0            /* Subchannel protection key */
#define SCSW0_S         0x08            /* Suspend control           */
#define SCSW0_L         0x04            /* ESW format (logout stored)*/
#define SCSW0_CC        0x03            /* Deferred condition code...*/
#define SCSW0_CC_0      0x00            /* ...condition code 0       */
#define SCSW0_CC_1      0x01            /* ...condition code 1       */
#define SCSW0_CC_3      0x03            /* ...condition code 3       */

/* Bit definitions for SCSW flag byte 1 */
#define SCSW1_F         0x80            /* CCW format                */
#define SCSW1_P         0x40            /* Prefetch                  */
#define SCSW1_I         0x20            /* Initial status interrupt  */
#define SCSW1_A         0x10            /* Address limit checking    */
#define SCSW1_U         0x08            /* Suppress susp interrupt   */
#define SCSW1_Z         0x04            /* Zero condition code       */
#define SCSW1_E         0x02            /* Extended control          */
#define SCSW1_N         0x01            /* Path not operational      */

/* Bit definitions for SCSW flag byte 2 */
#define SCSW2_Q         0x80            /* QDIO active               */
#define SCSW2_FC        0x70            /* Function control bits...  */
#define SCSW2_FC_START  0x40            /* ...start function         */
#define SCSW2_FC_HALT   0x20            /* ...halt function          */
#define SCSW2_FC_CLEAR  0x10            /* ...clear function         */
#define SCSW2_AC        0x0F            /* Activity control bits...  */
#define SCSW2_AC_RESUM  0x08            /* ...resume pending         */
#define SCSW2_AC_START  0x04            /* ...start pending          */
#define SCSW2_AC_HALT   0x02            /* ...halt pending           */
#define SCSW2_AC_CLEAR  0x01            /* ...clear pending          */

/* Bit definitions for SCSW flag byte 3 */
#define SCSW3_AC        0xE0            /* Activity control bits...  */
#define SCSW3_AC_SCHAC  0x80            /* ...subchannel active      */
#define SCSW3_AC_DEVAC  0x40            /* ...device active          */
#define SCSW3_AC_SUSP   0x20            /* ...suspended              */
#define SCSW3_SC        0x1F            /* Status control bits...    */
#define SCSW3_SC_ALERT  0x10            /* ...alert status           */
#define SCSW3_SC_INTER  0x08            /* ...intermediate status    */
#define SCSW3_SC_PRI    0x04            /* ...primary status         */
#define SCSW3_SC_SEC    0x02            /* ...secondary status       */
#define SCSW3_SC_PEND   0x01            /* ...status pending         */

/* CSW unit status flags */
#define CSW_ATTN        0x80            /* Attention                 */
#define CSW_SM          0x40            /* Status modifier           */
#define CSW_CUE         0x20            /* Control unit end          */
#define CSW_BUSY        0x10            /* Busy                      */
#define CSW_CE          0x08            /* Channel end               */
#define CSW_DE          0x04            /* Device end                */
#define CSW_UC          0x02            /* Unit check                */
#define CSW_UX          0x01            /* Unit exception            */

/* CSW channel status flags */
#define CSW_PCI         0x80            /* Program control interrupt */
#define CSW_IL          0x40            /* Incorrect length          */
#define CSW_PROGC       0x20            /* Program check             */
#define CSW_PROTC       0x10            /* Protection check          */
#define CSW_CDC         0x08            /* Channel data check        */
#define CSW_CCC         0x04            /* Channel control check     */
#define CSW_ICC         0x02            /* Interface control check   */
#define CSW_CHC         0x01            /* Chaining check            */

/* CCW flags */
#define CCW_FLAGS_CD    0x80            /* Chain data flag           */
#define CCW_FLAGS_CC    0x40            /* Chain command flag        */
#define CCW_FLAGS_SLI   0x20            /* Suppress incorrect length
                                           indication flag           */
#define CCW_FLAGS_SKIP  0x10            /* Skip flag                 */
#define CCW_FLAGS_PCI   0x08            /* Program controlled
                                           interrupt flag            */
#define CCW_FLAGS_IDA   0x04            /* Indirect data address flag*/
#define CCW_FLAGS_SUSP  0x02            /* Suspend flag              */
#define CCW_FLAGS_MIDAW 0x01            /* Modified IDAW flag     @MW*/

/* MIDAW flags (bits 40-47)                                       @MW*/
#define MIDAW_LAST      0x80            /* Last MIDAW flag        @MW*/
#define MIDAW_SKIP      0x40            /* Skip flag              @MW*/
#define MIDAW_DTI       0x20            /* Data transfer interrupt@MW*/
#define MIDAW_RESV      0x1F            /* Reserved bits          @MW*/

/* Device independent bit settings for sense byte 0 */
#define SENSE_CR        0x80            /* Command reject            */
#define SENSE_IR        0x40            /* Intervention required     */
#define SENSE_BOC       0x20            /* Bus-out check             */
#define SENSE_EC        0x10            /* Equipment check           */
#define SENSE_DC        0x08            /* Data check                */
#define SENSE_OR        0x04            /* Overrun                   */
#define SENSE_US        0x04            /* Unit specify              */
#define SENSE_CC        0x02            /* Control check             */
#define SENSE_OC        0x01            /* Operation check           */

/* Device dependent bit settings for sense byte 1 */
#define SENSE1_PER      0x80            /* Permanent Error           */
#define SENSE1_ITF      0x40            /* Invalid Track Format      */
#define SENSE1_EOC      0x20            /* End of Cylinder           */
#define SENSE1_MTO      0x10            /* Message to Operator       */
#define SENSE1_NRF      0x08            /* No Record Found           */
#define SENSE1_FP       0x04            /* File Protected            */
#define SENSE1_WRI      0x02            /* Write Inhibited           */
#define SENSE1_IE       0x01            /* Imprecise Ending          */

/* Subchannel information block structure definition */
typedef struct _SCHIB {
        PMCW    pmcw;                   /* Path management ctl word  */
        SCSW    scsw;                   /* Subchannel status word    */
        BYTE    moddep[12];             /* Model dependent area      */
    } SCHIB;

/* Interruption response block structure definition */
typedef struct _IRB {
        SCSW    scsw;                   /* Subchannel status word    */
        ESW     esw;                    /* Extended status word      */
        BYTE    ecw[32];                /* Extended control word     */
    } IRB;

/* Measurement Block */
typedef struct _MBK {
        HWORD   srcount;                /* SSCH + RSCH count         */
        HWORD   samplecnt;              /* Sample count              */
        FWORD   dct;                    /* Device connect time       */
        FWORD   fpt;                    /* Function pending time     */
        FWORD   ddt;                    /* Device disconnect time    */
        FWORD   cuqt;                   /* Control unit queueing time*/
        FWORD   resv[3];                /* Reserved                  */
    } MBK;

/* Bit definitions for SCHM instruction */
#define CHM_GPR1_MBK    0xF0000000      /* Measurement Block Key     */
#define CHM_GPR1_M      0x00000002      /* Measurement mode control  */
#define CHM_GPR1_D      0x00000001      /* Block update Mode         */
#define CHM_GPR1_A      0x01000000      /* Alternate mode            */
#define CHM_GPR1_ZONE   0x00FF0000      /* Zone                      */
#define CHM_GPR1_RESV   0x0E00FFFC      /* Reserved, must be zero    */

/* Measurement Block Origin  */
#define S_CHM_GPR2_RESV 0x8000001F      /* Reserved, must be zero    */
#define Z_CHM_GPR2_RESV 0x0000001F      /* Reserved, must be zero    */

/* Macros for classifying CCW operation codes */
#define IS_CCW_WRITE(c)         is_ccw_write(c)
#define IS_CCW_READ(c)          is_ccw_read(c)
#define IS_CCW_CONTROL(c)       is_ccw_control(c)
#define IS_CCW_NOP(c)           is_ccw_nop(c)
#define IS_CCW_SENSE(c)         is_ccw_sense(c)
#define IS_CCW_TIC(c)           is_ccw_tic(c)
#define IS_CCW_RDBACK(c)        is_ccw_rdback(c)

#endif /* _CHANNEL_H */


#if defined(__Post_Process_Includes__) && !defined(_CHANNEL_H_Post_Process_Include)
#define _CHANNEL_H_Post_Process_Include

static INLINE IOINT*    io_interrupt_queued(const IOINT*);
static INLINE void      queue_io_interrupt_qlocked(IOINT*);
static INLINE void      queue_io_interrupt(IOINT*);
static INLINE void      dequeue_io_interrupt_qlocked(IOINT*);
static INLINE void      dequeue_io_interrupt(IOINT*);

static INLINE IOINT*
io_interrupt_queued(const IOINT* io)
{
    IOINT *prev = (IOINT*)&sysblk.iointq;

    if (io->priority == -1)
        return (NULL);

    for (;
         prev->next != NULL && prev->next != io;
         prev = prev->next);

    return ((prev->next == io) ? prev : NULL);
}

static INLINE void
queue_io_interrupt_qlocked(IOINT* io)
{
    DEVBLK* dev = io->dev;
    IOINT*  prev;
    int     priority = (((dev->priority << 8) |
                         (dev->orb.csspriority)) << 8) |
                          dev->orb.cupriority;

    /* If the priority for an interrupt is not -1, the interrrupt is
     * already on the queue.
     */
    if (io->priority != -1)
    {
        /* If same priority, just return as already queued */
        if (io->priority == priority)
            return;

        /* The I/O priority changed during an active I/O. Technically,
         * this should never occur, but does occasionally happen due to
         * other errors. Trapping the error at this point is near
         * useless without preparation and a debugger. Consequently,
         * just dequeue the interrupt, and take the normal path to
         * requeue at the requested priority.
         *
         * If this is not done, it is possible to have two remaining
         * elements on the queue pointing to each other, with all other
         * threads blocked.
         */
        dequeue_io_interrupt_qlocked(io);
    }

    /* Locate position in queue */
    for (prev = (IOINT*)&sysblk.iointq;
         prev->next != NULL     &&
            prev->next != io    &&
            prev->next->priority > priority;
         prev = prev->next);

    /* Add to queue if not already queued (for example, PCI) */
    if (prev->next != io)
    {
        io->priority = priority;
        io->next = prev->next;
        prev->next = io;

        /* Deprecated. Ordering of SCSWs by interrupt is performed by
         * the routine requesting an SCSW. What is important is
         * maintaining the correct number of interrupt instances on the
         * queue for a given device.
         */
             if (io->pending)     dev->pending     = 1;
        else if (io->pcipending)  dev->pcipending  = 1;
        else if (io->attnpending) dev->attnpending = 1;
    }
}

static INLINE void
queue_io_interrupt(IOINT* io)
{
    obtain_lock(&sysblk.iointqlk);
    queue_io_interrupt_qlocked(io);
    release_lock(&sysblk.iointqlk);
}

static INLINE void
_test_scsw_pending(const SCSW* scsw, const char* file, const int line)
{
    if (!(scsw->flag3 & SCSW3_SC_PEND))
    {
        char    debugmsg[133];

        snprintf(debugmsg, sizeof(debugmsg),
                 "Non-status pending SCSW queued from %s line %d",
                 file, line);
        WRMSG(HHC90000, "I", debugmsg);
    }
}

static INLINE void
_test_already_queued(const IOINT* io, const char* file, const int line)
{
    if (io_interrupt_queued(io))
    {
        char    debugmsg[133];

        snprintf(debugmsg, sizeof(debugmsg),
                 "Attempted requeue non-dequeued IOINT element from %s line %d",
                 file, line);
        WRMSG(HHC90000, "I", debugmsg);
    }
}

static INLINE void
dequeue_io_interrupt_qlocked(IOINT* io)
{
    IOINT* prev;

    prev = io_interrupt_queued(io);

    if (prev != NULL)
    {
        /* Dequeue I/O interrupt */
        prev->next = io->next;
        io->next = NULL;
        io->priority = -1;

             if (io->pending)     io->dev->pending     = 0;
        else if (io->pcipending)  io->dev->pcipending  = 0;
        else if (io->attnpending) io->dev->attnpending = 0;
    }
}

static INLINE void
dequeue_io_interrupt(IOINT* io)
{
   obtain_lock(&sysblk.iointqlk);
   dequeue_io_interrupt_qlocked(io);
   release_lock(&sysblk.iointqlk);
}

#if !defined(CHANNEL_INLINES)
#define CHANNEL_INLINES

static INLINE int   scsw_KEY(const SCSW*);
static INLINE int   scsw_S(const SCSW*);
static INLINE int   scsw_L(const SCSW*);
static INLINE int   scsw_CC(const SCSW*);

static INLINE int   scsw_F(const SCSW*);
static INLINE int   scsw_P(const SCSW*);
static INLINE int   scsw_I(const SCSW*);
static INLINE int   scsw_A(const SCSW*);
static INLINE int   scsw_U(const SCSW*);

static INLINE int   scsw_Z(const SCSW*);
static INLINE int   scsw_E(const SCSW*);
static INLINE int   scsw_N(const SCSW*);
static INLINE int   scsw_Q(const SCSW*);

static INLINE int   scsw_start_function(const SCSW*);
static INLINE int   scsw_halt_function(const SCSW*);
static INLINE int   scsw_clear_function(const SCSW*);
static INLINE int   scsw_halt_or_clear_function(const SCSW*);

static INLINE int   scsw_resume_pending(const SCSW*);
static INLINE int   scsw_start_pending(const SCSW*);
static INLINE int   scsw_halt_pending(const SCSW*);
static INLINE int   scsw_clear_pending(const SCSW*);
static INLINE int   scsw_halt_or_clear_pending(const SCSW*);

static INLINE int   scsw_subchannel_active(const SCSW*);
static INLINE int   scsw_device_active(const SCSW*);
static INLINE int   scsw_suspended(const SCSW*);

static INLINE int   scsw_alert(const SCSW*);
static INLINE int   scsw_alert_pending(const SCSW*);

static INLINE int   scsw_intermediate_status(const SCSW*);
static INLINE int   scsw_intermediate_pending(const SCSW*);

static INLINE int   scsw_primary_status(const SCSW*);
static INLINE int   scsw_primary_pending(const SCSW*);

static INLINE int   scsw_secondary(const SCSW*);
static INLINE int   scsw_secondary_pending(const SCSW*);

static INLINE int   scsw_status_pending(const SCSW*);


#define scsw_flag(_flag,_test) \
        (scsw->##_flag & (_test))

#define scsw_test_flag(_flag,_test) \
        (scsw_flag(_flag,_test) == (_test))

#define scsw_flag0(_flags) \
        scsw_flag(flag0,(_flags))

#define scsw_test_flag0(_flags) \
        scsw_test_flag(flag0,(_flags))

#define scsw_flag1(_flags) \
        scsw_flag(flag1,(_flags))

#define scsw_test_flag1(_flags) \
        scsw_test_flag(flag1,(_flags))

#define scsw_flag2(_flags) \
        scsw_flag(flag2,(_flags))

#define scsw_test_flag2(_flags) \
        scsw_test_flag(flag2,(_flags))

#define scsw_flag3(_flags) \
        scsw_flag(flag3,(_flags))

#define scsw_test_flag3(_flags) \
        scsw_test_flag(flag3,(_flags))

static INLINE int
scsw_KEY(const SCSW* scsw)
{
    return (scsw_flag0(SCSW0_KEY));
}

static INLINE int
scsw_S(const SCSW* scsw)
{
    return (scsw_flag0(SCSW0_S));
}

static INLINE int
scsw_L(const SCSW* scsw)
{
    return (scsw_flag0(SCSW0_L));
}

static INLINE int
scsw_CC(const SCSW* scsw)
{
    return (scsw_flag0(SCSW0_CC));
}

static INLINE int
scsw_F(const SCSW* scsw)
{
    return (scsw->flag1 & SCSW1_F);
}

static INLINE int
scsw_P(const SCSW* scsw)
{
    return (scsw_flag1(SCSW1_P));
}

static INLINE int
scsw_I(const SCSW* scsw)
{
    return (scsw_flag1(SCSW1_I));
}

static INLINE int
scsw_A(const SCSW* scsw)
{
    return (scsw_flag1(SCSW1_A));
}

static INLINE int
scsw_U(const SCSW* scsw)
{
    return (scsw_flag1(SCSW1_U));
}

static INLINE int
scsw_Z(const SCSW* scsw)
{
    return (scsw_flag1(SCSW1_Z));
}

static INLINE int
scsw_E(const SCSW* scsw)
{
    return (scsw_flag1(SCSW1_E));
}

static INLINE int
scsw_N(const SCSW* scsw)
{
    return (scsw_flag1(SCSW1_N));
}

static INLINE int
scsw_Q(const SCSW* scsw)
{
    return (scsw_flag2(SCSW2_Q));
}

static INLINE int
scsw_start_function(const SCSW* scsw)
{
    return (scsw_flag2(SCSW2_FC_START));
}

static INLINE int
scsw_status_pending(const SCSW* scsw)
{
    return (scsw_flag3(SCSW3_SC_PEND));
}

static INLINE int
scsw_resume_pending(const SCSW* scsw)
{
    return (scsw_flag2(SCSW2_AC_RESUM));
}

static INLINE int
scsw_start_pending(const SCSW* scsw)
{
    return (scsw_flag2(SCSW2_AC_START));
}

static INLINE int
scsw_halt_function(const SCSW* scsw)
{
    return (scsw_flag2(SCSW2_FC_HALT));
}

static INLINE int
scsw_clear_function(const SCSW* scsw)
{
    return (scsw_flag2(SCSW2_FC_CLEAR));
}

static INLINE int
scsw_halt_pending(const SCSW* scsw)
{
    return (scsw_flag2(SCSW2_AC_HALT));
}

static INLINE int
scsw_halt_or_clear_function(const SCSW* scsw)
{
    return (scsw_flag2(SCSW2_FC_HALT |
                       SCSW2_FC_CLEAR));
}

static INLINE int
scsw_halt_or_clear_pending(const SCSW* scsw)
{
    return (scsw_flag2(SCSW2_AC_HALT |
                       SCSW2_AC_CLEAR));
}

static INLINE int
scsw_clear_pending(const SCSW* scsw)
{
    return (scsw_flag2(SCSW2_AC_CLEAR));
}

static INLINE int
scsw_alert_status(const SCSW* scsw)
{
    return (scsw_flag3(SCSW3_SC_ALERT));
}

static INLINE int
scsw_alert_pending(const SCSW* scsw)
{
    return (scsw_test_flag3(SCSW3_SC_ALERT |
                            SCSW3_SC_PEND));
}

static INLINE int
scsw_intermediate_status(const SCSW* scsw)
{
    return (scsw_flag3(SCSW3_SC_INTER));
}

static INLINE int
scsw_intermediate_pending(const SCSW* scsw)
{
    return (scsw_test_flag3(SCSW3_SC_INTER  |
                            SCSW3_SC_PEND));
}

static INLINE int
scsw_primary_status(const SCSW* scsw)
{
    return (scsw_flag3(SCSW3_SC_PRI));
}

static INLINE int
scsw_primary_pending(const SCSW* scsw)
{
    return (scsw_test_flag3(SCSW3_SC_PRI    |
                            SCSW3_SC_PEND));
}

static INLINE int
scsw_secondary_status(const SCSW* scsw)
{
    return (scsw_flag3(SCSW3_SC_SEC));
}

static INLINE int
scsw_secondary_pending(const SCSW* scsw)
{
    return (scsw_test_flag3(SCSW3_SC_SEC    |
                            SCSW3_SC_PEND));
}

static INLINE int
scsw_primary_and_secondary_pending(const SCSW* scsw)
{
    return (scsw_flag3(SCSW3_SC_PRI     |
                       SCSW3_SC_SEC     |
                       SCSW3_SC_PEND));
}

static INLINE int
scsw_primary_or_secondary_pending(const SCSW* scsw)
{
    return (scsw_status_pending(scsw) &&
            scsw_flag3(SCSW3_SC_PRI   |
                       SCSW3_SC_SEC));
}

static INLINE int
scsw_subchannel_active(const SCSW* scsw)
{
    return (scsw_flag3(SCSW3_AC_SCHAC));
}

static INLINE int
scsw_device_active(const SCSW* scsw)
{
    return (scsw_flag3(SCSW3_AC_DEVAC));
}

static INLINE int
scsw_suspended(const SCSW* scsw)
{
    return (scsw_flag3(SCSW3_AC_SUSP));
}


/*-------------------------------------------------------------------*/
/*  scsw_select_type (const DEVBLK* dev)                             */
/*-------------------------------------------------------------------*/

static INLINE scsw_type
scsw_select_type(const DEVBLK* dev)
{
    scsw_type   result;

    /* Scenario 1:
     * PCI interrupt without a pending halt or clear
     */
    if (unlikely(scsw_status_pending(&dev->pciscsw) &&
                 likely(!scsw_halt_or_clear_function(&dev->pciscsw))))
        result = scsw_pci;

    /* Scenario 2:
     * Normal interrupt or TSCH without an interrupt
     */
    else if ( scsw_status_pending(&dev->scsw)       ||
             !scsw_status_pending(&dev->attnscsw)   ||
              scsw_clear_function(&dev->scsw))
        result = scsw_normal;

    /* Scenario 3:
     * Attention interrupt
     */
    else
        result = scsw_attn;

    return (result);
}


/*-------------------------------------------------------------------*/
/*  scsw_select (const DEVBLK* dev)                                  */
/*-------------------------------------------------------------------*/

static INLINE SCSW*
scsw_select(const DEVBLK* dev)
{
    SCSW*   result;

    switch (scsw_select_type(dev))
    {
        case scsw_pci:
            result = (SCSW*)&dev->pciscsw;
            break;

        default:
        case scsw_normal:
            result = (SCSW*)&dev->scsw;
            break;

        case scsw_attn:
            result = (SCSW*)&dev->attnscsw;
            break;
    }

    return (result);
}


/*--------------------------------------------------------------------*/
/*  AIPSX (SCSW*)                                                     */
/*                                                                    */
/*  Generates the AIPSX indication for Figure 16-5, the Deferred-     */
/*  Condition-Code Meaning for Status-Pending Subchannel, Figure      */
/*  16-5.                                                             */
/*--------------------------------------------------------------------*/
static INLINE U8
AIPSX (const SCSW* scsw)
{
    U8  result   = scsw_flag1(SCSW1_P);             /* >> 6 << 2  */
        result >>= 2;
        result  |= scsw_flag1(SCSW1_I);             /* >> 5 << 3  */
        result  |= scsw_flag0(SCSW0_S);             /* >> 3 << 1  */
        result >>= 2;
        result  |= scsw_flag1(SCSW1_A);             /* >> 4 << 4  */
        result  |= scsw_flag3(SCSW3_SC_PEND);       /* >> 0 << 0  */

    return (result);
}


static INLINE int   subchannel_busy(const DEVBLK*);
static INLINE int   subchannel_status_pending(const DEVBLK*);
static INLINE int   subchannel_suspended(const DEVBLK*);
static INLINE SCSW* subchannel_scsw(const DEVBLK*);

static INLINE int
subchannel_status_pending (const DEVBLK* dev)
{
    return (scsw_status_pending(&dev->scsw)     ||
            scsw_status_pending(&dev->pciscsw)  ||
            scsw_status_pending(&dev->attnscsw) ||
            dev->tschpending);
}

static INLINE int
subchannel_suspended(const DEVBLK* dev)
{
    return (scsw_suspended(&dev->scsw));
}

static INLINE int
subchannel_busy (const DEVBLK* dev)
{
    SCSW*   scsw = (SCSW*)&dev->scsw;

    return (scsw_status_pending(scsw)           ||
            scsw_status_pending(&dev->pciscsw)  ||
            scsw_status_pending(&dev->attnscsw) ||
            scsw_flag3(SCSW3_AC_SCHAC |
                       SCSW3_AC_DEVAC)          ||
            (!scsw_suspended(scsw) &&
             (scsw_flag2(SCSW2_FC     |
                         SCSW2_AC)      ||
              scsw_flag3(SCSW3_AC &
                        ~SCSW3_AC_SUSP)))       ||
            dev->startpending                   ||
            (dev->busy &&
             (dev->ioactive == DEV_SYS_LOCAL)));
}

static INLINE SCSW*
subchannel_scsw(const DEVBLK* dev)
{
    SCSW*   scsw;

    /* Select proper SCSW */
    if (scsw_status_pending(&dev->pciscsw) &&
        !scsw_clear_function(&dev->scsw))
        scsw = (SCSW*)&dev->pciscsw;

    else if (scsw_status_pending(&dev->scsw) ||
             scsw_clear_function(&dev->scsw) ||
             !scsw_status_pending(&dev->attnscsw))
        scsw = (SCSW*)&dev->scsw;

    else
        scsw = (SCSW*)&dev->attnscsw;

    return (scsw);
}

static INLINE U16
subchannel_status(DEVBLK* dev)
{
    SCSW*   scsw = subchannel_scsw(dev);

    return (fetch_hw(&scsw->flag2));
}


#if defined(_CHANNEL_C_)

static INLINE void  scsw_set_KEY(SCSW*, const BYTE Key);

static INLINE void  scsw_set_S(SCSW*);
static INLINE void  scsw_clear_S(SCSW*);

static INLINE void  scsw_set_L(SCSW*);
static INLINE void  scsw_clear_L(SCSW*);

static INLINE void  scsw_set_F(SCSW*);
static INLINE void  scsw_clear_F(SCSW*);

static INLINE void  scsw_set_CC(SCSW*, BYTE CC);
static INLINE void  scsw_clear_CC(SCSW*);

static INLINE void  scsw_set_P(SCSW*);
static INLINE void  scsw_clear_P(SCSW*);

static INLINE void  scsw_set_I(SCSW*);
static INLINE void  scsw_clear_I(SCSW*);

static INLINE void  scsw_set_A(SCSW*);
static INLINE void  scsw_clear_A(SCSW*);

static INLINE void  scsw_set_U(SCSW*);
static INLINE void  scsw_clear_U(SCSW*);

static INLINE void  scsw_set_Z(SCSW*);
static INLINE void  scsw_clear_Z(SCSW*);

static INLINE void  scsw_set_E(SCSW*);
static INLINE void  scsw_clear_E(SCSW*);

static INLINE void  scsw_set_N(SCSW*);
static INLINE void  scsw_clear_N(SCSW*);

static INLINE void  scsw_set_start_function(SCSW*);
static INLINE void  scsw_clear_start_function(SCSW*);

static INLINE void  scsw_set_halt_function(SCSW*);
static INLINE void  scsw_clear_halt_function(SCSW*);

static INLINE void  scsw_set_clear_function(SCSW*);
static INLINE void  scsw_clear_clear_function(SCSW*);

static INLINE void  scsw_set_resume_pending(SCSW*);
static INLINE void  scsw_clear_resume_pending(SCSW*);

static INLINE void  scsw_set_start_pending(SCSW*);
static INLINE void  scsw_clear_start_pending(SCSW*);

static INLINE void  scsw_set_halt_pending(SCSW*);
static INLINE void  scsw_clear_halt_pending(SCSW*);

static INLINE void  scsw_set_clear_pending(SCSW*);
static INLINE void  scsw_clear_clear_pending(SCSW*);

static INLINE void  scsw_set_subchannel_active(SCSW*);
static INLINE void  scsw_clear_subchannel_active(SCSW*);

static INLINE void  scsw_set_device_active(SCSW*);
static INLINE void  scsw_clear_device_active(SCSW*);

static INLINE void  scsw_set_suspended(SCSW*);
static INLINE void  scsw_clear_suspended(SCSW*);

static INLINE void  scsw_set_alert_status(SCSW*);
static INLINE void  scsw_clear_alert_status(SCSW*);

static INLINE void  scsw_set_alert_pending(SCSW*);
static INLINE void  scsw_clear_alert_pending(SCSW*);

static INLINE void  scsw_set_intermediate_status(SCSW*);
static INLINE void  scsw_clear_intermediate_status(SCSW*);

static INLINE void  scsw_set_intermediate_pending(SCSW*);
static INLINE void  scsw_clear_intermediate_pending(SCSW*);

static INLINE void  scsw_set_primary_status(SCSW*);
static INLINE void  scsw_clear_primary_status(SCSW*);

static INLINE void  scsw_set_primary_pending(SCSW*);
static INLINE void  scsw_clear_primary_pending(SCSW*);

static INLINE void  scsw_set_secondary(SCSW*);
static INLINE void  scsw_clear_secondary(SCSW*);

static INLINE void  scsw_set_secondary_pending(SCSW*);
static INLINE void  scsw_clear_secondary_pending(SCSW*);

static INLINE void  scsw_set_status_pending(SCSW*);
static INLINE void  scsw_clear_status_pending(SCSW*);

static INLINE void  subchannel_set_active(DEVBLK*);
static INLINE void  subchannel_clear_active(DEVBLK*);
static INLINE void  subchannel_clear_status(DEVBLK*);
static INLINE void  subchannel_clear_suspended(DEVBLK*);
static INLINE void  subchannel_set_device_active(DEVBLK*);


#define scsw_set_flag(_flag,_flags) \
        scsw->##_flag |= (_flags)

#define scsw_clear_flag(_flag,_flags) \
        scsw->##_flag &= ~(_flags)

#define scsw_set_flag0(_flags) \
        scsw_set_flag(flag0,(_flags))

#define scsw_clear_flag0(_flags) \
        scsw_clear_flag(flag0,(_flags))

#define scsw_set_flag1(_flags) \
        scsw_set_flag(flag1,(_flags))

#define scsw_clear_flag1(_flags) \
        scsw_clear_flag(flag1,(_flags))

#define scsw_set_flag2(_flags) \
        scsw_set_flag(flag2,(_flags))

#define scsw_clear_flag2(_flags) \
        scsw_clear_flag(flag2,(_flags))

#define scsw_set_flag3(_flags) \
       _scsw_set_flag3(scsw,(_flags))

#define scsw_clear_flag3(_flags) \
       _scsw_clear_flag3(scsw,(_flags))

#define scsw_clear_and_set_flag3(_clear,_set) \
       _scsw_clear_and_set_flag3(scsw,(_clear),(_set))

static INLINE void
scsw_update_pending(SCSW* scsw)
{
    if (scsw_flag3(SCSW3_SC_ALERT |
                   SCSW3_SC_INTER |
                   SCSW3_SC_PRI   |
                   SCSW3_SC_SEC)        ||
        (scsw_flag2(SCSW2_FC_CLEAR) &&
         !scsw_flag2(SCSW2_AC_CLEAR)))
        scsw->flag3 |= SCSW3_SC_PEND;
    else
        scsw->flag3 &= ~SCSW3_SC_PEND;
}

static INLINE void
_scsw_set_flag3(SCSW* scsw, const BYTE flags)
{
    scsw->flag3 |= flags;
    scsw_update_pending(scsw);
}

static INLINE void
_scsw_clear_flag3(SCSW* scsw, const BYTE flags)
{
    scsw->flag3 &= ~flags;
    scsw_update_pending(scsw);
}

static INLINE void
_scsw_clear_and_set_flag3(SCSW* scsw, const BYTE clear, const BYTE set)
{
    scsw->flag3 &= ~clear;
    scsw->flag3 |= set;
    scsw_update_pending(scsw);
}

#define scsw_set_fc(_flag) \
       _scsw_set_fc(scsw,(_flag))

static INLINE void
_scsw_set_fc(SCSW* scsw, const BYTE fc)
{
    scsw->flag2 = (scsw->flag2 & ~SCSW2_FC) |
                  fc;
}

static INLINE void
scsw_set_KEY(SCSW* scsw, const BYTE Key)
{
    scsw_clear_flag0(SCSW0_KEY),
    scsw_set_flag0(Key & SCSW0_KEY);
}

static INLINE void
scsw_set_S(SCSW* scsw)
{
    scsw_set_flag0(SCSW0_S);
}

static INLINE void
scsw_clear_S(SCSW* scsw)
{
    scsw_clear_flag0(SCSW0_S);
}

static INLINE void
scsw_set_L(SCSW* scsw)
{
    scsw_set_flag0(SCSW0_L);
}

static INLINE void
scsw_clear_L(SCSW* scsw)
{
    scsw_clear_flag0(SCSW0_L);
}

static INLINE void
scsw_set_CC(SCSW* scsw, BYTE CC)
{
    CC &= SCSW0_CC;
    scsw_clear_flag0(SCSW0_CC);
    scsw_set_flag0(CC);
    if (!CC)
        scsw_set_Z(scsw);
    else
        scsw_clear_Z(scsw);
    scsw_set_intermediate_pending(scsw);
}

static INLINE void
scsw_clear_CC(SCSW* scsw)
{
    scsw_clear_flag0(SCSW0_CC);
    scsw_clear_Z(scsw);
    scsw_clear_intermediate_pending(scsw);
}

static INLINE void
scsw_set_F(SCSW* scsw)
{
    scsw_set_flag1(SCSW1_F);
}

static INLINE void
scsw_clear_F(SCSW* scsw)
{
    scsw_clear_flag1(SCSW1_F);
}

static INLINE void
scsw_set_P(SCSW* scsw)
{
    scsw_set_flag1(SCSW1_P);
}

static INLINE void
scsw_clear_P(SCSW* scsw)
{
    scsw_clear_flag1(SCSW1_P);
}

static INLINE void
scsw_set_I(SCSW* scsw)
{
    scsw_set_flag1(SCSW1_I);
}

static INLINE void
scsw_clear_I(SCSW* scsw)
{
    scsw_clear_flag1(SCSW1_I);
}

static INLINE void
scsw_set_A(SCSW* scsw)
{
    scsw_set_flag1(SCSW1_A);
}

static INLINE void
scsw_clear_A(SCSW* scsw)
{
    scsw_clear_flag1(SCSW1_A);
}

static INLINE void
scsw_set_U(SCSW* scsw)
{
    scsw_set_flag1(SCSW1_U);
}

static INLINE void
scsw_clear_U(SCSW* scsw)
{
    scsw_clear_flag1(SCSW1_U);
}

static INLINE void
scsw_set_Z(SCSW* scsw)
{
    scsw_set_flag1(SCSW1_Z);

    /* Set intermediate status in the SCSW */
    scsw_set_intermediate_pending(scsw);
}

static INLINE void
scsw_clear_Z(SCSW* scsw)
{
    scsw_clear_flag1(SCSW1_Z);
}

static INLINE void
scsw_set_E(SCSW* scsw)
{
    scsw_set_flag1(SCSW1_E);
}

static INLINE void
scsw_clear_E(SCSW* scsw)
{
    scsw_clear_flag1(SCSW1_E);
}

static INLINE void
scsw_set_N(SCSW* scsw)
{
    scsw_set_flag1(SCSW1_N);
}

static INLINE void
scsw_clear_N(SCSW* scsw)
{
    scsw_clear_flag1(SCSW1_N);
}

static INLINE void
scsw_set_Q(SCSW* scsw)
{
    scsw_set_flag2(SCSW2_Q);
}

static INLINE void
scsw_clear_Q(SCSW* scsw)
{
    scsw_clear_flag2(SCSW2_Q);
}

static INLINE void
scsw_set_start_function(SCSW* scsw)
{
    scsw_set_fc(SCSW2_FC_START),
    scsw_clear_flag2(SCSW2_AC_RESUM |
                     SCSW2_AC_START),
    scsw_clear_flag3(SCSW3_AC_SUSP  |
                     SCSW3_SC_ALERT |
                     SCSW3_SC_INTER |
                     SCSW3_SC_PEND);
}

static INLINE void
scsw_clear_start_function(SCSW* scsw)
{
    scsw_clear_flag2(SCSW2_FC_START |
                     SCSW2_AC_START);
}

static INLINE void
scsw_set_status_pending(SCSW* scsw)
{
    scsw_set_flag3(SCSW3_SC_PEND);
}

static INLINE void
scsw_clear_status_pending(SCSW* scsw)
{
    scsw_clear_flag3(SCSW3_SC_PEND);
}

static INLINE void
scsw_set_resume_pending(SCSW* scsw)
{
    scsw_set_flag2(SCSW2_AC_RESUM);
    scsw_clear_flag2(SCSW2_AC_START);
}

static INLINE void
scsw_clear_resume_pending(SCSW* scsw)
{
    scsw_clear_flag2(SCSW2_AC_RESUM);
}

static INLINE void
scsw_set_start_pending(SCSW* scsw)
{
    scsw_clear_resume_pending(scsw);
    scsw_set_flag2(SCSW2_FC_START | SCSW2_AC_START);
}

static INLINE void
scsw_clear_start_pending(SCSW* scsw)
{
    scsw_clear_flag2(SCSW2_AC_START);
}

static INLINE void
scsw_set_halt_function(SCSW* scsw)
{
    scsw_set_fc(SCSW2_FC_HALT),
    scsw_clear_flag2(SCSW2_AC_RESUM |
                     SCSW2_AC_START);
    if (scsw_flag3(SCSW3_AC_SUSP))
    {
        scsw_clear_flag3(SCSW3_AC_SUSP),
        scsw_set_flag3(SCSW3_SC_ALERT);
    }
}

static INLINE void
scsw_clear_halt_function(SCSW* scsw)
{
    scsw_clear_flag2(SCSW2_FC_HALT |
                     SCSW2_AC_HALT);
}

static INLINE void
scsw_set_clear_function(SCSW* scsw)
{
    scsw_set_fc(SCSW2_FC_CLEAR);
}

static INLINE void
scsw_clear_clear_function(SCSW* scsw)
{
    scsw_clear_flag2(SCSW2_FC_CLEAR |
                     SCSW2_AC_CLEAR);
}

static INLINE void
scsw_set_halt_pending(SCSW* scsw)
{
    scsw_set_flag2(SCSW2_AC_HALT);
}

static INLINE void
scsw_clear_halt_pending(SCSW* scsw)
{
    scsw_clear_flag2(SCSW2_AC_HALT);
}

static INLINE void
scsw_set_clear_pending(SCSW* scsw)
{
    scsw_set_flag2(SCSW2_AC_CLEAR);
}

static INLINE void
scsw_clear_clear_pending(SCSW* scsw)
{
    scsw_clear_flag2(SCSW2_AC_CLEAR);
}

static INLINE void
scsw_set_alert_status(SCSW* scsw)
{
    scsw_set_flag3(SCSW3_SC_ALERT);
}

static INLINE void
scsw_clear_alert_status(SCSW* scsw)
{
    scsw_clear_flag3(SCSW3_SC_ALERT);
}

static INLINE void
scsw_set_alert_pending(SCSW* scsw)
{
    scsw_set_flag3(SCSW3_SC_ALERT | SCSW3_SC_PEND);
}

static INLINE void
scsw_clear_alert_pending(SCSW* scsw)
{
    scsw_clear_flag3(SCSW3_SC_ALERT);
}

static INLINE void
scsw_reset(SCSW* scsw)
{
    memset(scsw, 0, sizeof(SCSW));
    scsw_set_alert_pending(scsw);
}

static INLINE void
scsw_set_intermediate_status(SCSW* scsw)
{
    scsw_set_flag3(SCSW3_SC_INTER);
}

static INLINE void
scsw_clear_intermediate_status(SCSW* scsw)
{
    scsw_clear_flag3(SCSW3_SC_INTER);
}

static INLINE void
scsw_set_intermediate_pending(SCSW* scsw)
{
    scsw_set_intermediate_status(scsw);
}

static INLINE void
scsw_clear_intermediate_pending(SCSW* scsw)
{
    scsw_clear_intermediate_status(scsw);
}

static INLINE void
scsw_set_primary_status(SCSW* scsw)
{
    scsw_set_flag3(SCSW3_SC_PRI);
}

static INLINE void
scsw_clear_primary_status(SCSW* scsw)
{
    scsw_clear_flag3(SCSW3_SC_PRI);
}

static INLINE void
scsw_set_primary_pending(SCSW* scsw)
{
    scsw_set_primary_status(scsw);
}

static INLINE void
scsw_clear_primary_pending(SCSW* scsw)
{
    scsw_clear_primary_status(scsw);
}

static INLINE void
scsw_set_secondary_status(SCSW* scsw)
{
    scsw_set_flag3(SCSW3_SC_SEC);
}

static INLINE void
scsw_clear_secondary_status(SCSW* scsw)
{
    scsw_clear_flag3(SCSW3_SC_SEC);
}

static INLINE void
scsw_set_secondary_pending(SCSW* scsw)
{
    scsw_set_secondary_status(scsw);
}

static INLINE void
scsw_clear_secondary_pending(SCSW* scsw)
{
    scsw_clear_secondary_status(scsw);
}

static INLINE void
scsw_set_primary_and_secondary_pending(SCSW* scsw)
{
    scsw_set_flag3(SCSW3_SC_PRI   |
                   SCSW3_SC_SEC);
}

static INLINE void
scsw_clear_primary_and_secondary_pending(SCSW* scsw)
{
    scsw_clear_flag3(SCSW3_SC_PRI |
                     SCSW3_SC_SEC);
}

static INLINE void
scsw_set_subchannel_active(SCSW* scsw)
{
    scsw_set_flag3(SCSW3_AC_SCHAC);
}

static INLINE void
scsw_clear_subchannel_active(SCSW* scsw)
{
    scsw_clear_flag3(SCSW3_AC_SCHAC |
                     SCSW3_AC_DEVAC |
                     SCSW3_SC_INTER);
}

static INLINE void
scsw_set_device_active(SCSW* scsw)
{
    scsw_set_flag3(SCSW3_AC_SCHAC   |
                   SCSW3_AC_DEVAC),
    scsw_clear_flag2(SCSW2_AC_RESUM |
                     SCSW2_AC_START);
}

static INLINE void
scsw_clear_device_active(SCSW* scsw)
{
    scsw_clear_flag3(SCSW3_AC_DEVAC);
}

static INLINE void
scsw_set_suspended(SCSW* scsw)
{
    int device_active = scsw_device_active(scsw);

    scsw_clear_flag2(SCSW2_AC_START),
    scsw_clear_and_set_flag3(SCSW3_AC_SCHAC |
                             SCSW3_AC_DEVAC,
                             scsw_U ?
                             SCSW3_AC_SUSP :
                             (device_active ?
                              (SCSW3_AC_SUSP  |
                               SCSW3_SC_INTER):
                              (SCSW3_AC_SUSP  |
                               SCSW3_SC_ALERT |
                               SCSW3_SC_INTER)));
    scsw->unitstat = 0;
}

static INLINE void
scsw_clear_suspended(SCSW* scsw)
{
    scsw_clear_flag3(SCSW3_AC_SUSP);
}


/*--------------------------------------------------------------------*/
/*  Inline routines for Conditions and Indications Cleared at the     */
/*  Subchannel by TEST SUBCHANNEL; use of the routines keep the       */
/*  logic flow through the table of conditions clean.                 */
/*                                                                    */
/*  SA22-7832-09, Figure 14-2, Conditions and Indications Cleared at  */
/*                the Subchannel by TEST SUBCHANNEL, p. 14-21.        */
/*                                                                    */
/*--------------------------------------------------------------------*/

static INLINE void
scsw_clear_n_C (SCSW* scsw)
{
    scsw->flag1 &= ~SCSW1_N;
}

static INLINE void
scsw_clear_q_C (SCSW* scsw)
{
    scsw->flag2 &= ~SCSW2_Q;
}

static INLINE void
scsw_clear_fc_C (SCSW* scsw)
{
    scsw->flag2 &= ~SCSW2_FC;
}

static INLINE void
scsw_clear_fc_Nc (SCSW* scsw)
{
    if (scsw->flag2 & SCSW2_FC_HALT &&
        scsw->flag3 & SCSW3_AC_SUSP)
        scsw_clear_fc_C(scsw);
}

static INLINE void
scsw_clear_ac_Cp (SCSW* scsw)
{
    scsw->flag2 &= ~(SCSW2_AC_RESUM |
                         SCSW2_AC_START |
                         SCSW2_AC_HALT  |
                         SCSW2_AC_CLEAR);
    scsw->flag3 &= ~SCSW3_AC_SUSP;
}

static INLINE void
scsw_clear_ac_Nr (SCSW* scsw)
{
    if (scsw->flag2 & SCSW2_FC_START &&
        scsw->flag3 & SCSW3_AC_SUSP)
    {
        if (scsw->flag2 & SCSW2_FC_HALT)
            scsw_clear_ac_Cp(scsw);
        else
        {
            scsw->flag2 &= ~SCSW2_AC_RESUM;
            scsw_clear_n_C(scsw);
        }
    }
}

static INLINE void
scsw_clear_sc_Cs (SCSW* scsw)
{
    scsw->flag3 &= ~(SCSW3_SC_ALERT |
                     SCSW3_SC_INTER |
                     SCSW3_SC_PRI   |
                     SCSW3_SC_SEC   |
                     SCSW3_SC_PEND);
    SCSW3_SC_PEND;
}


/*-------------------------------------------------------------------*/
/*  Subchannel Management                                            */
/*-------------------------------------------------------------------*/

static INLINE void
subchannel_set_active(DEVBLK* dev)
{
    scsw_set_subchannel_active(&dev->scsw);
    dev->busy = 1;
}

static INLINE void
subchannel_clear_active(DEVBLK* dev)
{
    scsw_clear_subchannel_active(&dev->scsw);
    dev->startpending = 0;
    dev->busy = 0;
}

static INLINE void
subchannel_set_device_active(DEVBLK* dev)
{
    scsw_set_device_active(&dev->scsw),
    dev->busy = 1;
}

static INLINE void
subchannel_clear_device_active(DEVBLK* dev)
{
    scsw_clear_device_active(&dev->scsw);
//  dev->busy = subchannel_status_pending(dev) ? 1 : 0;
}

static INLINE void
scsw_clear_status (SCSW* scsw)
{
    scsw_clear_Z(scsw);
    scsw->flag2 = 0;
    scsw->flag3 = 0;
    scsw->word[1] = 0;
    scsw->word[2] = 0;
}

static INLINE void
subchannel_clear_status (DEVBLK* dev)
{
    dequeue_io_interrupt_qlocked(&dev->ioint);
    dequeue_io_interrupt_qlocked(&dev->pciioint);
    dequeue_io_interrupt_qlocked(&dev->attnioint);

    scsw_clear_status(&dev->scsw);
    scsw_clear_status(&dev->pciscsw);
    scsw_clear_status(&dev->attnscsw);

    /* Ensure clean status flag bits */
    dev->suspended          = 0;
    dev->pending            = 0;
    dev->pcipending         = 0;
    dev->attnpending        = 0;
    dev->startpending       = 0;
    dev->resumesuspended    = 0;
    dev->tschpending        = 0;
}

static INLINE void
subchannel_set_suspended(DEVBLK* dev)
{
    SCSW*   scsw = &dev->scsw;

    /* Clean up device and complete suspension exit */
    subchannel_clear_active(dev);

    /* Set the subchannel status word to suspended       */
    /* SA22-7201-05:                                     */
    /*  p. 16-15, Subchannel-Active (Bit 24)             */
    /*  pp. 16-15 -- 16-16, Device-Active (Bit 25)       */
    /*  p. 16-16, Suspended (Bit 26)                     */
    /*  p. 16-16, Alert Status (Bit 27)                  */
    /*  p. 16-17, Intermediate Status (Bit 28)           */
    /*  p. 16-18, Status-Pending (Bit 31)                */

    scsw_set_suspended(scsw);

    if (dev->scsw.chanstat & CSW_PCI)
    {
        scsw_set_intermediate_pending(scsw);
        scsw_clear_intermediate_pending(&dev->pciscsw);
    }
    else
    {
        dev->scsw.chanstat   = 0;
        if (!scsw_U(scsw))
            scsw_set_intermediate_pending(scsw);
    }

    dev->suspended = 1;
}

static INLINE void
subchannel_clear_suspended(DEVBLK* dev)
{
    scsw_clear_suspended(&dev->scsw),
    dev->suspended = 0;
}


/*-------------------------------------------------------------------*/
/*  Device Management                                                */
/*-------------------------------------------------------------------*/

static INLINE void  device_set_active(DEVBLK*);
static INLINE void  device_clear_active(DEVBLK*);


static INLINE void
device_set_active(DEVBLK* dev)
{
    subchannel_set_device_active(dev);
}

static INLINE void
device_clear_active(DEVBLK* dev)
{
    scsw_clear_device_active(&dev->scsw);
}

#endif /*defined(_CHANNEL_C_)*/


/*-------------------------------------------------------------------*/
/*  CCW Management                                                   */
/*-------------------------------------------------------------------*/

static INLINE int
is_ccw_write(const BYTE opcode)
{
    return ((opcode & 0x03) == 0x01);
}

static INLINE int
is_ccw_read(const BYTE opcode)
{
    return ((opcode & 0x03) == 0x02);
}

static INLINE int
is_ccw_control(const BYTE opcode)
{
    return ((opcode & 0x03) == 0x03);
}

static INLINE int
is_ccw_nop(const BYTE opcode)
{
    return (opcode == 0x03);
}

static INLINE int
is_ccw_sense(const BYTE opcode)
{
    return ((opcode & 0x0F) == 0x04);
}

static INLINE int
is_ccw_tic(const BYTE opcode)
{
    return ((opcode & 0x0F) == 0x08);
}

static INLINE int
is_ccw_rdback(const BYTE opcode)
{
    return ((opcode & 0x0F) == 0x0C);
}


#endif /*CHANNEL_INLINES*/
#endif /*_CHANNEL_H_Post_Process_Include*/
