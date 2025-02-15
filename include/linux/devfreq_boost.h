/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2018-2019 Sultan Alsawaf <sultan@kerneltoast.com>.
 */
#ifndef _DEVFREQ_BOOST_H_
#define _DEVFREQ_BOOST_H_

#include <linux/devfreq.h>

enum df_device {
	DEVFREQ_MSM_CPUBW,
	DEVFREQ_MSM_DDRBW,
	DEVFREQ_MSM_GPUBW,
	DEVFREQ_MAX
};

#ifdef CONFIG_DEVFREQ_BOOST
void devfreq_boost_kick_flex(enum df_device device, unsigned int duration_ms);
void devfreq_boost_kick_max(enum df_device device, unsigned int duration_ms);
void devfreq_boost_kick_wake(enum df_device device, unsigned int duration_ms);
void devfreq_register_boost_device(enum df_device device, struct devfreq *df);
#else
static inline
void devfreq_boost_kick_flex(enum df_device device, unsigned int duration_ms)
{
}
static inline
void devfreq_boost_kick_max(enum df_device device, unsigned int duration_ms)
{
}
static inline
void devfreq_boost_kick_wake(enum df_device device, unsigned int duration_ms)
{
}
static inline
void devfreq_register_boost_device(enum df_device device, struct devfreq *df)
{
}
#endif

#endif /* _DEVFREQ_BOOST_H_ */
