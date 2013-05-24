/**
 * Debug output wrapper
 */

#ifndef __NORDB_DBG
#define __NORDB_DBG

#include "nordb_opt.h"

#if DBG_ON == 1
#include <stdio.h>
#define DBG(...) printf(__VA_ARGS__);
#endif

#endif
