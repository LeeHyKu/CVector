/*
 * env.h: Declare constants that vary by environment
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
#ifndef ENV_H
#define ENV_H
#if _WIN64
	#define ENV64BIT
#elif _WIN32
    #define ENV32BIT
#elif __GNUC__
	#if __x86_64__ || __ppc64__ || __aarch64__
		#define ENV64BIT
	#else
		#define ENV32BIT
    #endif
#endif

#ifdef ENV64BIT
    #define PTRSIZ 8
#elif defined ENV32BIT
    #define PTRSIZ 4
#endif
#endif