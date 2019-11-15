
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "mytest.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *mytest_debug_ce;

ZEND_DECLARE_MODULE_GLOBALS(mytest)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(mytest)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Mytest_Debug);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(mytest)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_mytest_globals *mytest_globals TSRMLS_DC)
{
	mytest_globals->initialized = 0;

	/* Cache Enabled */
	mytest_globals->cache_enabled = 1;

	/* Recursive Lock */
	mytest_globals->recursive_lock = 0;

	/* Static cache */
	memset(mytest_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_mytest_globals *mytest_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(mytest)
{
	zend_mytest_globals *mytest_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	mytest_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(mytest_globals_ptr);
	zephir_initialize_memory(mytest_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(mytest)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(mytest)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_MYTEST_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_MYTEST_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_MYTEST_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_MYTEST_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_MYTEST_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(mytest)
{
	php_zephir_init_globals(mytest_globals);
	php_zephir_init_module_globals(mytest_globals);
}

static PHP_GSHUTDOWN_FUNCTION(mytest)
{
	
}


zend_function_entry php_mytest_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_mytest_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry mytest_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_mytest_deps,
	PHP_MYTEST_EXTNAME,
	php_mytest_functions,
	PHP_MINIT(mytest),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(mytest),
#else
	NULL,
#endif
	PHP_RINIT(mytest),
	PHP_RSHUTDOWN(mytest),
	PHP_MINFO(mytest),
	PHP_MYTEST_VERSION,
	ZEND_MODULE_GLOBALS(mytest),
	PHP_GINIT(mytest),
	PHP_GSHUTDOWN(mytest),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(mytest),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_MYTEST
ZEND_GET_MODULE(mytest)
#endif
