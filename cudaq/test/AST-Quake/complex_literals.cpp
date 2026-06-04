/*******************************************************************************
 * Copyright (c) 2026 NVIDIA Corporation & Affiliates.                         *
 * All rights reserved.                                                        *
 *                                                                             *
 * This source code and the accompanying materials are made available under    *
 * the terms of the Apache License 2.0 which accompanies this distribution.    *
 ******************************************************************************/

// UNSUPPORTED: *
// RUN: cudaq-quake %s | FileCheck %s

#include <cudaq.h>

CUDAQ_REGISTER_OPERATION(unitary_3,
                         1, // Number of qubits
                         0, // Number of params
                         (std::vector<std::complex<double>>{
                             0.311740 + 0.286260i, -0.905661 + 0.025514i,
                             0.903697 + 0.064850i, 0.323887 - 0.272442i}));

// CHECK-LABEL:   func.func @__nvqpp__mlirgen__function_unitary_3_generator_1
// CHECK-DAG:       %[[CONSTANT_0:.*]] = complex.constant [3.238870e-01, 0.000000e+00] : complex<f64>
// CHECK-DAG:       %[[CONSTANT_1:.*]] = complex.constant [0.000000e+00, 2.724420e-01] : complex<f64>
// CHECK-DAG:       %[[CONSTANT_2:.*]] = complex.constant [0.90369699999999997, 0.000000e+00] : complex<f64>
// CHECK-DAG:       %[[CONSTANT_3:.*]] = complex.constant [0.000000e+00, 6.485000e-02] : complex<f64>
// CHECK-DAG:       %[[CONSTANT_4:.*]] = complex.constant [-9.056610e-01, 0.000000e+00] : complex<f64>
// CHECK-DAG:       %[[CONSTANT_5:.*]] = complex.constant [0.000000e+00, 2.551400e-02] : complex<f64>
// CHECK-DAG:       %[[CONSTANT_8:.*]] = complex.constant [0.000000e+00, 2.862600e-01] : complex<f64>
// CHECK-DAG:       %[[CONSTANT_9:.*]] = complex.constant [3.117400e-01, 0.000000e+00] : complex<f64>
// CHECK-NOT:       complex.constant
// CHECK:           %[[ADD_0:.*]] = complex.add %[[CONSTANT_9]], %[[CONSTANT_8]] : complex<f64>
// CHECK:           %[[ADD_1:.*]] = complex.add %[[CONSTANT_4]], %[[CONSTANT_5]] : complex<f64>
// CHECK:           %[[ADD_2:.*]] = complex.add %[[CONSTANT_2]], %[[CONSTANT_3]] : complex<f64>
// CHECK:           %[[SUB_0:.*]] = complex.sub %[[CONSTANT_0]], %[[CONSTANT_1]] : complex<f64>
// CHECK-NOT:       complex.add
// CHECK-NOT:       complex.sub
// CHECK:         }
