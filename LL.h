/*
 * File:   LL.h
 * Author: mk
 *
 * Created on October 21, 2015, 9:31 AM
 */

#pragma once
#include<pthread.h>

typedef struct {
    size_t db_size;
    char *db_ll_as0;
    char *db_ll_as1;
    char *db_ll_prev;
    unsigned char *db_ll_as0_ba;
    unsigned char *db_ll_as1_ba;
    unsigned char *db_ll_mr_ba;
    unsigned char db_ll_lock;
    int current;

} db_ll_infomation;

int db_ll_init(void *ll_info, size_t db_size);
void *ll_read(size_t index);
int ll_write(size_t index, void *value);
void db_ll_ckp(int ckp_id, void *ll_info);
void db_ll_destroy(void *ll_info);

