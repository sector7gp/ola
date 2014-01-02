/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * MathUtils.cpp
 * Basic math helper functions.
 * Copyright (C) 2013 Peter Newman
 */

#define __STDC_LIMIT_MACROS  // for UINT8_MAX & friends
#include <stdint.h>

#include <limits>

namespace ola {
namespace math {

void UInt16ToTwoUInt8(const uint16_t &input, uint8_t *high, uint8_t *low) {
  *high = (input >> std::numeric_limits<uint8_t>::digits) & UINT8_MAX;
  *low = input & UINT8_MAX;
}

uint16_t TwoUInt8ToUInt16(const uint8_t &high, const uint8_t &low) {
  return (((uint16_t)high << std::numeric_limits<uint8_t>::digits) | low);
}
}  // namespace math
}  // namespace ola
