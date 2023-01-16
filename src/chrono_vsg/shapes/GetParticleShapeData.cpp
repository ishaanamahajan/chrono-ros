// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2022 projectchrono.org
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Rainer Gericke
// =============================================================================

#include "chrono_vsg/shapes/GetParticleShapeData.h"

namespace chrono {
namespace vsg3d {

void GetParticleShapeData(vsg::ref_ptr<vsg::vec3Array>& vertices,
                          vsg::ref_ptr<vsg::vec3Array>& normals,
                          vsg::ref_ptr<vsg::vec2Array>& texcoords,
                          vsg::ref_ptr<vsg::ushortArray>& indices,
                          float& boundingSphereRadius) {
    vertices = vsg::vec3Array::create({{0, 0, 1},
                                       {0.5, 0, 0.866025},
                                       {0.866025, 0, 0.5},
                                       {1, 0, 6.12323e-17},
                                       {0.866025, 0, -0.5},
                                       {0.5, 0, -0.866025},
                                       {1.22465e-16, 0, -1},
                                       {0, 0, 1},
                                       {0.433013, 0.25, 0.866025},
                                       {0.75, 0.433013, 0.5},
                                       {0.866025, 0.5, 6.12323e-17},
                                       {0.75, 0.433013, -0.5},
                                       {0.433013, 0.25, -0.866025},
                                       {1.06058e-16, 6.12323e-17, -1},
                                       {0, 0, 1},
                                       {0.25, 0.433013, 0.866025},
                                       {0.433013, 0.75, 0.5},
                                       {0.5, 0.866025, 6.12323e-17},
                                       {0.433013, 0.75, -0.5},
                                       {0.25, 0.433013, -0.866025},
                                       {6.12323e-17, 1.06058e-16, -1},
                                       {0, 0, 1},
                                       {3.06162e-17, 0.5, 0.866025},
                                       {5.30288e-17, 0.866025, 0.5},
                                       {6.12323e-17, 1, 6.12323e-17},
                                       {5.30288e-17, 0.866025, -0.5},
                                       {3.06162e-17, 0.5, -0.866025},
                                       {7.4988e-33, 1.22465e-16, -1},
                                       {-0, 0, 1},
                                       {-0.25, 0.433013, 0.866025},
                                       {-0.433013, 0.75, 0.5},
                                       {-0.5, 0.866025, 6.12323e-17},
                                       {-0.433013, 0.75, -0.5},
                                       {-0.25, 0.433013, -0.866025},
                                       {-6.12323e-17, 1.06058e-16, -1},
                                       {-0, 0, 1},
                                       {-0.433013, 0.25, 0.866025},
                                       {-0.75, 0.433013, 0.5},
                                       {-0.866025, 0.5, 6.12323e-17},
                                       {-0.75, 0.433013, -0.5},
                                       {-0.433013, 0.25, -0.866025},
                                       {-1.06058e-16, 6.12323e-17, -1},
                                       {-0, 0, 1},
                                       {-0.5, 6.12323e-17, 0.866025},
                                       {-0.866025, 1.06058e-16, 0.5},
                                       {-1, 1.22465e-16, 6.12323e-17},
                                       {-0.866025, 1.06058e-16, -0.5},
                                       {-0.5, 6.12323e-17, -0.866025},
                                       {-1.22465e-16, 1.49976e-32, -1},
                                       {-0, -0, 1},
                                       {-0.433013, -0.25, 0.866025},
                                       {-0.75, -0.433013, 0.5},
                                       {-0.866025, -0.5, 6.12323e-17},
                                       {-0.75, -0.433013, -0.5},
                                       {-0.433013, -0.25, -0.866025},
                                       {-1.06058e-16, -6.12323e-17, -1},
                                       {-0, -0, 1},
                                       {-0.25, -0.433013, 0.866025},
                                       {-0.433013, -0.75, 0.5},
                                       {-0.5, -0.866025, 6.12323e-17},
                                       {-0.433013, -0.75, -0.5},
                                       {-0.25, -0.433013, -0.866025},
                                       {-6.12323e-17, -1.06058e-16, -1},
                                       {-0, -0, 1},
                                       {-9.18485e-17, -0.5, 0.866025},
                                       {-1.59086e-16, -0.866025, 0.5},
                                       {-1.83697e-16, -1, 6.12323e-17},
                                       {-1.59086e-16, -0.866025, -0.5},
                                       {-9.18485e-17, -0.5, -0.866025},
                                       {-2.24964e-32, -1.22465e-16, -1},
                                       {0, -0, 1},
                                       {0.25, -0.433013, 0.866025},
                                       {0.433013, -0.75, 0.5},
                                       {0.5, -0.866025, 6.12323e-17},
                                       {0.433013, -0.75, -0.5},
                                       {0.25, -0.433013, -0.866025},
                                       {6.12323e-17, -1.06058e-16, -1},
                                       {0, -0, 1},
                                       {0.433013, -0.25, 0.866025},
                                       {0.75, -0.433013, 0.5},
                                       {0.866025, -0.5, 6.12323e-17},
                                       {0.75, -0.433013, -0.5},
                                       {0.433013, -0.25, -0.866025},
                                       {1.06058e-16, -6.12323e-17, -1},
                                       {0, -0, 1},
                                       {0.5, -1.22465e-16, 0.866025},
                                       {0.866025, -2.12115e-16, 0.5},
                                       {1, -2.44929e-16, 6.12323e-17},
                                       {0.866025, -2.12115e-16, -0.5},
                                       {0.5, -1.22465e-16, -0.866025},
                                       {1.22465e-16, -2.99952e-32, -1}});

    normals = vsg::vec3Array::create({{0, 0, 1},
                                      {0.5, 0, 0.866025},
                                      {0.866025, 0, 0.5},
                                      {1, 0, 6.12323e-17},
                                      {0.866025, 0, -0.5},
                                      {0.5, 0, -0.866025},
                                      {1.22465e-16, 0, -1},
                                      {0, 0, 1},
                                      {0.433013, 0.25, 0.866025},
                                      {0.75, 0.433013, 0.5},
                                      {0.866025, 0.5, 6.12323e-17},
                                      {0.75, 0.433013, -0.5},
                                      {0.433013, 0.25, -0.866025},
                                      {1.06058e-16, 6.12323e-17, -1},
                                      {0, 0, 1},
                                      {0.25, 0.433013, 0.866025},
                                      {0.433013, 0.75, 0.5},
                                      {0.5, 0.866025, 6.12323e-17},
                                      {0.433013, 0.75, -0.5},
                                      {0.25, 0.433013, -0.866025},
                                      {6.12323e-17, 1.06058e-16, -1},
                                      {0, 0, 1},
                                      {3.06162e-17, 0.5, 0.866025},
                                      {5.30288e-17, 0.866025, 0.5},
                                      {6.12323e-17, 1, 6.12323e-17},
                                      {5.30288e-17, 0.866025, -0.5},
                                      {3.06162e-17, 0.5, -0.866025},
                                      {7.4988e-33, 1.22465e-16, -1},
                                      {-0, 0, 1},
                                      {-0.25, 0.433013, 0.866025},
                                      {-0.433013, 0.75, 0.5},
                                      {-0.5, 0.866025, 6.12323e-17},
                                      {-0.433013, 0.75, -0.5},
                                      {-0.25, 0.433013, -0.866025},
                                      {-6.12323e-17, 1.06058e-16, -1},
                                      {-0, 0, 1},
                                      {-0.433013, 0.25, 0.866025},
                                      {-0.75, 0.433013, 0.5},
                                      {-0.866025, 0.5, 6.12323e-17},
                                      {-0.75, 0.433013, -0.5},
                                      {-0.433013, 0.25, -0.866025},
                                      {-1.06058e-16, 6.12323e-17, -1},
                                      {-0, 0, 1},
                                      {-0.5, 6.12323e-17, 0.866025},
                                      {-0.866025, 1.06058e-16, 0.5},
                                      {-1, 1.22465e-16, 6.12323e-17},
                                      {-0.866025, 1.06058e-16, -0.5},
                                      {-0.5, 6.12323e-17, -0.866025},
                                      {-1.22465e-16, 1.49976e-32, -1},
                                      {-0, -0, 1},
                                      {-0.433013, -0.25, 0.866025},
                                      {-0.75, -0.433013, 0.5},
                                      {-0.866025, -0.5, 6.12323e-17},
                                      {-0.75, -0.433013, -0.5},
                                      {-0.433013, -0.25, -0.866025},
                                      {-1.06058e-16, -6.12323e-17, -1},
                                      {-0, -0, 1},
                                      {-0.25, -0.433013, 0.866025},
                                      {-0.433013, -0.75, 0.5},
                                      {-0.5, -0.866025, 6.12323e-17},
                                      {-0.433013, -0.75, -0.5},
                                      {-0.25, -0.433013, -0.866025},
                                      {-6.12323e-17, -1.06058e-16, -1},
                                      {-0, -0, 1},
                                      {-9.18485e-17, -0.5, 0.866025},
                                      {-1.59086e-16, -0.866025, 0.5},
                                      {-1.83697e-16, -1, 6.12323e-17},
                                      {-1.59086e-16, -0.866025, -0.5},
                                      {-9.18485e-17, -0.5, -0.866025},
                                      {-2.24964e-32, -1.22465e-16, -1},
                                      {0, -0, 1},
                                      {0.25, -0.433013, 0.866025},
                                      {0.433013, -0.75, 0.5},
                                      {0.5, -0.866025, 6.12323e-17},
                                      {0.433013, -0.75, -0.5},
                                      {0.25, -0.433013, -0.866025},
                                      {6.12323e-17, -1.06058e-16, -1},
                                      {0, -0, 1},
                                      {0.433013, -0.25, 0.866025},
                                      {0.75, -0.433013, 0.5},
                                      {0.866025, -0.5, 6.12323e-17},
                                      {0.75, -0.433013, -0.5},
                                      {0.433013, -0.25, -0.866025},
                                      {1.06058e-16, -6.12323e-17, -1},
                                      {0, -0, 1},
                                      {0.5, -1.22465e-16, 0.866025},
                                      {0.866025, -2.12115e-16, 0.5},
                                      {1, -2.44929e-16, 6.12323e-17},
                                      {0.866025, -2.12115e-16, -0.5},
                                      {0.5, -1.22465e-16, -0.866025},
                                      {1.22465e-16, -2.99952e-32, -1}});

    texcoords = vsg::vec2Array::create({{1, 0},
                                        {1, 0.166667},
                                        {1, 0.333333},
                                        {1, 0.5},
                                        {1, 0.666667},
                                        {1, 0.833333},
                                        {1, 1},
                                        {0.916667, 0},
                                        {0.916667, 0.166667},
                                        {0.916667, 0.333333},
                                        {0.916667, 0.5},
                                        {0.916667, 0.666667},
                                        {0.916667, 0.833333},
                                        {0.916667, 1},
                                        {0.833333, 0},
                                        {0.833333, 0.166667},
                                        {0.833333, 0.333333},
                                        {0.833333, 0.5},
                                        {0.833333, 0.666667},
                                        {0.833333, 0.833333},
                                        {0.833333, 1},
                                        {0.75, 0},
                                        {0.75, 0.166667},
                                        {0.75, 0.333333},
                                        {0.75, 0.5},
                                        {0.75, 0.666667},
                                        {0.75, 0.833333},
                                        {0.75, 1},
                                        {0.666667, 0},
                                        {0.666667, 0.166667},
                                        {0.666667, 0.333333},
                                        {0.666667, 0.5},
                                        {0.666667, 0.666667},
                                        {0.666667, 0.833333},
                                        {0.666667, 1},
                                        {0.583333, 0},
                                        {0.583333, 0.166667},
                                        {0.583333, 0.333333},
                                        {0.583333, 0.5},
                                        {0.583333, 0.666667},
                                        {0.583333, 0.833333},
                                        {0.583333, 1},
                                        {0.5, 0},
                                        {0.5, 0.166667},
                                        {0.5, 0.333333},
                                        {0.5, 0.5},
                                        {0.5, 0.666667},
                                        {0.5, 0.833333},
                                        {0.5, 1},
                                        {0.416667, 0},
                                        {0.416667, 0.166667},
                                        {0.416667, 0.333333},
                                        {0.416667, 0.5},
                                        {0.416667, 0.666667},
                                        {0.416667, 0.833333},
                                        {0.416667, 1},
                                        {0.333333, 0},
                                        {0.333333, 0.166667},
                                        {0.333333, 0.333333},
                                        {0.333333, 0.5},
                                        {0.333333, 0.666667},
                                        {0.333333, 0.833333},
                                        {0.333333, 1},
                                        {0.25, 0},
                                        {0.25, 0.166667},
                                        {0.25, 0.333333},
                                        {0.25, 0.5},
                                        {0.25, 0.666667},
                                        {0.25, 0.833333},
                                        {0.25, 1},
                                        {0.166667, 0},
                                        {0.166667, 0.166667},
                                        {0.166667, 0.333333},
                                        {0.166667, 0.5},
                                        {0.166667, 0.666667},
                                        {0.166667, 0.833333},
                                        {0.166667, 1},
                                        {0.0833333, 0},
                                        {0.0833333, 0.166667},
                                        {0.0833333, 0.333333},
                                        {0.0833333, 0.5},
                                        {0.0833333, 0.666667},
                                        {0.0833333, 0.833333},
                                        {0.0833333, 1},
                                        {0, 0},
                                        {0, 0.166667},
                                        {0, 0.333333},
                                        {0, 0.5},
                                        {0, 0.666667},
                                        {0, 0.833333},
                                        {0, 1}});

    indices = vsg::ushortArray::create(
        {0,  1,  8,  1,  2,  9,  2,  3,  10, 3,  4,  11, 4,  5,  12, 5,  6,  13, 1,  9,  8,  2,  10, 9,  3,  11, 10,
         4,  12, 11, 5,  13, 12, 7,  8,  15, 8,  9,  16, 9,  10, 17, 10, 11, 18, 11, 12, 19, 12, 13, 20, 8,  16, 15,
         9,  17, 16, 10, 18, 17, 11, 19, 18, 12, 20, 19, 14, 15, 22, 15, 16, 23, 16, 17, 24, 17, 18, 25, 18, 19, 26,
         19, 20, 27, 15, 23, 22, 16, 24, 23, 17, 25, 24, 18, 26, 25, 19, 27, 26, 21, 22, 29, 22, 23, 30, 23, 24, 31,
         24, 25, 32, 25, 26, 33, 26, 27, 34, 22, 30, 29, 23, 31, 30, 24, 32, 31, 25, 33, 32, 26, 34, 33, 28, 29, 36,
         29, 30, 37, 30, 31, 38, 31, 32, 39, 32, 33, 40, 33, 34, 41, 29, 37, 36, 30, 38, 37, 31, 39, 38, 32, 40, 39,
         33, 41, 40, 35, 36, 43, 36, 37, 44, 37, 38, 45, 38, 39, 46, 39, 40, 47, 40, 41, 48, 36, 44, 43, 37, 45, 44,
         38, 46, 45, 39, 47, 46, 40, 48, 47, 42, 43, 50, 43, 44, 51, 44, 45, 52, 45, 46, 53, 46, 47, 54, 47, 48, 55,
         43, 51, 50, 44, 52, 51, 45, 53, 52, 46, 54, 53, 47, 55, 54, 49, 50, 57, 50, 51, 58, 51, 52, 59, 52, 53, 60,
         53, 54, 61, 54, 55, 62, 50, 58, 57, 51, 59, 58, 52, 60, 59, 53, 61, 60, 54, 62, 61, 56, 57, 64, 57, 58, 65,
         58, 59, 66, 59, 60, 67, 60, 61, 68, 61, 62, 69, 57, 65, 64, 58, 66, 65, 59, 67, 66, 60, 68, 67, 61, 69, 68,
         63, 64, 71, 64, 65, 72, 65, 66, 73, 66, 67, 74, 67, 68, 75, 68, 69, 76, 64, 72, 71, 65, 73, 72, 66, 74, 73,
         67, 75, 74, 68, 76, 75, 70, 71, 78, 71, 72, 79, 72, 73, 80, 73, 74, 81, 74, 75, 82, 75, 76, 83, 71, 79, 78,
         72, 80, 79, 73, 81, 80, 74, 82, 81, 75, 83, 82, 77, 78, 85, 78, 79, 86, 79, 80, 87, 80, 81, 88, 81, 82, 89,
         82, 83, 90, 78, 86, 85, 79, 87, 86, 80, 88, 87, 81, 89, 88, 82, 90, 89});

    // bounding sphere radius > 1.0
    boundingSphereRadius = 1.1f;
}

}  // namespace vsg3d
}  // namespace chrono