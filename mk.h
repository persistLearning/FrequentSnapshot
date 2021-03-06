/*
 * File:   mk.h
 * Author: mk
 *
 * Created on September 20, 2015, 8:37 PM
 */
#pragma once
#include<pthread.h>

typedef struct {
    size_t db_size;
    char *db_mk_as1;
    char *db_mk_as2;
    unsigned char *db_mk_ba;
    unsigned char *db_mk_access;
    unsigned char db_mk_lock;
    unsigned char current;
} db_mk_infomation;


int db_mk_init(void *mk_info, size_t db_size);
void *mk_read(size_t index);
int mk_write(size_t index, void* value);
void db_mk_ckp(int ckp_order, void *mk_info);
void db_mk_destroy(void *mk_info);

