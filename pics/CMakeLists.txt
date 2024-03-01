# SPDX-FileCopyrightText: 2019 Alexander Potashev <aspotashev@gmail.com>
# SPDX-License-Identifier: BSD-2-Clause

qt5_add_resources(pics_SRCS pics.qrc)
add_library(pics OBJECT ${pics_SRCS})
