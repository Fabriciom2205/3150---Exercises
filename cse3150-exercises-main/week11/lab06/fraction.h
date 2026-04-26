#pragma once

#include "bigint.h"
#include <utility>

using BigFraction = std::pair<bigint, bigint>;

BigFraction fraction_add(BigFraction a, BigFraction b);
BigFraction fraction_multiply(BigFraction a, BigFraction b);