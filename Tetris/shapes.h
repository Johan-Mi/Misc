#pragma once

typedef enum {
	O,
	I1, I2, I3, I4,
	T1, T2, T3, T4,
	J1, J2, J3, J4,
	L1, L2, L3, L4,
	S1, S2, S3, S4,
	Z1, Z2, Z3, Z4,
} Shape;

/*
 * O
 * -OO-
 * -OO-
 * ----
 *
 * I1   I2   I3   I4
 * ---- --O- ---- -O--
 * OOOO --O- ---- -O--
 * ---- --O- OOOO -O--
 * ---- --O- ---- -O--
 *
 * T1  T2  T3  T4
 * -O- -O- --- -O-
 * OOO -OO OOO OO-
 * --- -O- -O- -O-
 *
 * J1  J2  J3  J4
 * O-- -OO --- -O-
 * OOO -O- OOO -O-
 * --- -O- --O -OO
 *
 * L1  L2  L3  L4
 * --O -O- --- OO-
 * OOO -O- OOO -O-
 * --- -OO O-- -O-
 *
 * S1  S2  S3  S4
 * -OO -O- --- O--
 * OO- -OO -OO OO-
 * --- --O OO- -O-
 *
 * Z1  Z2  Z3  Z4
 * OO- --O --- -O-
 * -OO -OO OO- OO-
 * --- -O- -OO O--
 *
 */
