/* $Id$ */
/* Copyright (c) 2006-2015 Pierre Pronchery <khorben@defora.org> */
/* This file is part of DeforaOS System libSystem */
/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. */



#ifndef LIBSYSTEM_SYSTEM_STRING_H
# define LIBSYSTEM_SYSTEM_STRING_H

# include <sys/types.h>


/* String */
/* types */
typedef char String;


/* macros */
/* XXX for compatibility */
#define string_length(a) string_get_length(a)


/* functions */
String * string_new(String const * string);
String * string_new_append(String const * string, ...);
String * string_new_format(String const * format, ...);
String * string_new_length(String const * string, size_t length);
String * string_new_replace(String const * string, String const * what,
		String const * by);
void string_delete(String * string);

/* accessors */
size_t string_get_length(String const * string);
size_t string_get_size(String const * string);

int string_set(String ** string, String const * string2);

/* useful */
int string_append(String ** string, String const * append);
void string_clear(String * string);
void string_cut(String * string, size_t length);

int string_compare(String const * string, String const * string2);
int string_compare_length(String const * string, String const * string2,
		size_t length);

String ** string_explode(String const * string, String const * separator);

String * string_find(String const * string, String const * key);
ssize_t string_index(String const * string, String const * key);

int string_replace(String ** string, String const * what, String const * by);

#endif /* !LIBSYSTEM_SYSTEM_STRING_H */
