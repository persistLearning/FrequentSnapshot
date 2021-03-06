#pragma once
#define UNLOCK  0
#define LOCK    -1

#define NAIVE_ALG           0
#define COPY_ON_UPDATE_ALG  1
#define ZIGZAG_ALG          2
#define PINGPONG_ALG        3
#define MK_ALG              4
#define LL_ALG              5
#define MYFORK_ALG           6

#include <stdio.h>
#include<sys/mman.h>
#include <sys/wait.h>
#include<fcntl.h>
#include <time.h>
#include <numa.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

#define __USE_GNU
#include <sched.h>
#include <pthread.h>

long long get_ntime(void);
long long get_utime(void);
long long get_mtime(void);

int randomfile_init(FILE *rf,long *rbuf,long long rbufSize);

void db_lock(unsigned char *lock);
void db_unlock(unsigned char *lock);
int pin_To_vCPU(int cpu);

void writeLarge(int fd, const void *mem, size_t count,size_t block);
