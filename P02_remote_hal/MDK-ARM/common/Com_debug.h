#ifndef __COM_DEBUG_H__
#define __COM_DEBUG_H__

#include "usart.h"
#include "stdio.h"
#include <string.h>

#define DEBUG_LOG_ENABLE 1//注释该行代码即可关闭日志打印

#ifdef DEBUG_LOG_ENABLE
#define __FILE_NAME__ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1):__FILE__)
#define debug_printf(format, ...) printf( "[%s:%d]" format,__FILE_NAME__, __LINE__,##__VA_ARGS__)

#else
#define debug_printf(format, ...)

#endif

#endif
