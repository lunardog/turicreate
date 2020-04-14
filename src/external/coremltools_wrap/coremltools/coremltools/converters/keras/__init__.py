# Copyright (c) 2017, Apple Inc. All rights reserved.
#
# Use of this source code is governed by a BSD-3-clause license that can be
# found in the LICENSE.txt file or at https://opensource.org/licenses/BSD-3-Clause

from ..._deps import HAS_KERAS_TF as _HAS_KERAS_TF
from ..._deps import HAS_KERAS2_TF as _HAS_KERAS2_TF

if _HAS_KERAS_TF or _HAS_KERAS2_TF:
    import keras as _keras
    import logging as _logging
    from ._keras_converter import convert, convertToSpec
    if _keras.backend.backend() != 'tensorflow':
        _HAS_KERAS_TF = False
        _HAS_KERAS2_TF = False
        _logging.warn('Currently, only Keras models with TensorFlow backend can be converted to CoreML.')

# if _HAS_KERAS_TF:
#     from ._keras_converter import convert
#
# if _HAS_KERAS2_TF:
#     from ._keras2_converter import convert
