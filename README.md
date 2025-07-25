# Huffman-ENCODING-DECODING

Huffman Encoding & DECODING is a compression of a source information.

The program supports **ENCODING** and **DECODING** from both **console** and **file**

Methods used:
  - STATIC
  - DYNAMIC (FGK version)

# USAGE
  1. Download the ***git***:  
### `git clone https://github.com/s0chu/Huffman-ENCODING-DECODING`
  2. Start ***starter.sh***:  
### `bash starter.sh`
  3. Follow the console for information
![▶️ Demo](Assets/demo.gif)

# DETAILS
## STATIC version
Uses the classical and optimal version for minimizing the average number of bits
Max Code-Word can have a length of ***|Alpha| - 1*** characters, where ***Alpha*** represents the alphabet

Encoding Format: `code#ascii(ch_1)#fr_ch_1#...#ascii(ch_|Alpha|)#fr_ch_|Alpha|`, where *ascii(ch)* is the base 10 of the ascii code of ch

Example: The encoding of ***Hello!!!!!!*** is **110101100100111000000#33#6#72#1#101#1#108#2#111#1**
Time complexity: `O(|Text| · |Alpha| · log(|Alpha|))`
## DYNAMIC version
Uses 1 traversal of the source information
Every new character is composed in the encoding of *ESC encoding* + ascii 8 bit of the character

Example: The encoding of ***abccd*** is **01100001 0 01100010 00 01100011 1011 00 01100100** which simplifies into **a esc b esc c 1011 esc d**
Time complexity: `O(|Text| · |Alpha|)`