#ifndef FIRE_TYPES_H
#define FIRE_TYPES_H
// header that contains types

//denotes the max integer that can represent a binary type
#define FireType_MAX 1

enum FireType
{
        FireType_null, //not a true type, denotes null byte or non-type
        FireType_Number
};

typedef enum FireType FireType;

static inline int
FireType_is_type(unsigned int type)
{
        return type <= FireType_MAX;
}

static inline void
FireType_write(void* buf, FireType type)
{
        *(unsigned char*)buf = type;
}

#endif
