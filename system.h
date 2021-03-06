#pragma once
#include "util.h"
#include "naive.h"
#include "cou.h"
#include "zigzag.h"
#include "pingpong.h"
#include "mk.h"
#include "LL.h"
#include "myfork.h"
typedef struct {
    int algType;
    size_t dbSize;
    int unitSize;
    struct timespec ckpTimeLog[2000];
    long long *ckpOverheadLog;
    long long *ckpPrepareLog;
    long long *ckpTotalOverheadLog;
    int ckpMaxNum;
    int ckpID;
    int dbState;
    int updateThrNum;
    int updateFrequency;
    long long  globaltick;
    long *rfBuf;
    int rfBufSize;
    pthread_mutex_t dbStateRWLock;
    pthread_mutex_t accessMutex;
    pthread_spinlock_t presync;
	unsigned char  pre_lock;
    db_naive_infomation naiveInfo;
    db_cou_infomation couInfo;
    db_zigzag_infomation zigzagInfo;
    db_pingpong_infomation pingpongInfo;
    db_mk_infomation mkInfo;
    db_ll_infomation llInfo;
	db_myfork_infomation myforkInfo;
    long long update_count;
    long long dbStartTime;
    long long dbEndTime;
} db_server;

//void log_time_write(db_server *s);
void add_overhead_log(db_server *s,long long ns);
void write_overhead_log(db_server *s,const char *filePath);
void add_prepare_log(db_server *s,long long ns);
void add_total_log(db_server *s,long long ns);

///////////////////////////////////////////////////////////////

typedef struct {
    size_t db_size;
    int alg_type;
    long *random_buffer;
    int random_buffer_size;
    pthread_barrier_t *update_brr_init;
    pthread_barrier_t *brr_exit;
    int pthread_id;
    int update_frequency;
}update_thread_info;

void *update_thread(void *arg);
int update_thread_start(pthread_t *update_thread_id_array[],pthread_barrier_t *brr_exit,db_server *dbs);
int random_update_db( long *random_buf,int buf_size,char *log_name,int uf);
int tick_update(long *random_buf, int buf_size, int times, FILE *logFile, int tick);
void* (*db_read)(size_t index);
int (*db_write)(size_t index, void* value);

///////////////////////////////////////////////////////////////

typedef struct {
    size_t dbSize;
    int algType;
    pthread_barrier_t *ckpInitBrr;
    pthread_barrier_t *ckpExitBrr;
} db_thread_info;

void *database_thread(void *arg);
int db_thread_start(pthread_t *db_thread_id, pthread_barrier_t *brr_exit, db_server *dbs);

