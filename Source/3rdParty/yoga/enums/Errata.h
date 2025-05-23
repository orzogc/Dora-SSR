/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off
#pragma once

#include <cstdint>
#include "yoga/YGEnums.h"
#include "yoga/enums/YogaEnums.h"

namespace facebook::yoga {

enum class Errata : uint32_t {
  None = YGErrataNone,
  StretchFlexBasis = YGErrataStretchFlexBasis,
  AbsolutePositionWithoutInsetsExcludesPadding = YGErrataAbsolutePositionWithoutInsetsExcludesPadding,
  AbsolutePercentAgainstInnerSize = YGErrataAbsolutePercentAgainstInnerSize,
  All = YGErrataAll,
  Classic = YGErrataClassic,
};

YG_DEFINE_ENUM_FLAG_OPERATORS(Errata)

constexpr Errata scopedEnum(YGErrata unscoped) {
  return static_cast<Errata>(unscoped);
}

constexpr YGErrata unscopedEnum(Errata scoped) {
  return static_cast<YGErrata>(scoped);
}

inline const char* toString(Errata e) {
  return YGErrataToString(unscopedEnum(e));
}

} // namespace facebook::yoga
