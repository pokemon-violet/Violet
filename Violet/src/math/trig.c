/*
 * sin.c
 *
 *  Created on: Jun 7, 2018
 *      Author: dominik
 */
#include "types.h"
#include "math.h"
#include "debug.h"



FIXED FIXED_TRIANGLE_SIN(FIXED theta) {
  // This function can only handle positive angles
  if (theta < 0) return -FIXED_TRIANGLE_SIN(-theta);
  // Extract the fractional part
  int fractional_part = theta & ((1 << FIXED_SHIFT) - 1);
  // Get the number of bits indexing the quadrant
  int quadrant_bits = FIXED_SHIFT - 2;
  // Get the quadrant to access
  int quadrant_idx = fractional_part >> quadrant_bits;
  // Get the bits that index the lut
  int lut_idx = fractional_part & ((1 << quadrant_bits) - 1);
  switch(quadrant_idx) {
    case 0: {
      // Quadrant 0: y = 4x
      return lut_idx * 4;
    }
    case 1: {
      // Quadrant 1: y = 1 - 4x
      return INT_TO_FIXED(1) - 4 * lut_idx;
    }
    case 2: {
      // Quadrant 2: y = -4x
      return - 4 * lut_idx;
    }
    case 3: {
      // Quadrant 3: y = 4x - 1
      return 4 * lut_idx - INT_TO_FIXED(1);
    }
    default:
      return 0;
  }
}

FIXED FIXED_TRIANGLE_COS(FIXED theta) {
  return FIXED_TRIANGLE_SIN(theta + (1 << (FIXED_SHIFT - 2)));
}

FIXED FIXED_TRIANGLE_TAN(FIXED theta) {
  FIXED sin = FIXED_TRIANGLE_SIN(theta);
  FIXED cos = FIXED_TRIANGLE_COS(theta);
  if (!cos) {
    derrf("Triangle tangens not defined for theta %d\n", theta);
    return -1;
  }
  return FIXED_DIV(sin, cos);
}

FIXED FIXED_SIN(FIXED theta) {
  // This function can only handle positive angles
  if (theta < 0) return -FIXED_SIN(-theta);
  // Extract the fractional part
  int fractional_part = theta & ((1 << FIXED_SHIFT) - 1);
  // Get the number of bits indexing the quadrant
  int quadrant_bits = FIXED_SHIFT - 2;
  // Get the quadrant to access
  int quadrant_idx = fractional_part >> quadrant_bits;
  // Get the bits that index the lut
  int lut_idx = fractional_part & ((1 << quadrant_bits) - 1);
  // Scale the lut_idx to index the lut
  lut_idx >>= quadrant_bits - SIN_LUT_BITS;
  int result = 1;
  switch(quadrant_idx) {
    case 2:
      result = -1;
      FALL_THROUGH;
    case 0: {
      // First quadrant
      return result * sin_lut[lut_idx];
    }
    case 3: {
      result = -1;
      FALL_THROUGH;
    }
    case 1: {
      // Second quadrant
      // For exactly 90 degrees return 1.0
      if(!lut_idx) return (1 << FIXED_SHIFT) * result;
      // Reverse index the [0, 90) degree lut
      return result * sin_lut[(1 << SIN_LUT_BITS) - lut_idx];
    }
    default:
      return 0;
  }
}

FIXED FIXED_COS(FIXED theta) {
  return FIXED_SIN(theta + (1 << (FIXED_SHIFT - 2)));
}

FIXED FIXED_TAN(FIXED theta) {
  FIXED sin = FIXED_SIN(theta);
  FIXED cos = FIXED_COS(theta);
  if (!cos) {
    derrf("Tangens not defined for theta %d\n", theta);
    return -1;
  }
  return FIXED_DIV(sin, cos);
}

u16 sin_lut[1 << SIN_LUT_BITS]= {
  0x0000, 0x00C9, 0x0192, 0x025B, 0x0324, 0x03ED, 0x04B6, 0x057F,
  0x0648, 0x0711, 0x07DA, 0x08A3, 0x096C, 0x0A35, 0x0AFE, 0x0BC6,
  0x0C8F, 0x0D58, 0x0E21, 0x0EEA, 0x0FB2, 0x107B, 0x1144, 0x120C,
  0x12D5, 0x139D, 0x1466, 0x152E, 0x15F6, 0x16BF, 0x1787, 0x184F,
  0x1917, 0x19DF, 0x1AA7, 0x1B6F, 0x1C37, 0x1CFF, 0x1DC7, 0x1E8E,
  0x1F56, 0x201D, 0x20E5, 0x21AC, 0x2273, 0x233B, 0x2402, 0x24C9,
  0x2590, 0x2656, 0x271D, 0x27E4, 0x28AA, 0x2971, 0x2A37, 0x2AFE,
  0x2BC4, 0x2C8A, 0x2D50, 0x2E15, 0x2EDB, 0x2FA1, 0x3066, 0x312C,
  0x31F1, 0x32B6, 0x337B, 0x3440, 0x3505, 0x35C9, 0x368E, 0x3752,
  0x3817, 0x38DB, 0x399F, 0x3A62, 0x3B26, 0x3BEA, 0x3CAD, 0x3D70,
  0x3E33, 0x3EF6, 0x3FB9, 0x407C, 0x413E, 0x4201, 0x42C3, 0x4385,
  0x4447, 0x4508, 0x45CA, 0x468B, 0x474D, 0x480E, 0x48CE, 0x498F,
  0x4A50, 0x4B10, 0x4BD0, 0x4C90, 0x4D50, 0x4E0F, 0x4ECF, 0x4F8E,
  0x504D, 0x510C, 0x51CA, 0x5289, 0x5347, 0x5405, 0x54C3, 0x5581,
  0x563E, 0x56FB, 0x57B8, 0x5875, 0x5931, 0x59EE, 0x5AAA, 0x5B66,
  0x5C22, 0x5CDD, 0x5D98, 0x5E53, 0x5F0E, 0x5FC9, 0x6083, 0x613D,
  0x61F7, 0x62B1, 0x636A, 0x6423, 0x64DC, 0x6595, 0x664D, 0x6705,
  0x67BD, 0x6875, 0x692D, 0x69E4, 0x6A9B, 0x6B51, 0x6C08, 0x6CBE,
  0x6D74, 0x6E29, 0x6EDF, 0x6F94, 0x7049, 0x70FD, 0x71B1, 0x7265,
  0x7319, 0x73CD, 0x7480, 0x7533, 0x75E5, 0x7698, 0x774A, 0x77FB,
  0x78AD, 0x795E, 0x7A0F, 0x7AC0, 0x7B70, 0x7C20, 0x7CD0, 0x7D7F,
  0x7E2E, 0x7EDD, 0x7F8B, 0x803A, 0x80E7, 0x8195, 0x8242, 0x82EF,
  0x839C, 0x8448, 0x84F4, 0x85A0, 0x864B, 0x86F6, 0x87A1, 0x884B,
  0x88F5, 0x899F, 0x8A48, 0x8AF1, 0x8B9A, 0x8C42, 0x8CEA, 0x8D92,
  0x8E39, 0x8EE0, 0x8F87, 0x902D, 0x90D3, 0x9179, 0x921E, 0x92C3,
  0x9368, 0x940C, 0x94B0, 0x9553, 0x95F6, 0x9699, 0x973C, 0x97DE,
  0x987F, 0x9921, 0x99C2, 0x9A62, 0x9B02, 0x9BA2, 0x9C42, 0x9CE1,
  0x9D7F, 0x9E1E, 0x9EBC, 0x9F59, 0x9FF6, 0xA093, 0xA12F, 0xA1CB,
  0xA267, 0xA302, 0xA39D, 0xA438, 0xA4D2, 0xA56B, 0xA605, 0xA69D,
  0xA736, 0xA7CE, 0xA866, 0xA8FD, 0xA994, 0xAA2A, 0xAAC0, 0xAB56,
  0xABEB, 0xAC80, 0xAD14, 0xADA8, 0xAE3B, 0xAECE, 0xAF61, 0xAFF3,
  0xB085, 0xB117, 0xB1A8, 0xB238, 0xB2C8, 0xB358, 0xB3E7, 0xB476,
  0xB504, 0xB592, 0xB620, 0xB6AD, 0xB73A, 0xB7C6, 0xB852, 0xB8DD,
  0xB968, 0xB9F2, 0xBA7C, 0xBB06, 0xBB8F, 0xBC17, 0xBCA0, 0xBD27,
  0xBDAE, 0xBE35, 0xBEBC, 0xBF41, 0xBFC7, 0xC04C, 0xC0D0, 0xC154,
  0xC1D8, 0xC25B, 0xC2DE, 0xC360, 0xC3E2, 0xC463, 0xC4E3, 0xC564,
  0xC5E4, 0xC663, 0xC6E2, 0xC760, 0xC7DE, 0xC85B, 0xC8D8, 0xC955,
  0xC9D1, 0xCA4C, 0xCAC7, 0xCB41, 0xCBBB, 0xCC35, 0xCCAE, 0xCD26,
  0xCD9F, 0xCE16, 0xCE8D, 0xCF04, 0xCF7A, 0xCFEF, 0xD064, 0xD0D9,
  0xD14D, 0xD1C0, 0xD233, 0xD2A6, 0xD318, 0xD389, 0xD3FA, 0xD46B,
  0xD4DB, 0xD54A, 0xD5B9, 0xD627, 0xD695, 0xD703, 0xD770, 0xD7DC,
  0xD848, 0xD8B3, 0xD91E, 0xD988, 0xD9F2, 0xDA5B, 0xDAC4, 0xDB2C,
  0xDB94, 0xDBFB, 0xDC61, 0xDCC7, 0xDD2D, 0xDD92, 0xDDF6, 0xDE5A,
  0xDEBE, 0xDF20, 0xDF83, 0xDFE4, 0xE046, 0xE0A6, 0xE106, 0xE166,
  0xE1C5, 0xE224, 0xE282, 0xE2DF, 0xE33C, 0xE398, 0xE3F4, 0xE44F,
  0xE4AA, 0xE504, 0xE55E, 0xE5B7, 0xE60F, 0xE667, 0xE6BE, 0xE715,
  0xE76B, 0xE7C1, 0xE816, 0xE86B, 0xE8BF, 0xE912, 0xE965, 0xE9B7,
  0xEA09, 0xEA5A, 0xEAAB, 0xEAFB, 0xEB4B, 0xEB99, 0xEBE8, 0xEC36,
  0xEC83, 0xECD0, 0xED1C, 0xED67, 0xEDB2, 0xEDFC, 0xEE46, 0xEE8F,
  0xEED8, 0xEF20, 0xEF68, 0xEFAF, 0xEFF5, 0xF03B, 0xF080, 0xF0C5,
  0xF109, 0xF14C, 0xF18F, 0xF1D1, 0xF213, 0xF254, 0xF294, 0xF2D4,
  0xF314, 0xF353, 0xF391, 0xF3CE, 0xF40B, 0xF448, 0xF484, 0xF4BF,
  0xF4FA, 0xF534, 0xF56D, 0xF5A6, 0xF5DE, 0xF616, 0xF64D, 0xF684,
  0xF6BA, 0xF6EF, 0xF724, 0xF758, 0xF78B, 0xF7BE, 0xF7F1, 0xF822,
  0xF853, 0xF884, 0xF8B4, 0xF8E3, 0xF912, 0xF940, 0xF96E, 0xF99B,
  0xF9C7, 0xF9F3, 0xFA1E, 0xFA49, 0xFA73, 0xFA9C, 0xFAC5, 0xFAED,
  0xFB14, 0xFB3B, 0xFB61, 0xFB87, 0xFBAC, 0xFBD1, 0xFBF5, 0xFC18,
  0xFC3B, 0xFC5D, 0xFC7E, 0xFC9F, 0xFCBF, 0xFCDF, 0xFCFE, 0xFD1C,
  0xFD3A, 0xFD57, 0xFD74, 0xFD90, 0xFDAB, 0xFDC6, 0xFDE0, 0xFDFA,
  0xFE13, 0xFE2B, 0xFE43, 0xFE5A, 0xFE70, 0xFE86, 0xFE9B, 0xFEB0,
  0xFEC4, 0xFED7, 0xFEEA, 0xFEFC, 0xFF0E, 0xFF1F, 0xFF2F, 0xFF3F,
  0xFF4E, 0xFF5C, 0xFF6A, 0xFF78, 0xFF84, 0xFF90, 0xFF9C, 0xFFA6,
  0xFFB1, 0xFFBA, 0xFFC3, 0xFFCB, 0xFFD3, 0xFFDA, 0xFFE1, 0xFFE7,
  0xFFEC, 0xFFF0, 0xFFF4, 0xFFF8, 0xFFFB, 0xFFFD, 0xFFFE, 0xFFFF,
};


