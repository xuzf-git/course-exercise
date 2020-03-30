///////////////////////////////////////////////////////
// CLib.h
// Header file for a C-like library
// An array-like entity created at runtime

typedef struct CStashTag
{
  int size;     // Size of each space
  int quantity; // Number of storage spaces
  int next;     // Next empty space
  unsigned char *storage;
} CStash;

void initialize(CStash *s, int size); // 初始化
void cleanup(CStash *s); // 清理存储空间
int add(CStash *s, const void *element); // 新添加一个元素
void *fetch(CStash *s, int index);
int count(CStash *s);
void inflate(CStash *s, int increase);
///:~
