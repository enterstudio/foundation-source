/*
 * $Id: ebmlbinary.c 1319 2008-09-19 16:08:57Z robux4 $
 * Copyright (c) 2010, Matroska (non-profit organisation)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Matroska assocation nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY the Matroska association ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL The Matroska Foundation BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _EBML2_EBML_CONFIG_H
#define _EBML2_EBML_CONFIG_H

#include "corec.h"

#define LIBEBML_NAMESPACE libebml

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef uint8_t binary;

#define countof(x)  (sizeof(x)/sizeof(*(x)))

#ifdef __GNUC__
#define EBML_PRETTYLONGINT(c) (c ## ll)
#else // __GNUC__
#define EBML_PRETTYLONGINT(c) (c)
#endif // __GNUC__

namespace LIBEBML_NAMESPACE {

    enum endianess {
        big_endian,   ///< PowerPC, Alpha, 68000
        little_endian ///< x86, x64, (most) ARM, (most) MIPS
    };

    class big_int16
    {
    public:
        big_int16(int16_t);
        big_int16();
        void Fill(binary *Buffer) const;
        void Eval(const binary *Buffer);
        operator int16() const;
    private:
        int16_t Value;
    };
};

#endif // _EBML2_EBML_CONFIG_H
