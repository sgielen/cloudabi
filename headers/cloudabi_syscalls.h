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
//
// This file is automatically generated. Do not edit.
//
// Source: https://github.com/NuxiNL/cloudabi

#ifndef CLOUDABI_SYSCALLS_H
#define CLOUDABI_SYSCALLS_H

#include "cloudabi_syscalls_struct.h"

extern cloudabi_syscalls_t cloudabi_syscalls;

static inline cloudabi_errno_t cloudabi_sys_clock_res_get(
    cloudabi_clockid_t clock_id, cloudabi_timestamp_t *resolution) {
  return cloudabi_syscalls.clock_res_get(clock_id, resolution);
}

static inline cloudabi_errno_t cloudabi_sys_clock_time_get(
    cloudabi_clockid_t clock_id, cloudabi_timestamp_t precision,
    cloudabi_timestamp_t *time) {
  return cloudabi_syscalls.clock_time_get(clock_id, precision, time);
}

static inline cloudabi_errno_t cloudabi_sys_condvar_signal(
    _Atomic(cloudabi_condvar_t) * condvar, cloudabi_scope_t scope,
    cloudabi_nthreads_t nwaiters) {
  return cloudabi_syscalls.condvar_signal(condvar, scope, nwaiters);
}

static inline cloudabi_errno_t cloudabi_sys_fd_close(cloudabi_fd_t fd) {
  return cloudabi_syscalls.fd_close(fd);
}

static inline cloudabi_errno_t cloudabi_sys_fd_create1(cloudabi_filetype_t type,
                                                       cloudabi_fd_t *fd) {
  return cloudabi_syscalls.fd_create1(type, fd);
}

static inline cloudabi_errno_t cloudabi_sys_fd_create2(cloudabi_filetype_t type,
                                                       cloudabi_fd_t *fd1,
                                                       cloudabi_fd_t *fd2) {
  return cloudabi_syscalls.fd_create2(type, fd1, fd2);
}

static inline cloudabi_errno_t cloudabi_sys_fd_datasync(cloudabi_fd_t fd) {
  return cloudabi_syscalls.fd_datasync(fd);
}

static inline cloudabi_errno_t cloudabi_sys_fd_dup(cloudabi_fd_t from,
                                                   cloudabi_fd_t *fd) {
  return cloudabi_syscalls.fd_dup(from, fd);
}

static inline cloudabi_errno_t cloudabi_sys_fd_pread(
    cloudabi_fd_t fd, const cloudabi_iovec_t *iov, size_t iovcnt,
    cloudabi_filesize_t offset, size_t *nread) {
  return cloudabi_syscalls.fd_pread(fd, iov, iovcnt, offset, nread);
}

static inline cloudabi_errno_t cloudabi_sys_fd_pwrite(
    cloudabi_fd_t fd, const cloudabi_ciovec_t *iov, size_t iovcnt,
    cloudabi_filesize_t offset, size_t *nwritten) {
  return cloudabi_syscalls.fd_pwrite(fd, iov, iovcnt, offset, nwritten);
}

static inline cloudabi_errno_t cloudabi_sys_fd_read(cloudabi_fd_t fd,
                                                    const cloudabi_iovec_t *iov,
                                                    size_t iovcnt,
                                                    size_t *nread) {
  return cloudabi_syscalls.fd_read(fd, iov, iovcnt, nread);
}

static inline cloudabi_errno_t cloudabi_sys_fd_replace(cloudabi_fd_t from,
                                                       cloudabi_fd_t to) {
  return cloudabi_syscalls.fd_replace(from, to);
}

static inline cloudabi_errno_t cloudabi_sys_fd_seek(
    cloudabi_fd_t fd, cloudabi_filedelta_t offset, cloudabi_whence_t whence,
    cloudabi_filesize_t *newoffset) {
  return cloudabi_syscalls.fd_seek(fd, offset, whence, newoffset);
}

static inline cloudabi_errno_t cloudabi_sys_fd_stat_get(
    cloudabi_fd_t fd, cloudabi_fdstat_t *buf) {
  return cloudabi_syscalls.fd_stat_get(fd, buf);
}

static inline cloudabi_errno_t cloudabi_sys_fd_stat_put(
    cloudabi_fd_t fd, const cloudabi_fdstat_t *buf, cloudabi_fdsflags_t flags) {
  return cloudabi_syscalls.fd_stat_put(fd, buf, flags);
}

static inline cloudabi_errno_t cloudabi_sys_fd_sync(cloudabi_fd_t fd) {
  return cloudabi_syscalls.fd_sync(fd);
}

static inline cloudabi_errno_t cloudabi_sys_fd_write(
    cloudabi_fd_t fd, const cloudabi_ciovec_t *iov, size_t iovcnt,
    size_t *nwritten) {
  return cloudabi_syscalls.fd_write(fd, iov, iovcnt, nwritten);
}

static inline cloudabi_errno_t cloudabi_sys_file_advise(
    cloudabi_fd_t fd, cloudabi_filesize_t offset, cloudabi_filesize_t len,
    cloudabi_advice_t advice) {
  return cloudabi_syscalls.file_advise(fd, offset, len, advice);
}

static inline cloudabi_errno_t cloudabi_sys_file_allocate(
    cloudabi_fd_t fd, cloudabi_filesize_t offset, cloudabi_filesize_t len) {
  return cloudabi_syscalls.file_allocate(fd, offset, len);
}

static inline cloudabi_errno_t cloudabi_sys_file_create(
    cloudabi_fd_t fd, const char *path, size_t pathlen,
    cloudabi_filetype_t type) {
  return cloudabi_syscalls.file_create(fd, path, pathlen, type);
}

static inline cloudabi_errno_t cloudabi_sys_file_link(
    cloudabi_lookup_t fd1, const char *path1, size_t path1len,
    cloudabi_fd_t fd2, const char *path2, size_t path2len) {
  return cloudabi_syscalls.file_link(fd1, path1, path1len, fd2, path2,
                                     path2len);
}

static inline cloudabi_errno_t cloudabi_sys_file_open(
    cloudabi_lookup_t dirfd, const char *path, size_t pathlen,
    cloudabi_oflags_t oflags, const cloudabi_fdstat_t *fds, cloudabi_fd_t *fd) {
  return cloudabi_syscalls.file_open(dirfd, path, pathlen, oflags, fds, fd);
}

static inline cloudabi_errno_t cloudabi_sys_file_readdir(
    cloudabi_fd_t fd, void *buf, size_t nbyte, cloudabi_dircookie_t cookie,
    size_t *bufused) {
  return cloudabi_syscalls.file_readdir(fd, buf, nbyte, cookie, bufused);
}

static inline cloudabi_errno_t cloudabi_sys_file_readlink(
    cloudabi_fd_t fd, const char *path, size_t pathlen, char *buf,
    size_t bufsize, size_t *bufused) {
  return cloudabi_syscalls.file_readlink(fd, path, pathlen, buf, bufsize,
                                         bufused);
}

static inline cloudabi_errno_t cloudabi_sys_file_rename(
    cloudabi_fd_t oldfd, const char *old, size_t oldlen, cloudabi_fd_t newfd,
    const char *new, size_t newlen) {
  return cloudabi_syscalls.file_rename(oldfd, old, oldlen, newfd, new, newlen);
}

static inline cloudabi_errno_t cloudabi_sys_file_stat_fget(
    cloudabi_fd_t fd, cloudabi_filestat_t *buf) {
  return cloudabi_syscalls.file_stat_fget(fd, buf);
}

static inline cloudabi_errno_t cloudabi_sys_file_stat_fput(
    cloudabi_fd_t fd, const cloudabi_filestat_t *buf,
    cloudabi_fsflags_t flags) {
  return cloudabi_syscalls.file_stat_fput(fd, buf, flags);
}

static inline cloudabi_errno_t cloudabi_sys_file_stat_get(
    cloudabi_lookup_t fd, const char *path, size_t pathlen,
    cloudabi_filestat_t *buf) {
  return cloudabi_syscalls.file_stat_get(fd, path, pathlen, buf);
}

static inline cloudabi_errno_t cloudabi_sys_file_stat_put(
    cloudabi_lookup_t fd, const char *path, size_t pathlen,
    const cloudabi_filestat_t *buf, cloudabi_fsflags_t flags) {
  return cloudabi_syscalls.file_stat_put(fd, path, pathlen, buf, flags);
}

static inline cloudabi_errno_t cloudabi_sys_file_symlink(const char *path1,
                                                         size_t path1len,
                                                         cloudabi_fd_t fd,
                                                         const char *path2,
                                                         size_t path2len) {
  return cloudabi_syscalls.file_symlink(path1, path1len, fd, path2, path2len);
}

static inline cloudabi_errno_t cloudabi_sys_file_unlink(
    cloudabi_fd_t fd, const char *path, size_t pathlen,
    cloudabi_ulflags_t flags) {
  return cloudabi_syscalls.file_unlink(fd, path, pathlen, flags);
}

static inline cloudabi_errno_t cloudabi_sys_lock_unlock(
    _Atomic(cloudabi_lock_t) * lock, cloudabi_scope_t scope) {
  return cloudabi_syscalls.lock_unlock(lock, scope);
}

static inline cloudabi_errno_t cloudabi_sys_mem_advise(
    void *addr, size_t len, cloudabi_advice_t advice) {
  return cloudabi_syscalls.mem_advise(addr, len, advice);
}

static inline cloudabi_errno_t cloudabi_sys_mem_lock(const void *addr,
                                                     size_t len) {
  return cloudabi_syscalls.mem_lock(addr, len);
}

static inline cloudabi_errno_t cloudabi_sys_mem_map(
    void *addr, size_t len, cloudabi_mprot_t prot, cloudabi_mflags_t flags,
    cloudabi_fd_t fd, cloudabi_filesize_t off, void **mem) {
  return cloudabi_syscalls.mem_map(addr, len, prot, flags, fd, off, mem);
}

static inline cloudabi_errno_t cloudabi_sys_mem_protect(void *addr, size_t len,
                                                        cloudabi_mprot_t prot) {
  return cloudabi_syscalls.mem_protect(addr, len, prot);
}

static inline cloudabi_errno_t cloudabi_sys_mem_sync(void *addr, size_t len,
                                                     cloudabi_msflags_t flags) {
  return cloudabi_syscalls.mem_sync(addr, len, flags);
}

static inline cloudabi_errno_t cloudabi_sys_mem_unlock(const void *addr,
                                                       size_t len) {
  return cloudabi_syscalls.mem_unlock(addr, len);
}

static inline cloudabi_errno_t cloudabi_sys_mem_unmap(void *addr, size_t len) {
  return cloudabi_syscalls.mem_unmap(addr, len);
}

static inline cloudabi_errno_t cloudabi_sys_poll(
    const cloudabi_subscription_t *in, cloudabi_event_t *out,
    size_t nsubscriptions, size_t *nevents) {
  return cloudabi_syscalls.poll(in, out, nsubscriptions, nevents);
}

static inline cloudabi_errno_t cloudabi_sys_poll_fd(
    cloudabi_fd_t fd, const cloudabi_subscription_t *in, size_t nin,
    cloudabi_event_t *out, size_t nout, const cloudabi_subscription_t *timeout,
    size_t *nevents) {
  return cloudabi_syscalls.poll_fd(fd, in, nin, out, nout, timeout, nevents);
}

static inline cloudabi_errno_t cloudabi_sys_proc_exec(cloudabi_fd_t fd,
                                                      const void *data,
                                                      size_t datalen,
                                                      const cloudabi_fd_t *fds,
                                                      size_t fdslen) {
  return cloudabi_syscalls.proc_exec(fd, data, datalen, fds, fdslen);
}

static inline _Noreturn void cloudabi_sys_proc_exit(cloudabi_exitcode_t rval) {
  cloudabi_syscalls.proc_exit(rval);
  for (;;)
    ;
}

static inline cloudabi_errno_t cloudabi_sys_proc_fork(cloudabi_fd_t *fd,
                                                      cloudabi_tid_t *tid) {
  return cloudabi_syscalls.proc_fork(fd, tid);
}

static inline cloudabi_errno_t cloudabi_sys_proc_raise(cloudabi_signal_t sig) {
  return cloudabi_syscalls.proc_raise(sig);
}

static inline cloudabi_errno_t cloudabi_sys_random_get(void *buf,
                                                       size_t nbyte) {
  return cloudabi_syscalls.random_get(buf, nbyte);
}

static inline cloudabi_errno_t cloudabi_sys_sock_accept(
    cloudabi_fd_t sock, cloudabi_sockstat_t *buf, cloudabi_fd_t *conn) {
  return cloudabi_syscalls.sock_accept(sock, buf, conn);
}

static inline cloudabi_errno_t cloudabi_sys_sock_bind(cloudabi_fd_t sock,
                                                      cloudabi_fd_t fd,
                                                      const char *path,
                                                      size_t pathlen) {
  return cloudabi_syscalls.sock_bind(sock, fd, path, pathlen);
}

static inline cloudabi_errno_t cloudabi_sys_sock_connect(cloudabi_fd_t sock,
                                                         cloudabi_fd_t fd,
                                                         const char *path,
                                                         size_t pathlen) {
  return cloudabi_syscalls.sock_connect(sock, fd, path, pathlen);
}

static inline cloudabi_errno_t cloudabi_sys_sock_listen(
    cloudabi_fd_t sock, cloudabi_backlog_t backlog) {
  return cloudabi_syscalls.sock_listen(sock, backlog);
}

static inline cloudabi_errno_t cloudabi_sys_sock_recv(
    cloudabi_fd_t sock, const cloudabi_recv_in_t *in,
    cloudabi_recv_out_t *out) {
  return cloudabi_syscalls.sock_recv(sock, in, out);
}

static inline cloudabi_errno_t cloudabi_sys_sock_send(
    cloudabi_fd_t sock, const cloudabi_send_in_t *in,
    cloudabi_send_out_t *out) {
  return cloudabi_syscalls.sock_send(sock, in, out);
}

static inline cloudabi_errno_t cloudabi_sys_sock_shutdown(
    cloudabi_fd_t sock, cloudabi_sdflags_t how) {
  return cloudabi_syscalls.sock_shutdown(sock, how);
}

static inline cloudabi_errno_t cloudabi_sys_sock_stat_get(
    cloudabi_fd_t sock, cloudabi_sockstat_t *buf, cloudabi_ssflags_t flags) {
  return cloudabi_syscalls.sock_stat_get(sock, buf, flags);
}

static inline cloudabi_errno_t cloudabi_sys_thread_create(
    cloudabi_threadattr_t *attr, cloudabi_tid_t *tid) {
  return cloudabi_syscalls.thread_create(attr, tid);
}

static inline _Noreturn void cloudabi_sys_thread_exit(_Atomic(cloudabi_lock_t) *
                                                          lock,
                                                      cloudabi_scope_t scope) {
  cloudabi_syscalls.thread_exit(lock, scope);
  for (;;)
    ;
}

static inline cloudabi_errno_t cloudabi_sys_thread_yield(void) {
  return cloudabi_syscalls.thread_yield();
}

#endif
