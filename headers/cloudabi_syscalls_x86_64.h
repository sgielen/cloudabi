// Copyright (c) 2016 Nuxi (https://nuxi.nl/) and contributors.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

// This file is automatically generated. Do not edit.
// Source: https://github.com/NuxiNL/cloudabi

#ifndef CLOUDABI_SYSCALLS_X86_64_H
#define CLOUDABI_SYSCALLS_X86_64_H

#include "cloudabi_types.h"

static inline cloudabi_errno_t
cloudabi_sys_clock_res_get(
	cloudabi_clockid_t clock_id,
	cloudabi_timestamp_t *resolution
) {
	register uint64_t reg_rax asm("rax") = 0;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)clock_id;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*resolution = (cloudabi_timestamp_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_clock_time_get(
	cloudabi_clockid_t clock_id,
	cloudabi_timestamp_t precision,
	cloudabi_timestamp_t *time
) {
	register uint64_t reg_rax asm("rax") = 1;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)clock_id;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)precision;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*time = (cloudabi_timestamp_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_condvar_signal(
	_Atomic(cloudabi_condvar_t) *condvar,
	cloudabi_mflags_t scope,
	cloudabi_nthreads_t nwaiters
) {
	register uint64_t reg_rax asm("rax") = 2;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)condvar;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)scope;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)nwaiters;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_close(
	cloudabi_fd_t fd
) {
	register uint64_t reg_rax asm("rax") = 3;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_create1(
	cloudabi_filetype_t type,
	cloudabi_fd_t *fd
) {
	register uint64_t reg_rax asm("rax") = 4;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)type;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*fd = (cloudabi_fd_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_create2(
	cloudabi_filetype_t type,
	cloudabi_fd_t *fd1,
	cloudabi_fd_t *fd2
) {
	register uint64_t reg_rax asm("rax") = 5;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)type;
	register uint64_t reg_rdx asm("rdx");
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		, "=r"(reg_rdx)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*fd1 = (cloudabi_fd_t)reg_rax;
		*fd2 = (cloudabi_fd_t)reg_rdx;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_datasync(
	cloudabi_fd_t fd
) {
	register uint64_t reg_rax asm("rax") = 6;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_dup(
	cloudabi_fd_t from,
	cloudabi_fd_t *fd
) {
	register uint64_t reg_rax asm("rax") = 7;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)from;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*fd = (cloudabi_fd_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_pread(
	cloudabi_fd_t fd,
	const cloudabi_iovec_t *iov,
	size_t iovcnt,
	cloudabi_filesize_t offset,
	size_t *nread
) {
	register uint64_t reg_rax asm("rax") = 8;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)iov;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)iovcnt;
	register uint64_t reg_r10 asm("r10") = (uint64_t)offset;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*nread = (size_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_pwrite(
	cloudabi_fd_t fd,
	const cloudabi_ciovec_t *iov,
	size_t iovcnt,
	cloudabi_filesize_t offset,
	size_t *nwritten
) {
	register uint64_t reg_rax asm("rax") = 9;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)iov;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)iovcnt;
	register uint64_t reg_r10 asm("r10") = (uint64_t)offset;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*nwritten = (size_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_read(
	cloudabi_fd_t fd,
	const cloudabi_iovec_t *iov,
	size_t iovcnt,
	size_t *nread
) {
	register uint64_t reg_rax asm("rax") = 10;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)iov;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)iovcnt;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*nread = (size_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_replace(
	cloudabi_fd_t from,
	cloudabi_fd_t to
) {
	register uint64_t reg_rax asm("rax") = 11;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)from;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)to;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_seek(
	cloudabi_fd_t fd,
	cloudabi_filedelta_t offset,
	cloudabi_whence_t whence,
	cloudabi_filesize_t *newoffset
) {
	register uint64_t reg_rax asm("rax") = 12;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)offset;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)whence;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*newoffset = (cloudabi_filesize_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_stat_get(
	cloudabi_fd_t fd,
	cloudabi_fdstat_t *buf
) {
	register uint64_t reg_rax asm("rax") = 13;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)buf;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_stat_put(
	cloudabi_fd_t fd,
	const cloudabi_fdstat_t *buf,
	cloudabi_fdsflags_t flags
) {
	register uint64_t reg_rax asm("rax") = 14;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)buf;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)flags;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_sync(
	cloudabi_fd_t fd
) {
	register uint64_t reg_rax asm("rax") = 15;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_fd_write(
	cloudabi_fd_t fd,
	const cloudabi_ciovec_t *iov,
	size_t iovcnt,
	size_t *nwritten
) {
	register uint64_t reg_rax asm("rax") = 16;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)iov;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)iovcnt;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*nwritten = (size_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_advise(
	cloudabi_fd_t fd,
	cloudabi_filesize_t offset,
	cloudabi_filesize_t len,
	cloudabi_advice_t advice
) {
	register uint64_t reg_rax asm("rax") = 17;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)offset;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)len;
	register uint64_t reg_r10 asm("r10") = (uint64_t)advice;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_allocate(
	cloudabi_fd_t fd,
	cloudabi_filesize_t offset,
	cloudabi_filesize_t len
) {
	register uint64_t reg_rax asm("rax") = 18;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)offset;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)len;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_create(
	cloudabi_fd_t fd,
	const char *path,
	size_t pathlen,
	cloudabi_filetype_t type
) {
	register uint64_t reg_rax asm("rax") = 19;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)path;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)pathlen;
	register uint64_t reg_r10 asm("r10") = (uint64_t)type;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_link(
	cloudabi_lookup_t fd1,
	const char *path1,
	size_t path1len,
	cloudabi_fd_t fd2,
	const char *path2,
	size_t path2len
) {
	register uint64_t reg_rax asm("rax") = 20;
	register uint64_t reg_rdi asm("rdi") = *(uint64_t *)&fd1;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)path1;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)path1len;
	register uint64_t reg_r10 asm("r10") = (uint64_t)fd2;
	register uint64_t reg_r8 asm("r8") = (uint64_t)path2;
	register uint64_t reg_r9 asm("r9") = (uint64_t)path2len;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		, "r"(reg_r8)
		, "r"(reg_r9)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_open(
	cloudabi_lookup_t dirfd,
	const char *path,
	size_t pathlen,
	cloudabi_oflags_t oflags,
	const cloudabi_fdstat_t *fds,
	cloudabi_fd_t *fd
) {
	register uint64_t reg_rax asm("rax") = 21;
	register uint64_t reg_rdi asm("rdi") = *(uint64_t *)&dirfd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)path;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)pathlen;
	register uint64_t reg_r10 asm("r10") = (uint64_t)oflags;
	register uint64_t reg_r8 asm("r8") = (uint64_t)fds;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		, "r"(reg_r8)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*fd = (cloudabi_fd_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_readdir(
	cloudabi_fd_t fd,
	void *buf,
	size_t nbyte,
	cloudabi_dircookie_t cookie,
	size_t *bufused
) {
	register uint64_t reg_rax asm("rax") = 22;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)buf;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)nbyte;
	register uint64_t reg_r10 asm("r10") = (uint64_t)cookie;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*bufused = (size_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_readlink(
	cloudabi_fd_t fd,
	const char *path,
	size_t pathlen,
	char *buf,
	size_t bufsize,
	size_t *bufused
) {
	register uint64_t reg_rax asm("rax") = 23;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)path;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)pathlen;
	register uint64_t reg_r10 asm("r10") = (uint64_t)buf;
	register uint64_t reg_r8 asm("r8") = (uint64_t)bufsize;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		, "r"(reg_r8)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*bufused = (size_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_rename(
	cloudabi_fd_t oldfd,
	const char *old,
	size_t oldlen,
	cloudabi_fd_t newfd,
	const char *new,
	size_t newlen
) {
	register uint64_t reg_rax asm("rax") = 24;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)oldfd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)old;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)oldlen;
	register uint64_t reg_r10 asm("r10") = (uint64_t)newfd;
	register uint64_t reg_r8 asm("r8") = (uint64_t)new;
	register uint64_t reg_r9 asm("r9") = (uint64_t)newlen;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		, "r"(reg_r8)
		, "r"(reg_r9)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_stat_fget(
	cloudabi_fd_t fd,
	cloudabi_filestat_t *buf
) {
	register uint64_t reg_rax asm("rax") = 25;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)buf;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_stat_fput(
	cloudabi_fd_t fd,
	const cloudabi_filestat_t *buf,
	cloudabi_fsflags_t flags
) {
	register uint64_t reg_rax asm("rax") = 26;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)buf;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)flags;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_stat_get(
	cloudabi_lookup_t fd,
	const char *path,
	size_t pathlen,
	cloudabi_filestat_t *buf
) {
	register uint64_t reg_rax asm("rax") = 27;
	register uint64_t reg_rdi asm("rdi") = *(uint64_t *)&fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)path;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)pathlen;
	register uint64_t reg_r10 asm("r10") = (uint64_t)buf;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_stat_put(
	cloudabi_lookup_t fd,
	const char *path,
	size_t pathlen,
	const cloudabi_filestat_t *buf,
	cloudabi_fsflags_t flags
) {
	register uint64_t reg_rax asm("rax") = 28;
	register uint64_t reg_rdi asm("rdi") = *(uint64_t *)&fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)path;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)pathlen;
	register uint64_t reg_r10 asm("r10") = (uint64_t)buf;
	register uint64_t reg_r8 asm("r8") = (uint64_t)flags;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		, "r"(reg_r8)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_symlink(
	const char *path1,
	size_t path1len,
	cloudabi_fd_t fd,
	const char *path2,
	size_t path2len
) {
	register uint64_t reg_rax asm("rax") = 29;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)path1;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)path1len;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)fd;
	register uint64_t reg_r10 asm("r10") = (uint64_t)path2;
	register uint64_t reg_r8 asm("r8") = (uint64_t)path2len;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		, "r"(reg_r8)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_file_unlink(
	cloudabi_fd_t fd,
	const char *path,
	size_t pathlen,
	cloudabi_ulflags_t flags
) {
	register uint64_t reg_rax asm("rax") = 30;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)path;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)pathlen;
	register uint64_t reg_r10 asm("r10") = (uint64_t)flags;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_lock_unlock(
	_Atomic(cloudabi_lock_t) *lock,
	cloudabi_mflags_t scope
) {
	register uint64_t reg_rax asm("rax") = 31;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)lock;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)scope;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_mem_advise(
	void *addr,
	size_t len,
	cloudabi_advice_t advice
) {
	register uint64_t reg_rax asm("rax") = 32;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)addr;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)len;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)advice;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_mem_lock(
	const void *addr,
	size_t len
) {
	register uint64_t reg_rax asm("rax") = 33;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)addr;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)len;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_mem_map(
	void *addr,
	size_t len,
	cloudabi_mprot_t prot,
	cloudabi_mflags_t flags,
	cloudabi_fd_t fd,
	cloudabi_filesize_t off,
	void **mem
) {
	register uint64_t reg_rax asm("rax") = 34;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)addr;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)len;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)prot;
	register uint64_t reg_r10 asm("r10") = (uint64_t)flags;
	register uint64_t reg_r8 asm("r8") = (uint64_t)fd;
	register uint64_t reg_r9 asm("r9") = (uint64_t)off;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		, "r"(reg_r8)
		, "r"(reg_r9)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*mem = (void *)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_mem_protect(
	void *addr,
	size_t len,
	cloudabi_mprot_t prot
) {
	register uint64_t reg_rax asm("rax") = 35;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)addr;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)len;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)prot;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_mem_sync(
	void *addr,
	size_t len,
	cloudabi_msflags_t flags
) {
	register uint64_t reg_rax asm("rax") = 36;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)addr;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)len;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)flags;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_mem_unlock(
	const void *addr,
	size_t len
) {
	register uint64_t reg_rax asm("rax") = 37;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)addr;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)len;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_mem_unmap(
	void *addr,
	size_t len
) {
	register uint64_t reg_rax asm("rax") = 38;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)addr;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)len;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_poll(
	const cloudabi_subscription_t *in,
	cloudabi_event_t *out,
	size_t nsubscriptions,
	size_t *nevents
) {
	register uint64_t reg_rax asm("rax") = 39;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)in;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)out;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)nsubscriptions;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*nevents = (size_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_poll_fd(
	cloudabi_fd_t fd,
	const cloudabi_subscription_t *in,
	size_t nin,
	cloudabi_event_t *out,
	size_t nout,
	const cloudabi_subscription_t *timeout,
	size_t *nevents
) {
	register uint64_t reg_rax asm("rax") = 57;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)in;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)nin;
	register uint64_t reg_r10 asm("r10") = (uint64_t)out;
	register uint64_t reg_r8 asm("r8") = (uint64_t)nout;
	register uint64_t reg_r9 asm("r9") = (uint64_t)timeout;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		, "r"(reg_r8)
		, "r"(reg_r9)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*nevents = (size_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_proc_exec(
	cloudabi_fd_t fd,
	const void *data,
	size_t datalen,
	const cloudabi_fd_t *fds,
	size_t fdslen
) {
	register uint64_t reg_rax asm("rax") = 40;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)fd;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)data;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)datalen;
	register uint64_t reg_r10 asm("r10") = (uint64_t)fds;
	register uint64_t reg_r8 asm("r8") = (uint64_t)fdslen;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		, "r"(reg_r8)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline _Noreturn void
cloudabi_sys_proc_exit(
	cloudabi_exitcode_t rval
) {
	register uint64_t reg_rax asm("rax") = 41;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)rval;
	asm volatile (
		"\tsyscall\n"
		:
		: "r"(reg_rax)
		, "r"(reg_rdi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	for (;;);
}

static inline cloudabi_errno_t
cloudabi_sys_proc_fork(
	cloudabi_fd_t *fd,
	cloudabi_tid_t *tid
) {
	register uint64_t reg_rax asm("rax") = 42;
	register uint64_t reg_rdx asm("rdx");
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		, "=r"(reg_rdx)
		: "r"(reg_rax)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*fd = (cloudabi_fd_t)reg_rax;
		*tid = (cloudabi_tid_t)reg_rdx;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_proc_raise(
	cloudabi_signal_t sig
) {
	register uint64_t reg_rax asm("rax") = 43;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)sig;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_random_get(
	void *buf,
	size_t nbyte
) {
	register uint64_t reg_rax asm("rax") = 44;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)buf;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)nbyte;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_sock_accept(
	cloudabi_fd_t sock,
	cloudabi_sockstat_t *buf,
	cloudabi_fd_t *conn
) {
	register uint64_t reg_rax asm("rax") = 45;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)sock;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)buf;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*conn = (cloudabi_fd_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_sock_bind(
	cloudabi_fd_t sock,
	cloudabi_fd_t fd,
	const char *path,
	size_t pathlen
) {
	register uint64_t reg_rax asm("rax") = 46;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)sock;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)fd;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)path;
	register uint64_t reg_r10 asm("r10") = (uint64_t)pathlen;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_sock_connect(
	cloudabi_fd_t sock,
	cloudabi_fd_t fd,
	const char *path,
	size_t pathlen
) {
	register uint64_t reg_rax asm("rax") = 47;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)sock;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)fd;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)path;
	register uint64_t reg_r10 asm("r10") = (uint64_t)pathlen;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		, "r"(reg_r10)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_sock_listen(
	cloudabi_fd_t sock,
	cloudabi_backlog_t backlog
) {
	register uint64_t reg_rax asm("rax") = 48;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)sock;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)backlog;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_sock_recv(
	cloudabi_fd_t sock,
	const cloudabi_recv_in_t *in,
	cloudabi_recv_out_t *out
) {
	register uint64_t reg_rax asm("rax") = 49;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)sock;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)in;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)out;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_sock_send(
	cloudabi_fd_t sock,
	const cloudabi_send_in_t *in,
	cloudabi_send_out_t *out
) {
	register uint64_t reg_rax asm("rax") = 50;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)sock;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)in;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)out;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_sock_shutdown(
	cloudabi_fd_t sock,
	cloudabi_sdflags_t how
) {
	register uint64_t reg_rax asm("rax") = 51;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)sock;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)how;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_sock_stat_get(
	cloudabi_fd_t sock,
	cloudabi_sockstat_t *buf,
	cloudabi_ssflags_t flags
) {
	register uint64_t reg_rax asm("rax") = 52;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)sock;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)buf;
	register uint64_t reg_rdx asm("rdx") = (uint64_t)flags;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		, "r"(reg_rdx)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_thread_create(
	cloudabi_threadattr_t *attr,
	cloudabi_tid_t *tid
) {
	register uint64_t reg_rax asm("rax") = 53;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)attr;
	register char okay;
	asm volatile (
		"\tsyscall\n"
		"\tsetnc %0\n"
		: "=r"(okay)
		, "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	if (okay) {
		*tid = (cloudabi_tid_t)reg_rax;
		return 0;
	}
	return reg_rax;
}

static inline _Noreturn void
cloudabi_sys_thread_exit(
	_Atomic(cloudabi_lock_t) *lock,
	cloudabi_mflags_t scope
) {
	register uint64_t reg_rax asm("rax") = 54;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)lock;
	register uint64_t reg_rsi asm("rsi") = (uint64_t)scope;
	asm volatile (
		"\tsyscall\n"
		:
		: "r"(reg_rax)
		, "r"(reg_rdi)
		, "r"(reg_rsi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	for (;;);
}

static inline cloudabi_errno_t
cloudabi_sys_thread_tcb_set(
	void *tcb
) {
	register uint64_t reg_rax asm("rax") = 55;
	register uint64_t reg_rdi asm("rdi") = (uint64_t)tcb;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		, "r"(reg_rdi)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

static inline cloudabi_errno_t
cloudabi_sys_thread_yield(void) {
	register uint64_t reg_rax asm("rax") = 56;
	asm volatile (
		"\tsyscall\n"
		: "=r"(reg_rax)
		: "r"(reg_rax)
		: "memory", "rcx", "rdx", "r8", "r9", "r10", "r11");
	return reg_rax;
}

#endif
