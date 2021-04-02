/*
 * test_ein: vector test
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
#include <stdio.h>

#include "vector.h"

#pragma warning(disable:4996)


int main(void)
{
    vector* vc = vcalloc();
    vcpush(vc, 1);
    while (vc->len)
    {
        int ipt;
        scanf("%d", &ipt);

        int idx = vcidxo(vc, ipt);
        if (idx != -1)
            printf("RMOV, IDX %d, VAR %d\n", idx, vcrmov(vc, idx));
        else
        {
            vcpush(vc, ipt);
            printf("ISRT, NOI %d, VAR %d\n", vc->len, ipt);
        }

        printf("NOI %d\nVALUE: { ", vc->len);
        for (int i = 0; i < vc->len; i++)
            printf("%d ", vc->lst[i]);
        printf(" }\n");
    }
    return 0;
}