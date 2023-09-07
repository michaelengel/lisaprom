# lisaprom
Trying to replace the Apple Lisa's CPU board 6309 PROM with a 22V10 GAL

gal-contents.txt is a hex dump of the original Lisa PROM

gal.c extracts single bits 0..7 for addresses 0...255 from the input data

bits.txt is the derivation and manual optimization of the logic formulas for bits 0..7

out.c implements the logic formulas for the GAL (correctness check)

