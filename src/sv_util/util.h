/* util.h -- utility routines for useful things
 * $Id$
 */

/***********************************************************
 * Copyright 2003 libSieve Development Team by Aaron Stone
 *
 * Licensed under LPGL and CMU's "MIT style" license.
 *
 * This is an original work modelled after CMU concepts.
 * It does not contain code written by or derived from CMU.
 ***********************************************************/

#ifndef INCLUDED_UTIL_H
#define INCLUDED_UTIL_H

/* These are the memory oriented functions */
void sv_free(void *ptr);
void *sv_malloc (size_t size);
void *sv_realloc (void *ptr, size_t size);
void *sv_memset (void *ptr, int c, size_t len);

/* These are the string oriented functions */
char *sv_strtolower (char *str, size_t len);
char *sv_strtoupper (char *str, size_t len);

char *sv_strdup (const char *str, size_t len);
char *sv_strconcat (const char *str, ...);

int sv_strisatom (const char *str, size_t len);
int sv_strtonum (const char *str);

struct mlbuf {
    char *str; /* The buffer! */
    char *tmp; /* For realloc */
    size_t sz; /* Total size */
    size_t ce; /* Current ending */
    size_t cb; /* Current beginning */
};

#define FREEME 1
#define NOFREE 0

char *sv_strbuf (struct mlbuf *ml, char *str, size_t len, int freeme);
void sv_strbuffree(struct mlbuf **ml);
void sv_strbufalloc(struct mlbuf **ml);

#endif /* INCLUDED_UTIL_H */
