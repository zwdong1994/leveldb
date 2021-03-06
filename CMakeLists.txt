cmake_minimum_required(VERSION 3.5)
project(main)

SET(CMAKE_C_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)

ADD_DEFINITIONS(-g -W -Wall -lrt -lcrypto -lpthread  -D_GLIBCXX_USE_CXX11_ABI=0 -fpermissive)

include_directories(./include /usr/include ./)
include_directories(db/ include/leveldb helpers/ port/ table/ util/)
link_libraries("/usr/lib/x86_64-linux-gnu/librt.so")
link_libraries("/usr/lib/x86_64-linux-gnu/libcrypto.a")
link_directories(/lib/x86_64-linux-gnu)

set(SOURCE_FILES main.cpp
        db/autocompact_test.cc
        db/builder.cc
        db/c.cc
        db/c_test.c
        db/corruption_test.cc
        db/db_bench.cc
        db/db_impl.cc
        db/db_iter.cc
        db/db_test.cc
        db/dbformat.cc
        db/dbformat_test.cc
        db/dumpfile.cc
        db/fault_injection_test.cc
        db/filename.cc
        db/filename_test.cc
        db/leveldbutil.cc
        db/log_reader.cc
        db/log_test.cc
        db/log_writer.cc
        db/memtable.cc
        db/recovery_test.cc
        db/repair.cc
        db/skiplist_test.cc
        db/table_cache.cc
        db/version_edit.cc
        db/version_edit_test.cc
        db/version_set.cc
        db/version_set_test.cc
        db/write_batch.cc
        db/write_batch_test.cc
        helpers/memenv/memenv.cc
        helpers/memenv/memenv_test.cc
        issues/issue178_test.cc
        issues/issue200_test.cc
        port/port_posix.cc
        table/block.cc
        table/block_builder.cc
        table/filter_block.cc
        table/filter_block_test.cc
        table/format.cc
        table/iterator.cc
        table/merger.cc
        table/table.cc
        table/table_builder.cc
        table/table_test.cc
        table/two_level_iterator.cc
        util/arena.cc
        util/arena_test.cc
        util/bloom.cc
        util/bloom_test.cc
        util/cache.cc
        util/cache_test.cc
        util/coding.cc
        util/coding_test.cc
        util/comparator.cc
        util/crc32c.cc
        util/crc32c_test.cc
        util/env.cc
        util/env_posix.cc
        util/env_posix_test.cc
        util/env_test.cc
        util/filter_policy.cc
        util/hash.cc
        util/hash_test.cc
        util/histogram.cc
        util/logging.cc
        util/options.cc
        util/status.cc
        util/testharness.cc
        util/testutil.cc
        test/test_put_get.cc)
add_executable(main ${SOURCE_FILES})