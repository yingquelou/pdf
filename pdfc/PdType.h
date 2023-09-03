#ifndef PDTYPE_H
#define PDTYPE_H 1
#include <stdbool.h>
enum PdTypeInfo
{
    pdBooleanType,
    pdIntegerType,
    pdRealType,
    pdStringType,
    pdNameType,
    pdArrayType,
    pdDictionaryType,
    pdStreamType,
    pdObjsXrefNumType
};
// base type - null object
#define pdnull ((void *)0)
// base type - Boolean
typedef bool pdBoolean, *PdBoolean;
// base type - Integer
typedef long long pdInteger, *PdInteger;
// base type - Real numbers
typedef long double pdReal, *PdReal;
#include <stdio.h>
// base type - strings
typedef struct pdString
{
    // 字符(串)序列大小长度
    size_t length;
    // 表示是否是十六进制字符(串)序列
    bool isHex;
    // 字符(串)序列
    char *str;
} pdString, *PdString;
// base type - Name
// 注意:名字类型要么都是动态分配,要么都不是
typedef char *PdName;
// 任意pdf类型对象的引用
typedef struct pdObj
{
    // 指向任意pdf类型对象
    void *obj;
    // 该对象的类型信息
    PdTypeInfo typeInfo;
} pdObj, *PdObj;
// 与交叉引用表条目相对应
typedef struct pdObjsXrefNum
{
    unsigned long long objectNumber;
    unsigned long long generation;
} pdObjsXrefNum, *PdObjsXrefNum;

// pdf主体的基本单元 - Indirect Objects
// 即表示整个
// n1 n2 obj
// ...
// endobj
// 对象
typedef struct pdObjs
{
    // 当前对象在交叉引用表的编号信息
    pdObjsXrefNum xrefNum;
    // 持有当前对象的所有
    // 内嵌对象
    PdObj objs;
    // 内嵌对象的数量
    size_t num;
} pdObjs, *PdObjs;
typedef struct pdArray
{
    size_t size;
    PdObj arr;
} pdArray, *PdArray;
typedef struct pdDictionaryEntry
{
    PdObj key;
    PdObj value;
} pdDictionaryEntry, *PdDictionaryEntry;

typedef struct pdDictionary
{
    size_t size;
    PdDictionaryEntry entries;
} pdDictionary, *PdDictionary;
typedef struct pdStream
{
    // name or array
    PdObj Filter;
    // name or array
    PdObj FFilter;
    // dictionary or array
    PdObj DecodeParms;
    // dictionary or array
    PdObj FDecodeParms;
    pdInteger Length;
    pdInteger DL;
    FILE *F;
    char *stream;
} pdStream, *PdStream;
#endif