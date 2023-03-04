## hexadecimal-dump

The function outputs a buffer in the form of the ASCII codes of the characters in hexadecimal format on the one hand and the corresponding characters (if they can be represented) on the other.

The output format corresponds exactly to the following structure:
- 6 characters buffer offset with leading zeros,
- 1 space character, 1 colon, 1 space character,
- Output of the next 16 bytes in the buffer formatted in 2 characters with leading 0 in hexadecimal format, where each two consecutive outputs are separated by exactly one space character,
- 3 spaces,
- 16 times the output of the previously hexadecimally represented bytes as a character, provided that this is "printable"
- Newline.
