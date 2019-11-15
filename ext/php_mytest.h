
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_MYTEST_H
#define PHP_MYTEST_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_MYTEST_NAME        "mytest"
#define PHP_MYTEST_VERSION     "0.0.1"
#define PHP_MYTEST_EXTNAME     "mytest"
#define PHP_MYTEST_AUTHOR      ""
#define PHP_MYTEST_ZEPVERSION  "0.12.12-$Id$"
#define PHP_MYTEST_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(mytest)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(mytest)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(mytest)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(mytest, v)
#else
	#define ZEPHIR_GLOBAL(v) (mytest_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_mytest_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(mytest_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(mytest_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def mytest_globals
#define zend_zephir_globals_def zend_mytest_globals

extern zend_module_entry mytest_module_entry;
#define phpext_mytest_ptr &mytest_module_entry

#endif
