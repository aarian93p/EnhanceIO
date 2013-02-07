/*
 *  eio_setlru.h
 *
 *  Copyright (C) 2012 STEC, Inc. All rights not specifically granted
 *   under a license included herein are reserved
 *  Amit Kale <akale@stec-inc.com>
 *  Harish Pujari <hpujari@stec-inc.com>
 *   Generic lru implementation used mainly for cache sets
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; under version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 */

#ifndef _EIO_SETLRU_H_
#define _EIO_SETLRU_H_

#define         LRU_NULL        -1

typedef struct lru_elem {
	index_t le_next;
	index_t le_prev;
	u_int64_t le_key;
} lru_elem_t;

typedef struct lru_ls {
	index_t ll_head;
	index_t ll_tail;
	index_t ll_max;
	u_int64_t ll_size;
	lru_elem_t ll_elem[1];
} lru_list_t;

int lru_init(lru_list_t **llist, index_t max);
void lru_uninit(lru_list_t *llist);
int lru_add(lru_list_t *llist, index_t index, u_int64_t key);
int lru_rem(lru_list_t *llist, index_t index);
int lru_touch(lru_list_t *llist, index_t index, u_int64_t key);
int lru_read_head(lru_list_t *llist, index_t *index, u_int64_t *key);
int lru_rem_head(lru_list_t *llist, index_t *index, u_int64_t *key);

#endif                          /* _EIO_SETLRU_H_ */
