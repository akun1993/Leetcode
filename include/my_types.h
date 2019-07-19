#ifndef __MY_TYPES_H__
#define __MY_TYPES_H__



#define SYS_64_BIT
//#define SYS_32_BIT

#ifdef SYS_32_BIT
typedef long long s64;
#else
typedef long      s64;
#endif
typedef int       s32;
typedef short     s16;
typedef char      s8;

#ifdef SYS_32_BIT
typedef unsigned long long u64;
#else
typedef unsigned long      u64;
#endif
typedef unsigned int       u32;
typedef unsigned short     u16;
typedef unsigned char      u8;

//network order
#ifdef SYS_32_BIT
typedef unsigned long long be64;
#else
typedef unsigned long      be64;
#endif
typedef unsigned int       be32;
typedef unsigned short     be16;

#endif
