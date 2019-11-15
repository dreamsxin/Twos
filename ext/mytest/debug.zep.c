
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/math.h"
#include "kernel/time.h"


ZEPHIR_INIT_CLASS(Mytest_Debug) {

	ZEPHIR_REGISTER_CLASS(Mytest, Debug, mytest, debug, mytest_debug_method_entry, 0);

	zend_declare_property_long(mytest_debug_ce, SL("interval"), 30, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);

	zend_declare_property_string(mytest_debug_ce, SL("lut"), "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(Mytest_Debug, decodes) {

	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, n = 0, j = 0, _3;
	zval *b32 = NULL, b32_sub, l, i, binary, _0, _1, _4, _5$$3, _6$$3, _7$$3, _8$$4, _9$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&b32_sub);
	ZVAL_UNDEF(&l);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&binary);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &b32);

	ZEPHIR_SEPARATE_PARAM(b32);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtoupper(&_0, b32);
	ZEPHIR_CPY_WRT(b32, &_0);
	ZEPHIR_INIT_VAR(&l);
	ZVAL_LONG(&l, (zephir_fast_strlen_ev(b32) - 1));
	n = 0;
	j = 0;
	ZEPHIR_INIT_VAR(&binary);
	ZVAL_NULL(&binary);
	ZEPHIR_CALL_FUNCTION(&_1, "str_split", NULL, 1, b32);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(b32, &_1);
	ZEPHIR_CPY_WRT(&_4, &l);
	_3 = 0;
	_2 = 0;
	if (ZEPHIR_GE_LONG(&_4, _3)) {
		while (1) {
			if (_2) {
				_3++;
				if (!(ZEPHIR_GE_LONG(&_4, _3))) {
					break;
				}
			} else {
				_2 = 1;
			}
			ZEPHIR_INIT_NVAR(&i);
			ZVAL_LONG(&i, _3);
			n = (n << 5);
			zephir_read_static_property_ce(&_5$$3, mytest_debug_ce, SL("lut"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_6$$3, b32, &i, PH_NOISY | PH_READONLY, "mytest/debug.zep", 17);
			ZEPHIR_INIT_NVAR(&_7$$3);
			zephir_fast_strpos(&_7$$3, &_5$$3, &_6$$3, 0 );
			n = (n + (zend_long) zephir_get_numberval(&_7$$3));
			j = (j + 5);
			if (j >= 8) {
				j = (j - 8);
				ZVAL_LONG(&_8$$4, (((n & ((0xff << j)))) >> j));
				ZEPHIR_CALL_FUNCTION(&_9$$4, "chr", &_10, 2, &_8$$4);
				zephir_check_call_status();
				zephir_concat_self(&binary, &_9$$4);
			}
		}
	}
	RETURN_CCTOR(&binary);

}

PHP_METHOD(Mytest_Debug, verify) {

	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _3, _4;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *secret, secret_sub, *otp, otp_sub, unixtime, i, ts, tmpk, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&secret_sub);
	ZVAL_UNDEF(&otp_sub);
	ZVAL_UNDEF(&unixtime);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&ts);
	ZVAL_UNDEF(&tmpk);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &secret, &otp);



	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	ZVAL_DOUBLE(&_1, zephir_safe_div_zval_long(&_0, 30));
	ZEPHIR_INIT_VAR(&unixtime);
	ZVAL_DOUBLE(&unixtime, zephir_floor(&_1));
	_4 = 2;
	_3 = -2;
	_2 = 0;
	if (_3 <= _4) {
		while (1) {
			if (_2) {
				_3++;
				if (!(_3 <= _4)) {
					break;
				}
			} else {
				_2 = 1;
			}
			ZEPHIR_INIT_NVAR(&i);
			ZVAL_LONG(&i, _3);
			ZEPHIR_INIT_NVAR(&ts);
			ZVAL_LONG(&ts, (zephir_get_numberval(&unixtime) + ((zephir_get_numberval(&i) * 30))));
			ZEPHIR_CALL_SELF(&tmpk, "generatecode", &_5, 0, secret, &ts);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(&tmpk, otp)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Mytest_Debug, generatesecretkey) {

	zend_bool _1;
	zval keytmp, b32, i, _0, _4$$3, _5$$3, _6$$3, _7$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keytmp);
	ZVAL_UNDEF(&b32);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&keytmp);
	ZVAL_STRING(&keytmp, "");
	ZEPHIR_INIT_VAR(&b32);
	ZVAL_STRING(&b32, "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567");
	ZEPHIR_CALL_FUNCTION(&_0, "str_split", NULL, 1, &b32);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&b32, &_0);
	_3 = 15;
	_2 = 0;
	_1 = 0;
	if (_2 <= _3) {
		while (1) {
			if (_1) {
				_2++;
				if (!(_2 <= _3)) {
					break;
				}
			} else {
				_1 = 1;
			}
			ZEPHIR_INIT_NVAR(&i);
			ZVAL_LONG(&i, _2);
			ZVAL_LONG(&_5$$3, 0);
			ZVAL_LONG(&_6$$3, 31);
			ZEPHIR_CALL_FUNCTION(&_7$$3, "rand", &_8, 3, &_5$$3, &_6$$3);
			zephir_check_call_status();
			zephir_array_fetch(&_4$$3, &b32, &_7$$3, PH_NOISY | PH_READONLY, "mytest/debug.zep", 48);
			zephir_concat_self(&keytmp, &_4$$3);
		}
	}
	RETURN_CCTOR(&keytmp);

}

PHP_METHOD(Mytest_Debug, generatecode) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _9;
	zval *key, key_sub, *step = NULL, step_sub, __$true, __$false, secret, timestamp, offset, hashs, hashpart, value, _2, _3, _4, _5, _6, _7, _8, _10, _11, _12, _13, _14, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&step_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&secret);
	ZVAL_UNDEF(&timestamp);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&hashs);
	ZVAL_UNDEF(&hashpart);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &step);

	if (!step) {
		step = &step_sub;
		ZEPHIR_CPY_WRT(step, &__$false);
	} else {
		ZEPHIR_SEPARATE_PARAM(step);
	}


	ZEPHIR_CALL_SELF(&secret, "decodes", NULL, 0, key);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(step)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_time(&_0$$3);
		ZVAL_DOUBLE(&_1$$3, zephir_safe_div_zval_long(&_0$$3, 30));
		ZEPHIR_INIT_NVAR(step);
		ZVAL_DOUBLE(step, zephir_floor(&_1$$3));
	}
	ZEPHIR_CALL_SELF(&timestamp, "pack64", NULL, 0, step);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "sha1");
	ZEPHIR_CALL_FUNCTION(&hashs, "hash_hmac", NULL, 4, &_2, &timestamp, &secret, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 19);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_substr(&_2, &hashs, 19 , 1 , 0);
	ZEPHIR_CALL_FUNCTION(&_5, "ord", NULL, 5, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&offset);
	ZVAL_LONG(&offset, ((zend_long) (zephir_get_numberval(&_5)) & 0x0f));
	ZVAL_LONG(&_6, 4);
	ZEPHIR_INIT_VAR(&hashpart);
	zephir_substr(&hashpart, &hashs, zephir_get_intval(&offset), 4 , 0);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "N");
	ZEPHIR_CALL_FUNCTION(&value, "unpack", NULL, 6, &_7, &hashpart);
	zephir_check_call_status();
	zephir_array_fetch_long(&_8, &value, 1, PH_NOISY | PH_READONLY, "mytest/debug.zep", 66);
	ZEPHIR_CPY_WRT(&value, &_8);
	_9 = ((zend_long) (zephir_get_numberval(&value)) & 0x7FFFFFFF);
	ZEPHIR_INIT_NVAR(&value);
	ZVAL_LONG(&value, _9);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_10, 10);
	ZVAL_LONG(&_11, 6);
	zephir_pow_function(&_7, &_10, &_11);
	ZEPHIR_INIT_VAR(&_12);
	mod_function(&_12, &value, &_7);
	ZVAL_LONG(&_13, 6);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "0");
	ZVAL_LONG(&_14, 0);
	ZEPHIR_RETURN_CALL_FUNCTION("str_pad", NULL, 7, &_12, &_13, &_7, &_14);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Mytest_Debug, pack64) {

	zend_bool _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, highmap = 0, lowmap = 0;
	zval *value, value_sub, higher, lower, _0, _8, _1$$3, _2$$3, _3$$3, _4$$3, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&higher);
	ZVAL_UNDEF(&lower);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_INT_SIZE");
	ZEPHIR_INIT_VAR(&higher);
	if (ZEPHIR_GE_LONG(&_0, 8)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_GET_CONSTANT(&_1$$3, "PHP_VERSION");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "5.6.3");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, ">=");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "version_compare", NULL, 8, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		_5$$3 = zephir_is_true(&_4$$3);
		if (_5$$3) {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZEPHIR_GET_CONSTANT(&_2$$3, "PHP_INT_SIZE");
			_5$$3 = ZEPHIR_GE_LONG(&_2$$3, 8);
		}
		if (_5$$3) {
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "J");
			ZEPHIR_RETURN_CALL_FUNCTION("pack", &_7, 9, &_6$$4, value);
			zephir_check_call_status();
			RETURN_MM();
		}
		highmap = -4294967296;
		ZVAL_LONG(&higher, ((((zend_long) (zephir_get_numberval(value)) & highmap)) >> 32));
	} else {
		ZVAL_LONG(&higher, 0);
	}
	lowmap = 4294967295;
	ZEPHIR_INIT_VAR(&lower);
	ZVAL_LONG(&lower, ((zend_long) (zephir_get_numberval(value)) & lowmap));
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "NN");
	ZEPHIR_RETURN_CALL_FUNCTION("pack", &_7, 9, &_8, &higher, &lower);
	zephir_check_call_status();
	RETURN_MM();

}

