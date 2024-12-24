file * fopen(filename,"openmode");（fopen, fdopen, freopen - stream open functions）(The fopen() function opens the file whose name is the string pointed to by pathname and associates a stream with it.)
（mode：r w a w：if not exist will create）
fclose(pointer);（fclose - close a stream）
fread 、 fwrite - 二进制流输入/输出(fread, fwrite - binary stream input/output)
size_t fread(void *pointer,size_t size, size_t nmemb,FILE *stream);




typedef 定义数据类型
stdint.h头文件中  typedef uint8_t  BYTE;
相当于char 但一般来说，处理二进制文件时（二进制文件流），（定义缓冲变量（中间变量）传递数据时）使用 uint8_t（无符号8位整型）会更加直观和清晰
(如果你想创建一个新类型来存储一个字节的数据，你可以通过下面的代码来实现，它定义了一个名为 BYTE a uint8_t 的新类型（在 stdint.h 中定义的类型，表示一个 8 位无符号整数）。

typedef uint8_t BYTE;)

RGBTRIPLE (*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
int a[][10] = malloc();  分配的连续空间，只用储存空间以及a的值（第一个元素的地址）即可 所有的元素均通过该指针偏移量获取
二维数组不是指针数组 在内存中顺序储存，不会为每一行分配单独的指针。访问 i[3][4]，编译器会计算它在内存中的偏移量，而不是通过指针跳转。

int** arr = malloc(10 * sizeof(int*));
for (int i = 0; i < 10; i++) {
    arr[i] = malloc(10 * sizeof(int));
}
指针数组

RGBTRIPLE (*image)[width]：内存可以动态分配，常用于需要灵活调整数组大小的场景。内存是通过 malloc 等函数动态分配的，可以在堆上分配任意大小的数组。
int (*a)[n] a为数组指针 指向数组的指针
RGBTRIPLE image[][width]：这是一个静态声明的数组，内存是在栈上分配的，大小必须在编译时确定。你无法在运行时调整它的大小。

二维数组定义和使用时通常需要指定行和列数
RGBTRIPLE image[height][width];在函数参数中，只需要指定列数，因为行数可以通过其他参数传递

数组指针常用来动态分配二维数组（可以指向一个动态分配的二维数组），适合需要在运行时调整大小，二维数组适合数据大小固定
