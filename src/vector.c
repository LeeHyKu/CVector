/*
 * vector.c: vector functions
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
#include "vector.h"

/* =======[Vector Object Manager]======= */

vector *vcalloc()
{
    vector* r = (vector*)malloc(sizeof(vector));
    if(r != NULL)
    {
        r->len = 0;
        r->lst = (void**)malloc(0);
    }
    return r;
}

void vcfree(vector* vc)
{
    free(vc->lst);
    free(vc);
}

void vcresz(vector* vc, int siz)
{
    vc->len = siz;
    vc->lst = (void**)realloc(vc->lst, PTRSIZ * siz);
}

/* =======[Vector Functions]======= */

void vcpush(vector* vc, void* obj)
{
    vcresz(vc, vc->len + 1);
    vc->lst[vc->len - 1] = obj;
}

void *vcpop(vector* vc)
{
    return vcrmov(vc, vc->len - 1);
}

void *vcsift(vector* vc)
{
    return vcrmov(vc, 0);
}

void vcusft(vector* vc, void* obj)
{
    vcisrt(vc, obj, 0);
}

void *vcrmov(vector* vc, int idx)
{
    if(idx >= vc->len || idx < 0) return NULL;
    void *r = vc->lst[idx];
    for(int i = idx + 1; i < vc->len; i++)
        vc->lst[i - 1] = vc->lst[i];
    vcresz(vc, vc->len - 1);
    return r;
}

int vcisrt(vector* vc, void* obj, int idx)
{
    if(idx < 0) return 0;
    if(vc->len)
    {
        vcresz(vc, vc->len + 1);
        for(int i = vc->len; i > idx; i--)
            vc->lst[i] = vc->lst[i - 1];
    }
    else vcpush(vc, obj);
    return 1;
}

int vcidxo(vector* vc, void* obj)
{
    for(int i = 0; i < vc->len; i++)
        if(vc->lst[i] == obj)
            return i;
    return -1;
}

void vcadds(vector* zu, vector* von)
{
    int ori = zu->len;
    vcresz(zu, zu->len + von->len);
    for(int i = 0; i < zu->len; i++)
        zu->lst[i + ori] = von->lst[i];
}

vector *vccmpr(vector* ein, vector* zwi)
{
    vector *r = vcaloc();
    vcadds(r, ein);
    vcadds(r, zwi);
    return r;
}