#ifndef __DATA_TYPE_DEF_H
#define __DATA_TYPE_DEF_H

#if (((__TID__ >> 8) & 0x7F) == 0x2b)     /* 0x2b = 43 dec */
#define HAVE_LONG_LONG              (1u)
#define IS_LITTLE_ENDIAN            (1u)
#else
#define HAVE_LONG_LONG              (0u)
#define IS_LITTLE_ENDIAN            (1u)
#endif

/* DATA TYPES (Compiler Specific) */
typedef char                char_t;   /* char type */
typedef unsigned char           bool_t;   /* Boolean type */
typedef unsigned char           uint8_t;  /* Unsigned  8 bit quantity  */
typedef signed   char           int8_t;   /* Signed    8 bit quantity  */
typedef unsigned int            uint16_t; /* Unsigned 16 bit quantity  */
typedef signed   int            int16_t;  /* Signed   16 bit quantity  */
typedef unsigned long           uint32_t; /* Unsigned 32 bit quantity  */
typedef signed   long           int32_t;  /* Signed   32 bit quantity  */
typedef unsigned long           uintptr_t;
typedef float                   fp32_t;
typedef double                  fp64_t;

typedef uint8_t                 nwk_id_t; 

#if HAVE_LONG_LONG > 0
typedef signed long long        int64_t;
typedef unsigned long long      uint64_t;
#else
typedef struct
{
#if IS_LITTLE_ENDIAN > 0
    uint32_t lo;
    uint32_t hi;
#else
    uint32_t hi;
    uint32_t lo;
#endif
} int64_t;
typedef int64_t uint64_t;
#endif

#ifndef NULL
#define NULL              ((void*)0)
#endif

#ifndef TRUE
#define TRUE              (uint8_t)1
#endif

#ifndef FALSE
#define FALSE               (uint8_t)0
#endif

#ifndef SUCCESS
#define SUCCESS                 (uint8_t)1
#endif

#ifndef FAILE
#define FAILE                   (uint8_t)0
#endif

#ifndef __INLINE
#define __INLINE
#endif

#ifndef FAILED
#define FAILED                  (uint8_t)0
#endif

/**
 * STANDARD BITS
 */
#ifndef BIT0
#define BIT0                    (0x01u)
#define BIT1                    (0x02u)
#define BIT2                    (0x04u)
#define BIT3                    (0x08u)
#define BIT4                    (0x10u)
#define BIT5                    (0x20u)
#define BIT6                    (0x40u)
#define BIT7                    (0x80u)
#endif

#ifndef st
#define st(x)                   do { x } while (__LINE__ == -1)
#endif

#ifndef BV
#define BV(n)                   (1 << (n))
#endif

#ifndef BM
#define BM(n)                   (1 << (n))
#endif

#ifndef BF
#define BF(x,b,s)               (((x) & (b)) >> (s))
#endif

#ifndef MIN
#define MIN(n,m)                (((n) < (m)) ? (n) : (m))
#endif

#ifndef MAX
#define MAX(n,m)                (((n) < (m)) ? (m) : (n))
#endif

#ifndef ABS
#define ABS(n)                  (((n) < 0) ? -(n) : (n))
#endif

#define HI_UINT16(a)            (((uint16_t)(a) >> 8) & 0xFF)
#define LO_UINT16(a)            ((uint16_t)(a) & 0xFF)

#ifndef _NOP
#define  _NOP()                 asm("NOP");
#endif

#endif
