#define x_width_npb 128
#define x_height_npb 64
static char x_bits_npb[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf1, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0xe4, 0xff, 0x07, 0x00, 0x00, 0x00, 0x38, 
0x00, 0x30, 0x00, 0x00, 0xc0, 0x00, 0x00, 0xc0, 0x31, 0xe7, 0xe3, 0x07, 0x00, 0x00, 0x00, 0x18, 
0x00, 0x30, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x20, 0x91, 0xf7, 0xf3, 0x03, 0x00, 0x00, 0x00, 0x0c, 
0x00, 0x18, 0x00, 0x00, 0x60, 0x00, 0x00, 0x90, 0xc9, 0xfa, 0xf1, 0x01, 0x00, 0x00, 0x00, 0x04, 
0x00, 0x08, 0x00, 0x00, 0x20, 0x00, 0x00, 0x80, 0x4c, 0xfc, 0xf9, 0x01, 0x00, 0x00, 0x00, 0x06, 
0x00, 0x0c, 0x00, 0x00, 0x10, 0x00, 0x00, 0xc0, 0xec, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x02, 
0x00, 0x06, 0x00, 0x00, 0x18, 0x00, 0x00, 0x40, 0xfe, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x03, 
0x00, 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x60, 0xee, 0x7f, 0x7e, 0x00, 0x00, 0x00, 0x80, 0x01, 
0x00, 0x83, 0xf3, 0x80, 0xec, 0x80, 0x0f, 0x30, 0xc7, 0x6f, 0x62, 0xf8, 0x01, 0xfc, 0x80, 0x7e, 
0x00, 0x41, 0x9f, 0xc1, 0x7f, 0xe0, 0x18, 0x30, 0xcb, 0x07, 0x30, 0x0e, 0x03, 0x87, 0xc1, 0xc3, 
0x80, 0x21, 0x83, 0x01, 0x02, 0x30, 0x10, 0x98, 0xcd, 0x9f, 0x1f, 0x03, 0x82, 0x01, 0xc1, 0xc0, 
0x80, 0x80, 0x81, 0x01, 0x01, 0x18, 0x10, 0xc8, 0xe7, 0xcf, 0x9f, 0x01, 0xc2, 0x10, 0x61, 0xc0, 
0xc0, 0x80, 0x80, 0x81, 0x01, 0x0c, 0x18, 0xcc, 0xe7, 0xcf, 0xcf, 0x00, 0x63, 0xf8, 0x30, 0x40, 
0x60, 0xc0, 0x80, 0x80, 0x00, 0xfe, 0x0f, 0xe6, 0xe3, 0xe7, 0xcf, 0xff, 0x71, 0x70, 0x30, 0x60, 
0x60, 0x60, 0xc0, 0xc0, 0x00, 0x03, 0x00, 0xe6, 0xf1, 0x73, 0x67, 0x00, 0x30, 0x00, 0x18, 0x60, 
0x30, 0x60, 0x40, 0x60, 0x0e, 0xc3, 0x01, 0xf3, 0xf9, 0x33, 0x36, 0x38, 0x18, 0x00, 0x08, 0x30, 
0x18, 0x30, 0x60, 0x20, 0x88, 0x61, 0x03, 0xf3, 0xf8, 0x39, 0x32, 0x6c, 0x18, 0x00, 0x0c, 0x10, 
0x18, 0x18, 0x20, 0x30, 0x8c, 0x31, 0x82, 0xf9, 0xfc, 0x78, 0x3b, 0x46, 0x0c, 0x30, 0x86, 0x19, 
0x0c, 0x18, 0x30, 0x18, 0x82, 0x31, 0xc3, 0x7c, 0xfc, 0x9c, 0x39, 0x66, 0x0c, 0x18, 0xc6, 0x0c, 
0x0e, 0x0c, 0x18, 0x38, 0x81, 0xc3, 0xe1, 0x3c, 0x7e, 0xcc, 0x78, 0x38, 0x1c, 0x0c, 0xc3, 0x06, 
0x0f, 0x0e, 0x18, 0xf0, 0x00, 0x7f, 0x60, 0x1e, 0x7e, 0xe0, 0xf0, 0x07, 0xf8, 0x87, 0x83, 0x03, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0xfe, 0xff, 0x78, 0xe0, 0x01, 0xe0, 0xc3, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x80, 0xe3, 0x3f, 0x80, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x9f, 0xe3, 0x3f, 0x9c, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x9f, 0xe3, 0x3f, 0x9e, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x9f, 0xe3, 0x3f, 0xfe, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x9f, 0xe3, 0x3f, 0xfe, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x9f, 0xe3, 0x3f, 0xfe, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x8f, 0xe3, 0x3f, 0xfe, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x03, 0x1c, 0xe0, 0x00, 0x07, 0x38, 0x80, 0xe3, 0x3f, 0xfe, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xc3, 0xdd, 0xe3, 0x70, 0x87, 0x3b, 0x80, 0xe3, 0x3f, 0xfe, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xe3, 0xfd, 0xe3, 0x78, 0xc7, 0x3b, 0xfe, 0xe3, 0x3f, 0xfe, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xe3, 0xfd, 0xe3, 0x78, 0xc7, 0x3b, 0xfe, 0xe3, 0x3f, 0xfe, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xe3, 0x1d, 0xe0, 0x78, 0xc7, 0x3b, 0xfe, 0xe3, 0x3f, 0xfe, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xe3, 0xdd, 0xe3, 0x78, 0xc7, 0x3b, 0xfe, 0xc3, 0x3f, 0xbe, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xe3, 0xdd, 0xe3, 0x78, 0xc7, 0x39, 0xfe, 0x03, 0x38, 0x9e, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xe3, 0x1d, 0xe0, 0x78, 0x07, 0x38, 0xfe, 0x03, 0x38, 0x80, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xc7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xb3, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x67, 0xe5, 0x93, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x67, 0xe7, 0xa3, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x67, 0xe7, 0xb3, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xaf, 0x67, 0xb2, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x43, 0xc6, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
}; 
