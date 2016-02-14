#ifndef PNG_H
#define PNG_H

/*
	Prints the given message to stderr and exits the program with status code
	EXIT_FAILURE.
*/
void error(const char *msg);

/* ========================================================================== */

/*
	Defines a pointer to a function that is used to convert a 32-bit integer to
	big-endian format and write it into a buffer. The return value is a pointer
	to the new start of the buffer (buf + 4).
*/
typedef uint8_t *(*write_be_function)(uint32_t value, uint8_t *buf);

/*
	Determines whether the processor uses big-endian, little-endian, or middle-
	endian format, and returns the appropriate write_be_function. In case the
	processor uses some other format (which is impossible), an error message is
	displayed and the program exits. More information about determining
	endianness at runtime (which ensures portability) can be found at
	http://hashdefine.net/blog/2015/06/07/endianness-how-to-manage-in-c.
*/
write_be_function get_write_be_function();

/*
	Initially set to NULL, but later set to the write_be_function that
	corresponds to the processor on which the program is being run.
*/
extern write_be_function write_be;

/* ========================================================================== */

/*
	A precomputed 32-bit CRC (Cyclic Redundancy Code) lookup table, used to
	speed up the creation of a CRC checksum for each chunk in a PNG file. More
	information about how to get the standard 32-bit CRC values can be found at
	http://www.barrgroup.com/Embedded-Systems/How-To/CRC-Calculation-C-Code.
*/
extern const uint32_t crc32_lookup_table[];

/*
	Creates a 32-bit CRC checksum from the first buf_len bytes in buf. In PNG
	files, the CRC is initialized to all 1's, then the data from each byte is
	processed, and lastly the 1's complement of the CRC is taken. More
	information about the use of CRC checksums in PNG files can be found at
	https://www.w3.org/TR/PNG/#5CRC-algorithm.
*/
uint32_t crc32(const uint8_t *buf, size_t buf_len);

#endif
