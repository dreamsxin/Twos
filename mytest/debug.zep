namespace Mytest;

class Debug
{
	protected static interval = 30;
	private static lut = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
	
	public static function decodes(b32)
	{
		var l,n,j,i,binary;
		let b32 = strtoupper(b32);
		let l = strlen(b32) - 1;
		let n = 0, j = 0, binary = null;
		let b32 = str_split(b32);
		for i in range(0,l) {
			let n = n << 5;
			let n = n + strpos(self::lut, b32[i]);
			let j = j + 5;
			if j >= 8 {
				let j = j - 8;
				let binary .= chr((n & (0xff << j)) >> j);
			}
		}
		return binary;
	}
	
	public function verify(secret, otp) 
	{
		var unixtime, i, ts, tmpk;
		let unixtime = floor(time() / 30);

		for i in range (-2,2) {
			 let ts = unixtime + (i * 30);
		    let tmpk = self::generatecode(secret,ts);
				if (tmpk == otp) {
					return true;
				}
		}
 	return false;
	}
	
	public static function generatesecretkey()
	{
		var keytmp,b32,i;
		let keytmp = "", b32 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
		let b32 = str_split(b32);
		for i in range(0,15){
			let keytmp .= b32[rand(0,31)];
		}
		return keytmp;
	}

	public static function generatecode(key, step = false)
	{
		var secret,timestamp,offset,hashs,hashpart,value;
		let secret = self::decodes(key);
		if step == false {
			let step = floor( time() / 30);
		}
		let timestamp = self::pack64(step);
		let hashs = hash_hmac( "sha1", timestamp, secret, true);

		let offset = ord( substr(hashs, 19, 1) ) & 0x0f;
		let hashpart = substr(hashs, offset, 4);
		let value = unpack("N", hashpart);
		let value = value[1];
		let value = value & 0x7FFFFFFF;
		return str_pad(value % pow(10, 6), 6, "0", STR_PAD_LEFT);
	}
	
	public static function pack64( value )
	{
		var highmap,higher,lowmap,lower;
		if ( PHP_INT_SIZE >= 8 ) {
			if ( version_compare( PHP_VERSION, "5.6.3", ">=" ) && PHP_INT_SIZE >= 8 ) {
				return pack( "J", value );
			}
			let highmap = 4294967295 << 32;
			let higher  = ( value & highmap ) >> 32;
		} else {
			let higher = 0;
		}
		let lowmap  = 4294967295;
		let lower   = value & lowmap;
		return pack( "NN", higher, lower);
	}
}
