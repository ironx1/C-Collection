#ifndef GENERIC_ALLOCATE_H
#define GENERIC_ALLOCATE_H

#define newNumM(type)                            \
    static void *new_##type(type val)             \
    {                                             \
        type *ptr = (type *)malloc(sizeof(type)); \
        if (ptr == (void *)0)                     \
            return (void *)0;                     \
        *ptr = val;                               \
        return ptr;                               \
    }

#define newStrM()                                       \
    static void *new_charset(char *string)                   \
    {                                                        \
        if (string == (void *)0)                             \
            return (void *)0;                                \
        size_t len = strlen(string);                         \
        char *pc = (char *)malloc(sizeof(char) * (len + 1)); \
        if (pc == (void *)0)                                 \
            return (void *)0;                                \
        strcpy_s(pc, len + 1, string);                       \
        return pc;                                           \
    }

#define compareNumM(type)                      \
    int compare_##type(void *obj1, void *obj2) \
    {                                          \
        if (*(type *)obj1 == *(type *)obj2)    \
            return 1;                          \
        return 0;                              \
    }

#define compareStrM                                 \
    int compare_str(void *obj1, void *obj2)         \
    {                                               \
        int r = strcmp((char *)obj1, (char *)obj2); \
        if (r == 0)                                 \
            return 1;                               \
        return 0;                                   \
    }

#define compareFieldsStrM(class, field)                \
    int compare_fields_str(void *classObj, void *data) \
    {                                                  \
        class *obj = classObj;                         \
        int r = strcmp(obj->field, (char *)data);      \
        if (r == 0)                                    \
            return 1;                                  \
        return 0;                                      \
    }

#define compareFieldsNumM(class, field, type)             \
    int compare_fields_##type(void *classObj, void *data) \
    {                                                     \
        class *obj = classObj;                            \
        if (obj->field == *(type *)data)                  \
            return 1;                                     \
        return 0;                                         \
    }

#endif