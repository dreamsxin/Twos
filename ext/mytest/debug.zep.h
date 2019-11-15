
extern zend_class_entry *mytest_debug_ce;

ZEPHIR_INIT_CLASS(Mytest_Debug);

PHP_METHOD(Mytest_Debug, decodes);
PHP_METHOD(Mytest_Debug, verify);
PHP_METHOD(Mytest_Debug, generatesecretkey);
PHP_METHOD(Mytest_Debug, generatecode);
PHP_METHOD(Mytest_Debug, pack64);

ZEND_BEGIN_ARG_INFO_EX(arginfo_mytest_debug_decodes, 0, 0, 1)
	ZEND_ARG_INFO(0, b32)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mytest_debug_verify, 0, 0, 2)
	ZEND_ARG_INFO(0, secret)
	ZEND_ARG_INFO(0, otp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mytest_debug_generatecode, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mytest_debug_pack64, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(mytest_debug_method_entry) {
	PHP_ME(Mytest_Debug, decodes, arginfo_mytest_debug_decodes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Mytest_Debug, verify, arginfo_mytest_debug_verify, ZEND_ACC_PUBLIC)
	PHP_ME(Mytest_Debug, generatesecretkey, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Mytest_Debug, generatecode, arginfo_mytest_debug_generatecode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Mytest_Debug, pack64, arginfo_mytest_debug_pack64, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
