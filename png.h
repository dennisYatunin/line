/*
	A precomputed 32-bit CRC (Cyclic Redundancy Code) lookup table, used to
	speed up the creation of a CRC checksum for each chunk in a PNG. More
	information about how to get the standard 32-bit CRC values can be found at
	http://www.barrgroup.com/Embedded-Systems/How-To/CRC-Calculation-C-Code.
*/
extern const unsigned int crc32_lookup_table[];

/*
	Creates a 32-bit CRC checksum from the string consisting of type (which
	must be 4 characters long) followed by the first data_len characters in
	data. In PNG, the CRC is initialized to all 1's, then the data from each
	byte is processed, and lastly the 1's complement of the CRC is taken. More
	information can be found at https://www.w3.org/TR/PNG/#5CRC-algorithm.
*/
unsigned int png_crc(const char *type, const unsigned char *data, int data_len);

png_chunk(const char *type, const unsigned char *data, int data_len, unsigned char *buf)