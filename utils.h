/*
  Plastic Logic EPD project on MSP430

  Copyright (C) 2013 Plastic Logic Limited

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef INCLUDE_UTIL_H
#define INCLUDE_UTIL_H 1

#include "types.h"
#include "FatFs/ff.h"
#include <stdint.h>

#ifdef LOG_TAG
#define LOG(msg, ...) \
	do { printf("%-8s: "msg"\n", LOG_TAG, ##__VA_ARGS__); } while (0)
#else
#define LOG(msg, ...)
#endif

/* -- Lightweight string parser -- */

/** Return the offset of the first occurence of any sep characters in str if
 * skip=0, or the first occurence of any character not in sep if skip=1 */
extern int parser_find_str(const char *str, const char *sep, int skip);

/** Copy the current string until the next separator in out and return the
 * offset to the next string, 0 if last and -1 if error */
extern int parser_read_str(const char *str, const char *sep, char *out,
			   int out_len);

/** Same as parser_read_str but convert the string to an integer */
extern int parser_read_int(const char *str, const char *sep, int *out);

/** Read a series of integers at the given addresses */
extern int parser_read_int_list(const char *str, const char *sep, int **list);

/** Read area coordinates (left, top, width, height) */
extern int parser_read_area(const char *str, const char *sep, struct area *a);

/** Read one line worth of data from a text file */
extern int parser_read_file_line(FIL *f, char *buffer, int max_length);

#endif /* INCLUDE_UTIL_H */
