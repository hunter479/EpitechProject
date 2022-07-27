/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** day02
*/

#ifndef BITMAP_H
    #define BITMAP_H

#include <stdint.h>
#include <stddef.h>

typedef struct __attribute__((packed)) s_bmp_header
{
    uint16_t    magic;
    uint32_t    size;
    uint16_t    _app1;
    uint16_t    _app2;
    uint32_t    offset;
}   bmp_header_t;

typedef struct __attribute__((packed)) s_bmp_info_header
{
    uint32_t    size;
    int32_t     width;
    int32_t     height;
    uint16_t    planes;
    uint16_t    bpp;
    uint32_t    compression;
    uint32_t    raw_data_size;
    int32_t     h_resolution;
    int32_t     v_resolution;
    uint32_t    palette_size;
    uint32_t    important_colors;
}   bmp_info_header_t;

void make_bmp_info_header(bmp_info_header_t *, size_t);
void make_bmp_header(bmp_header_t *, size_t);

#endif /* !BITMAP_H */
