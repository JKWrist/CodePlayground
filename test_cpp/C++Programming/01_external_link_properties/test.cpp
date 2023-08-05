
//   "_g_b", referenced from:
//       _main in external_link-c61e8b.o
// ld: symbol(s) not found for architecture x86_64
// clang: error: linker command failed with exit code 1 (use -v to see invocation)

extern const int g_b = 1000;
//extern 得写，要不const 修饰完，外部找不到这个符号