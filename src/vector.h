/*
 * vector.h: declare vector
 * 
 * Copyright (C) 2021 Hyun-Ku Lee
 *
 * This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>

#include "env.h"

/* =======[Vector Struct Definition]======= */

/**
 * vector, Dynamic array
 */
typedef struct vector
{
    void**  lst;
    int     len;
} vector;

/* =======[Vector Object Manager]======= */

/**
 * allocate vector
 */
vector     *vcaloc();
/**
 * delocate vector
 */
void        vcfree(vector* vc);
/**
 * resize vector
 */ 
void        vcresz(vector* vc, int siz);

/* =======[Vector Functions]======= */

/**
 * push object to vector
 * PARAMETER 'obj' MUST BE POINTER VALUE OR
 *  SIZEOF(obj) <= PTRSIZ(in 'env.h'; x64 -> 8, x86 -> 4)
 */
void        vcpush(vector* vc, void* obj);
/**
 * pop vector
 */
void       *vcpop (vector* vc);
/**
 * shift vector
 */
void       *vcsift(vector* vc);
/**
 * unshift vector
 * PARAMETER 'obj' MUST BE POINTER VALUE OR
 *  SIZEOF(obj) <= PTRSIZ(in 'env.h'; x64 -> 8, x86 -> 4)
 */
void        vcusft(vector* vc, void* obj);
/**
 * remove object from vector by index, and return it
 */
void       *vcrmov(vector* vc, int idx);
/**
 * insert object to vector at index
 * PARAMETER 'obj' MUST BE POINTER VALUE OR
 *  SIZEOF(obj) <= PTRSIZ(in 'env.h'; x64 -> 8, x86 -> 4)
 */
int         vcisrt(vector* vc, void* obj, int idx);
/**
 * find index of variable
 */
int         vcidxo(vector* vc, void* obj);
/**
 * add object in vector 'von' to vector 'zu'
 */
void        vcadds(vector* zu, vector* von);
/**
 * compare two vector, create new vector
 */
vector     *vcccmpr(vector* ein, vector* zwi);
#endif