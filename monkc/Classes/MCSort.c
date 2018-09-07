//
//  MCSort.c
//  Sapindus
//
//  Created by Sun YuLi on 2016/11/5.
//  Copyright © 2016年 oreisoft. All rights reserved.
//

#include "MCSort.h"

//class(MCSort, MCObject,
//      int* array;
//      size_t size);

oninit(MCSort)
{
    if (init(MCObject)) {
        var(array) = null;
        var(length) = 0;
        return obj;
    }else{
        return null;
    }
}

fun(MCSort, void, bye, voida)
{
    if (obj->array && obj->length > 0) {
        free(obj->array);
    }
}

fun(MCSort, MCSort*, initWithArray, MCGeneric* array, size_t length)
{
    var(array) = (MCGeneric*)malloc(sizeof(MCGeneric) * length);
    for (size_t i=0; i<length; i++) {
        obj->array[i] = array[i];
    }
    var(length) = length;
    //debug
    //ff(obj, printArray, 0);
    return obj;
}

ifun(void, swap, size_t a, size_t b)
{
    as(MCSort);
    if (a < b) {
        MCGeneric t = obj->array[a];
        obj->array[a] = obj->array[b];
        obj->array[b] = t;
    }
}

fun(MCSort, void, insertionSort, voida)
{
    
}

ifun(void, quicksort, const size_t l, const size_t r)
{
    as(MCSort);
    if (l >= r || l > obj->length || r > obj->length) {
        //debug_log("quicksort exit l=%ld r=%ld\n", l, r);
        return;
    }
    MCGeneric pivot = obj->array[l];
    size_t cur=l;
    for (size_t idx=l+1; idx<=r; idx++) {
        if (MCGenericCompare(obj->array[idx], pivot) < 0)
            swap(obj, ++cur, idx);
    }
    
    swap(obj, l, cur);
    quicksort(obj, l, cur-1);
    quicksort(obj, cur+1, r);
}

fun(MCSort, void, quickSort, voida)
{
    quicksort(obj, 0, var(length)-1);
}

fun(MCSort, void, printArray, voida)
{
    for (size_t i=0; i<obj->length; i++) {
        printf("element of array[%ld]=%.2f\n", i, obj->array[i].mcfloat);
    }
}

onload(MCSort)
{
    if (load(MCObject)) {
        bid(MCSort, void, bye, voida);
        bid(MCSort, MCSort*, initWithArray, MCGeneric* array, size_t length);
        bid(MCSort, void, insertionSort, voida);
        bid(MCSort, void, quickSort, voida);
        bid(MCSort, void, printArray, voida);
        return cla;
    }else{
        return null;
    }
}


