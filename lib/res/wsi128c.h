#define x_width_wsi 128
#define x_height_wsi 64
static char x_bits_wsi[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x44, 0x08, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x01, 0x00, 0x00, 
0xf0, 0xff, 0xf9, 0xff, 0xff, 0xf9, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xf0, 0xff, 0xf9, 0xff, 0xff, 0xf9, 0x1f, 0x00, 0x00, 0x40, 0x44, 0x44, 0x40, 0x44, 0x00, 0x00, 
0xf0, 0xff, 0xf9, 0xff, 0xff, 0xf9, 0x1f, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x80, 0x7f, 0xc0, 0x1f, 0x38, 0x80, 0x07, 0x00, 0x00, 0x10, 0x11, 0x11, 0x11, 0x11, 0x01, 0x00, 
0x80, 0x7f, 0xc0, 0x1f, 0x38, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x7f, 0x80, 0x1f, 0x18, 0x80, 0x03, 0x00, 0x80, 0x7f, 0xff, 0x55, 0x51, 0x45, 0x04, 0x00, 
0x00, 0x7f, 0x80, 0x3f, 0x1c, 0x80, 0x03, 0x00, 0x80, 0x7f, 0xff, 0xa9, 0xaa, 0x02, 0x00, 0x00, 
0x00, 0xff, 0x80, 0x3f, 0x1c, 0xc0, 0x01, 0x00, 0xa0, 0x7f, 0xff, 0x55, 0x51, 0x15, 0x01, 0x00, 
0x00, 0xfe, 0x00, 0x3f, 0x0c, 0xc0, 0x01, 0x00, 0xa0, 0x7f, 0xff, 0xa9, 0xaa, 0x02, 0x00, 0x00, 
0x00, 0xfe, 0x00, 0x7f, 0x0e, 0xc0, 0x01, 0x00, 0xb0, 0x7f, 0xff, 0x55, 0x51, 0x45, 0x44, 0x00, 
0x00, 0xfe, 0x01, 0x7f, 0x0e, 0xe0, 0x00, 0x00, 0xb8, 0x7f, 0xff, 0xa9, 0xaa, 0x02, 0x00, 0x00, 
0x00, 0xfc, 0x01, 0x7e, 0x06, 0xe0, 0x00, 0x00, 0xb8, 0x7f, 0xff, 0x55, 0x51, 0x15, 0x01, 0x01, 
0x00, 0xfc, 0x01, 0xfe, 0x07, 0xe0, 0x00, 0x00, 0xbc, 0x7f, 0xff, 0xa9, 0xaa, 0x02, 0x00, 0x00, 
0x00, 0xfc, 0x03, 0xfe, 0x03, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xf8, 0x03, 0xfc, 0x03, 0x70, 0x00, 0x00, 0x80, 0x7f, 0xaa, 0xa8, 0xaa, 0xa2, 0x0a, 0x00, 
0x00, 0xf8, 0x03, 0xfc, 0x03, 0x70, 0x00, 0x00, 0x92, 0x7f, 0x55, 0xfd, 0x53, 0x55, 0x05, 0x01, 
0x00, 0xf0, 0x07, 0xfc, 0x01, 0x38, 0x00, 0x00, 0x80, 0x7f, 0xaa, 0xa8, 0xaa, 0xa2, 0x0a, 0x00, 
0x00, 0xf0, 0x07, 0xf8, 0x01, 0x38, 0x00, 0x00, 0x84, 0x7f, 0x55, 0xfd, 0x53, 0x55, 0x45, 0x04, 
0x00, 0xf0, 0x07, 0xf8, 0x03, 0x38, 0x00, 0x40, 0x80, 0x7f, 0xaa, 0xa8, 0xaa, 0xa2, 0x0a, 0x00, 
0x00, 0xe0, 0x0f, 0xf8, 0x03, 0x1c, 0x00, 0x00, 0x91, 0x7f, 0x55, 0xfd, 0x53, 0x55, 0x05, 0x11, 
0x00, 0xe0, 0x0f, 0xf8, 0x03, 0x1c, 0xc0, 0x1f, 0x80, 0x7f, 0xaa, 0xa8, 0xaa, 0xa2, 0x0a, 0x00, 
0x00, 0xe0, 0x0f, 0xf0, 0x07, 0x1c, 0xf0, 0x7f, 0x83, 0x7f, 0x55, 0xfd, 0x53, 0x55, 0x45, 0x12, 
0x00, 0xc0, 0x1f, 0xf0, 0x07, 0x0c, 0xfc, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xc0, 0x1f, 0xf0, 0x07, 0x0e, 0x3e, 0xe0, 0x93, 0x7f, 0xff, 0xfd, 0xfb, 0x57, 0x05, 0x11, 
0x00, 0xc0, 0x1f, 0xf8, 0x0f, 0x0e, 0x0f, 0x80, 0x83, 0x7f, 0xaa, 0xa8, 0xaa, 0xa2, 0x0a, 0x00, 
0x00, 0x80, 0x3f, 0xf8, 0x0f, 0x86, 0x07, 0x80, 0x83, 0x7f, 0xff, 0xfd, 0xfb, 0x57, 0x45, 0x04, 
0x00, 0x80, 0x3f, 0xf8, 0x0f, 0xc7, 0x07, 0x80, 0x81, 0x7f, 0xaa, 0xa8, 0xaa, 0xa2, 0x0a, 0x00, 
0x00, 0x80, 0x3f, 0xdc, 0x1f, 0xc7, 0x03, 0x00, 0x91, 0x7f, 0xff, 0xfd, 0xfb, 0x57, 0x05, 0x11, 
0x00, 0x00, 0x7f, 0xdc, 0x1f, 0xe7, 0x03, 0x00, 0x80, 0x7f, 0xaa, 0xa8, 0xaa, 0xa2, 0x0a, 0x00, 
0x00, 0x00, 0x7f, 0x8c, 0xbf, 0xf3, 0x03, 0x40, 0x84, 0x7f, 0xff, 0xfd, 0xfb, 0x57, 0x45, 0x04, 
0x00, 0x00, 0x7f, 0x8e, 0xbf, 0xf3, 0x03, 0x00, 0x80, 0x7f, 0xaa, 0xa8, 0xaa, 0xa2, 0x0a, 0x00, 
0x00, 0x00, 0xfe, 0x8e, 0xbf, 0xf3, 0x03, 0x00, 0x91, 0x7f, 0xff, 0xfd, 0xfb, 0x57, 0x05, 0x11, 
0x00, 0x00, 0xfe, 0x07, 0xff, 0xf1, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xfe, 0x07, 0xff, 0xf1, 0x07, 0x40, 0x84, 0x7f, 0x55, 0xfd, 0x53, 0x55, 0x45, 0x12, 
0x00, 0x00, 0xfc, 0x07, 0xff, 0xe1, 0x0f, 0x00, 0x80, 0x7f, 0xaa, 0xa8, 0xaa, 0xa2, 0x0a, 0x00, 
0x00, 0x00, 0xfc, 0x03, 0xfe, 0xc0, 0x3f, 0x00, 0x91, 0x7f, 0x55, 0xfd, 0x53, 0x55, 0x05, 0x11, 
0x00, 0x00, 0xfc, 0x03, 0xfe, 0xc0, 0x7f, 0x00, 0x80, 0x7f, 0xaa, 0xa8, 0xaa, 0xa2, 0x0a, 0x00, 
0x00, 0x00, 0xf8, 0x03, 0xfe, 0x80, 0xff, 0x01, 0x84, 0x7f, 0x55, 0xfd, 0x53, 0x55, 0x45, 0x04, 
0x00, 0x00, 0xf8, 0x03, 0x7c, 0x00, 0xff, 0x07, 0x80, 0x7f, 0xaa, 0xa8, 0xaa, 0xa2, 0x0a, 0x00, 
0x00, 0x00, 0xf8, 0x01, 0x7c, 0x00, 0xfe, 0x1f, 0x92, 0x7f, 0x55, 0xfd, 0x53, 0x55, 0x05, 0x01, 
0x00, 0x00, 0xf0, 0x01, 0x7c, 0x00, 0xfc, 0x7f, 0x80, 0x7f, 0xaa, 0xa8, 0xaa, 0xa2, 0x0a, 0x00, 
0x00, 0x00, 0xf0, 0x00, 0x3c, 0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xe0, 0x00, 0x38, 0x00, 0xe0, 0xff, 0xbd, 0x7f, 0xff, 0xa9, 0xaa, 0x02, 0x00, 0x00, 
0x00, 0x00, 0xe0, 0x00, 0x38, 0x00, 0x80, 0xff, 0xbb, 0x7f, 0xff, 0x55, 0x51, 0x15, 0x01, 0x01, 
0x00, 0x00, 0x60, 0x00, 0x38, 0x00, 0x00, 0xfe, 0xb3, 0x7f, 0xff, 0xa9, 0xaa, 0x02, 0x00, 0x00, 
0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x00, 0xf8, 0xb7, 0x7f, 0xff, 0x55, 0x51, 0x45, 0x44, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xa7, 0x7f, 0xff, 0xa9, 0xaa, 0x02, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x8f, 0x7f, 0xff, 0x55, 0x51, 0x15, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0xe0, 0x8f, 0x7f, 0xff, 0xa9, 0xaa, 0x02, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0xe0, 0x0f, 0x7f, 0xff, 0x55, 0x51, 0x45, 0x04, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0xe0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0xe0, 0x07, 0x10, 0x11, 0x11, 0x11, 0x11, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0xe0, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0xe0, 0x03, 0x40, 0x44, 0x44, 0x40, 0x04, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0xf8, 0x00, 0x00, 0x11, 0x11, 0x11, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x1f, 0x00, 0x00, 0x40, 0x44, 0x08, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
}; 
