#include "circular_buffer.h"
#include <stdlib.h>
#include <stdio.h>


int circular_buffer_create(struct circular_buffer_t *a, int N) {
    if (a == NULL || N <= 0) {
        return 1;
    }
    a->ptr = malloc(N * sizeof(int));
    if (a->ptr == NULL) {
        return 2;
    }
    a->capacity = N;
    a->full = 0;
    a->begin = 0;
    a->end = 0;
    return 0;
}

int circular_buffer_create_struct(struct circular_buffer_t **cb, int N) {
    if (cb == NULL || N <= 0) {
        return 1;
    }
    *cb = (struct circular_buffer_t*) malloc(sizeof(struct circular_buffer_t));
    if (*cb == NULL) {
        return 2;
    }

    int err = circular_buffer_create(*cb, N);
    if (err == 2) {
        circular_buffer_destroy_struct(cb);
        return 2;
    }
    return 0;
}

void circular_buffer_destroy(struct circular_buffer_t *a) {
    if (a != NULL) {
        free(a->ptr);
    }
}

void circular_buffer_destroy_struct(struct circular_buffer_t **a) {
    if (a != NULL && *a != NULL) {
        circular_buffer_destroy(*a);
        free(*a);
    }
}


int circular_buffer_push_back(struct circular_buffer_t *cb, int value) {
    if (cb == NULL || cb->ptr == NULL || cb->capacity <=0 || cb->begin<0||cb->end<0||cb->begin>=cb->capacity||cb->end>=cb->capacity) {
        return 1;
    }

    if (cb->full) {
        *(cb->ptr+cb->begin) = value;
        cb->begin = (cb->begin + 1) % cb->capacity;
        cb->end = (cb->end + 1) % cb->capacity;
    } else {
        *(cb->ptr+cb->end) = value;
        cb->end = (cb->end + 1) % cb->capacity;
        if (cb->begin == cb->end) {
            cb->full = 1;
        }
    }

    return 0;
}


int circular_buffer_pop_front(struct circular_buffer_t *a, int *err_code) {
    if (a == NULL || a->ptr == NULL || a->capacity <=0 || a->begin<0||a->end<0||a->begin>=a->capacity||a->end>=a->capacity) {
        if (err_code != NULL) {
            *err_code = 1;
        }
        return 0;
    }

    if (circular_buffer_empty(a)) {
        if (err_code != NULL) {
            *err_code = 2;
        }
        return 0;
    }

    int val = *((a->ptr) + a->begin);
    a->begin = (a->begin + 1) % a->capacity;
    a->full = 0;

    if (err_code != NULL) {
        *err_code = 0;
    }
    return val;
}


int circular_buffer_pop_back(struct circular_buffer_t *a, int *err_code) {
    if (a == NULL || a->ptr == NULL || a->capacity <=0 || a->begin<0||a->end<0||a->begin>=a->capacity||a->end>=a->capacity) {
        if (err_code != NULL) {
            *err_code = 1;
        }
        return 0;
    }
    if (circular_buffer_empty(a)) {
        if (err_code != NULL) {
            *err_code = 2;
        }
        return 0;
    }
    int val = *((a->ptr) + (a->end - 1 + a->capacity) % a->capacity);
    a->end = (a->end - 1 + a->capacity) % a->capacity;
    a->full = 0;
    if (err_code != NULL) {
        *err_code = 0;
    }
    return val;
}


int circular_buffer_empty(const struct circular_buffer_t *a) {
    if (a == NULL || a->ptr == NULL || a->capacity <=0 || a->begin<0||a->end<0||a->begin>=a->capacity||a->end>=a->capacity) {
        return -1;
    }
    if (a->begin == a->end&&a->full==0) {
        return 1;
    } else {
        return 0;
    }
}

int circular_buffer_full(const struct circular_buffer_t *a) {
    if (a == NULL || a->ptr == NULL || a->capacity <=0 || a->begin<0||a->end<0||a->begin>=a->capacity||a->end>=a->capacity) {
        return -1;
    }
    if (a->full == 1) {
        return 1;
    } else {
        return 0;
    }
}

void circular_buffer_display(const struct circular_buffer_t *a) {
    if(a==NULL) {
        return;
    }
    if (!(a->ptr == NULL || a->capacity <=0 || a->begin<0||a->end<0||a->begin>=a->capacity||a->end>=a->capacity) && !circular_buffer_empty(a)) {
        if(a->begin>=a->end) {
            for (int i = a->begin; i < a->capacity; ++i) {
                printf("%d ",*((a->ptr)+i));
            }
            for (int i = 0; i < a->end; ++i) {
                printf("%d ",*((a->ptr)+i));
            }
        } else {
            for (int i = a->begin; i < a->end; ++i) {
                printf("%d ",*((a->ptr)+i));
            }
        }
        printf("\n");
    }
}
