/*
 * Copyright (c) 2023 Louis Langholtz https://github.com/louis-langholtz/PlayRho
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#ifndef PLAYRHO_BODYSHAPEFUNCTION_HPP
#define PLAYRHO_BODYSHAPEFUNCTION_HPP

/// @file
/// @brief Definition of the <code>BodyShapeFunction</code> type alias.

#include <functional> // for std::function
#include <utility> // for std::pair

// IWYU pragma: begin_exports

#include "playrho/BodyID.hpp"
#include "playrho/ShapeID.hpp"

// IWYU pragma: end_exports

namespace playrho {

/// @brief Body-shapes function.
using BodyShapeFunction = std::function<void(std::pair<BodyID, ShapeID>)>;

} // namespace playrho

#endif // PLAYRHO_BODYSHAPEFUNCTION_HPP
