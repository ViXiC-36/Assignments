.orig x3000

ld r2, DATA
not r2, r2
add r2, r2, #1
st r2, DATA
DATA .fill xf001
.end