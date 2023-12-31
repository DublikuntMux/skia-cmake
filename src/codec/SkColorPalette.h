/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkColorPalette_DEFINED
#define SkColorPalette_DEFINED

#include "include/core/SkColor.h"
#include "include/core/SkRefCnt.h"
#include "include/core/SkTypes.h"

/** \class SkColorPalette

    SkColorPalette holds an array of SkPMColors (premultiplied 32-bit colors) used by
    8-bit bitmaps, where the bitmap bytes are interpreted as indices into the colortable.

    SkColorPalette is thread-safe.
*/
class SkColorPalette : public SkRefCnt {
public:
    /** Copy up to 256 colors into a new SkColorPalette.
     */
    SkColorPalette(const SkPMColor colors[], int count);
    ~SkColorPalette() override;

    /** Returns the number of colors in the table.
     */
    int count() const { return fCount; }

    /** Returns the specified color from the table. In the debug build, this asserts that
     *  the index is in range (0 <= index < count).
     */
    SkPMColor operator[](int index) const {
        SkASSERT(fColors != nullptr && (unsigned)index < (unsigned)fCount);
        return fColors[index];
    }

    /** Return the array of colors for reading. */
    const SkPMColor* readColors() const { return fColors; }

private:
    SkPMColor*  fColors;
    int         fCount;

    using INHERITED = SkRefCnt;
};

#endif
