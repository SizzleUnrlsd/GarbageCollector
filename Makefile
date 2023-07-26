# Copyright (C) 2023 hugo
# 
# This file is part of GarbageCollector.
# 
# GarbageCollector is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# GarbageCollector is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with GarbageCollector.  If not, see <http://www.gnu.org/licenses/>.

TARGET = garbage-collector

CC = gcc

CFLAGS = -Wall -Wextra -Ilib -Wno-unknown-pragmas -Wno-frame-address

SRC_DIR = src

SRCS = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS) main.o
	$(CC) $(CFLAGS) $(OBJS) main.o -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) main.o $(TARGET)
