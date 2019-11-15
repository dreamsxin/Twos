<?php
class Twos {
	const DEFAULT_TIME_STEP_SEC = 30;
	private static $_base_32_chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ234567';
 	
	public static function is_valid_authcode($secret, $code, $discrepancy = 2,$unixTime = null) {
				if ($unixTime === null) {
          $unixTime = floor(time() / self::DEFAULT_TIME_STEP_SEC);
      }
      if (strlen($code) != 6) {
          return false;
      }
      for ($i = -$discrepancy; $i <= $discrepancy; ++$i) {
					$calculatedCode = self::calc_totp($secret, $unixTime + ($i * 30));
           if($calculatedCode == $code){
						 return true;
					 }
      }
       return false;
    }
 
 
	public static function generatesecretkey($length = 16) {
		$keyTmp = "";
		$b32 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
		for ($i = 0; $i < $length; $i++)
		$keyTmp .= $b32[rand(0,31)];
		return $keyTmp;
	}
	
 
	public static function pack64( $value ) {
		// 64bit mode (PHP_INT_SIZE == 8).
		if ( PHP_INT_SIZE >= 8 ) {
			// If we're on PHP 5.6.3+ we can use the new 64bit pack functionality.
			if ( version_compare( PHP_VERSION, '5.6.3', '>=' ) && PHP_INT_SIZE >= 8 ) {
				return pack( 'J', $value );
			}
			$highmap = 0xffffffff << 32;
			$higher  = ( $value & $highmap ) >> 32;
		} else {
			/*
			 * 32bit PHP can't shift 32 bits like that, so we have to assume 0 for the higher
			 * and not pack anything beyond it's limits.
			 */
			$higher = 0;
		}

		$lowmap  = 0xffffffff;
		$lower   = $value & $lowmap;

		return pack( 'NN', $higher, $lower );
	}

	//备用测试
	public static function calc_totpdd( $key, $step_count = false ) 
	{
		$secret = self::base32_decode( $key );

		if ( false === $step_count ) {
			$step_count = floor( time() / self::DEFAULT_TIME_STEP_SEC);
		}
		$timestamp = self::pack64( $step_count );
		$hash = hash_hmac( "sha1", $timestamp, $secret, true );

		$offset = ord( $hash[19] ) & 0xf;
		
		$code = (
				( ( ord( $hash[ $offset + 0 ] ) & 0x7f ) << 24 ) |
				( ( ord( $hash[ $offset + 1 ] ) & 0xff ) << 16 ) |
				( ( ord( $hash[ $offset + 2 ] ) & 0xff ) << 8 ) |
				( ord( $hash[ $offset + 3 ] ) & 0xff )
			) % pow( 10, 6 );

		return str_pad( $code, 6, '0', STR_PAD_LEFT );
	}
 
	public static function calc_totp( $key, $step_count = false ) {
		$secret = self::base32_decode( $key );
		if ( false === $step_count ) {
			$step_count = floor( time() / self::DEFAULT_TIME_STEP_SEC);
		}
		$timestamp = self::pack64( $step_count );
		$hash = hash_hmac( "sha1", $timestamp, $secret, true );
		$offset = ord(substr($hash, -1)) & 0x0F;
		$hast = substr($hash, $offset, 4);
		$value = unpack("N", $hast);
		$value = $value[1];
		//$value =  sprintf("%u", $value);
		$value =  $value & 0x7FFFFFFF;
		return str_pad($value % pow(10, 6), 6, "0", STR_PAD_LEFT);
	}
 
	public static function base32_decode($b32) {
		$b32 	= strtoupper($b32); 
		$l 	= strlen($b32);
		$n	= 0;
		$j	= 0;
		$binary = "";
		if (preg_match('/^[ABCDEFGHIJKLMNOPQRSTUVWXYZ234567]+$/', $b32)){
			for ($i = 0; $i < $l; $i++) {
					$n = $n << 5;
					$n = $n + strpos( self::$_base_32_chars, $b32[ $i ] ) ;
					$j = $j + 5;
					//echo 'n='.$n.PHP_EOL;
					if ($j >= 8) {
							$j = $j - 8;
							//echo 'n2='.(($n & (0xFF << $j)) >> $j).PHP_EOL;
							$binary .= chr(($n & (0xFF << $j)) >> $j);
							//echo 'binary'.bin2hex($binary).PHP_EOL;
					}
			}
		}
		return $binary;
	}

}

$totp = new Twos();
//$secart = $totp::generatesecretkey();
$secart = "ME42YT3UITXDDW7U";
$time = 1573781275;
$getcode = $totp::calc_totp($secart, $time/30);
$isok = $totp::is_valid_authcode($secart,$getcode);
var_dump($secart,$getcode,$isok);

echo PHP_EOL;

$totps = new Mytest\Debug();

$getcode = $totps::generatecode($secart, $time/30);
$isok = $totps->verify($secart,$getcode);
var_dump($secart,$getcode,$isok);