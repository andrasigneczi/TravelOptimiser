#include "png2arma.h"

/*
 * Copyright 2002-2010 Guillaume Cottenceau.
 *
 * This software may be freely redistributed under the terms
 * of the X11 license.
 *
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define PNG_DEBUG 3
#include <png.h>

void abort_(const char * s, ...)
{
        va_list args;
        va_start(args, s);
        vfprintf(stderr, s, args);
        fprintf(stderr, "\n");
        va_end(args);
        abort();
}

void Png2Arma::read_png_file(const char* file_name)
{
    char header[8];    // 8 is the maximum size that can be checked

    /* open file and test for it being a png */
    FILE *fp = fopen(file_name, "rb");
    if (!fp)
            abort_("[read_png_file] File %s could not be opened for reading", file_name);
    if(fread(header, 1, 8, fp)==0){};
    if (png_sig_cmp((png_bytep)header, 0, 8))
            abort_("[read_png_file] File %s is not recognized as a PNG file", file_name);


    /* initialize stuff */
    mPngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!mPngPtr)
            abort_("[read_png_file] png_create_read_struct failed");

    info_ptr = png_create_info_struct(mPngPtr);
    if (!info_ptr)
            abort_("[read_png_file] png_create_info_struct failed");

    if (setjmp(png_jmpbuf(mPngPtr)))
            abort_("[read_png_file] Error during init_io");

    mFileName = file_name;
    png_init_io(mPngPtr, fp);
    png_set_sig_bytes(mPngPtr, 8);

    png_read_info(mPngPtr, info_ptr);

    mWidth = png_get_image_width(mPngPtr, info_ptr);
    mHeight = png_get_image_height(mPngPtr, info_ptr);
    mColorType = png_get_color_type(mPngPtr, info_ptr);
    mBitDepth = png_get_bit_depth(mPngPtr, info_ptr);

    number_of_passes = png_set_interlace_handling(mPngPtr);
    png_read_update_info(mPngPtr, info_ptr);


    /* read file */
    if (setjmp(png_jmpbuf(mPngPtr)))
            abort_("[read_png_file] Error during read_image");

    row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * mHeight);
    for (size_t y=0; y<mHeight; y++)
            row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(mPngPtr,info_ptr));

    png_read_image(mPngPtr, row_pointers);
    fclose(fp);
}

void Png2Arma::close() {
    /* cleanup heap allocation */
    for (size_t y=0; y<mHeight; y++)
        free(row_pointers[y]);
    free(row_pointers);
}

void Png2Arma::write_png_file(const char* file_name)
{
    /* create file */
    FILE *fp = fopen(file_name, "wb");
    if (!fp)
            abort_("[write_png_file] File %s could not be opened for writing", file_name);


    /* initialize stuff */
    mPngPtr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!mPngPtr)
            abort_("[write_png_file] png_create_write_struct failed");

    info_ptr = png_create_info_struct(mPngPtr);
    if (!info_ptr)
            abort_("[write_png_file] png_create_info_struct failed");

    if (setjmp(png_jmpbuf(mPngPtr)))
            abort_("[write_png_file] Error during init_io");

    png_init_io(mPngPtr, fp);


    /* write header */
    if (setjmp(png_jmpbuf(mPngPtr)))
            abort_("[write_png_file] Error during writing header");

    png_set_IHDR(mPngPtr, info_ptr, mWidth, mHeight,
                 mBitDepth, mColorType, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_write_info(mPngPtr, info_ptr);


    /* write bytes */
    if (setjmp(png_jmpbuf(mPngPtr)))
            abort_("[write_png_file] Error during writing bytes");

    png_write_image(mPngPtr, row_pointers);


    /* end write */
    if (setjmp(png_jmpbuf(mPngPtr)))
            abort_("[write_png_file] Error during end of write");

    png_write_end(mPngPtr, NULL);

    close();
    fclose(fp);
}


arma::mat Png2Arma::process_file( size_t width, size_t height, bool gray )
{
    int multipler = 4;
    if (png_get_color_type(mPngPtr, info_ptr) == PNG_COLOR_TYPE_RGB){
            //abort_("[process_file] input file is PNG_COLOR_TYPE_RGB but must be PNG_COLOR_TYPE_RGBA "
              //     "(lacks the alpha channel)");
        multipler = 3;
    }

    else if (png_get_color_type(mPngPtr, info_ptr) != PNG_COLOR_TYPE_RGBA) {
	    std::cerr << mFileName << "\n";
            abort_("[process_file] color_type of input file must be PNG_COLOR_TYPE_RGBA (%d) (is %d)",
                   PNG_COLOR_TYPE_RGBA, png_get_color_type(mPngPtr, info_ptr));
    }

    int mul = 3;
    if( gray )
        mul = 1;
    arma::mat retVal = arma::zeros( 1, mul * width * height );
    if( width != mWidth || height != mHeight ) {
        std::cerr << "The image (" << mFileName << ") does not conform to the expected size!\n";
        std::cerr << "expected size (width x height): " << width << "x" << height << "; image size: " << mWidth << "x" << mHeight << std::endl;
        return arma::mat(0,0);
    }
    size_t x, y;
    for (y=0; y<mHeight && y < height; y++) {
        png_byte* row = row_pointers[y];
        for (x=0; x<mWidth && x < width; x++) {

            png_byte* ptr = &(row[x*multipler]);
            //printf("Pixel at position [ %d - %d ] has RGBA values: %d - %d - %d - %d\n",
            //       x, y, ptr[0], ptr[1], ptr[2], ptr[3]);
            if( gray ) {
                // Y=0.2126R+0.7152G+0.0722B
                retVal(0, y * width + x ) = 0.2126*ptr[0]+0.7152*ptr[2]+0.0722*ptr[1];
            } else {
                retVal(0, 3 * y * width + 3 * x + 0) = ptr[0];
                retVal(0, 3 * y * width + 3 * x + 1) = ptr[2];
                retVal(0, 3 * y * width + 3 * x + 2) = ptr[1];
            }
        }
    }
    return retVal;
}


