/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright 2025-2026 AxionOS
 */

#ifndef _AX_DRAGONITE_H_
#define _AX_DRAGONITE_H_

#include <linux/types.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/sched/task.h>
#include <linux/cpumask.h>

#define AXD_NAME "ax_dragonite"
#define AXD_VERSION "1.0.0"

#define AX_COMM_LEN 16
#define AXD_MAX_COMM_LEN 16
#define AXD_MAX_THREAD_GROUP_TASKS 512
#define AXD_MAX_KSWAPD_TASKS 32

#define AXD_NICE_BOOST -20
#define AXD_NICE_NORMAL 0
#define AXD_KSWAPD_COMM_PREFIX "kswapd"
#define AXD_KSWAPD_COMM_LEN 6
#define AXD_MATCH_ALL_COMM '*'
#define AXD_INVALID_PID 0

#define AXD_PROC_NTA_DIR "ax_named_thread_affinity"
#define AXD_PROC_DRAGONITE_DIR "ax_dragonite"
#define AXD_PROC_PID "pid"
#define AXD_PROC_NTA "named_thread_affinity"
#define AXD_PROC_RESET "reset"
#define AXD_PROC_BOOST "boost"
#define AXD_PROC_KSWAPD_PIN "kswapd_pin"
#define AXD_PROC_STATS "stats"

#define AXD_MAX_KBUF_PID 32
#define AXD_MAX_KBUF_AFFINITY 256
#define AXD_MAX_KBUF_BOOST 64
#define AXD_MAX_KBUF_KSWAPD 32
#define AXD_RADIX_DEC 10
#define AXD_RADIX_HEX 16
#define AXD_DEFAULT_BOOST_LEVEL 1

struct axd_stats {
    atomic64_t affinity_set_count;
    atomic64_t boost_set_count;
    atomic64_t reset_count;
    atomic64_t kswapd_pin_count;
};

extern struct axd_stats g_axd_stats;

int axd_set_affinity(pid_t pid, const char *comm_name, const struct cpumask *mask);
int axd_reset_affinity(pid_t pid);
int axd_set_boost(pid_t pid, int boost_level);
int axd_pin_kswapd(const struct cpumask *mask);

int axd_proc_init(void);
void axd_proc_exit(void);

#endif
