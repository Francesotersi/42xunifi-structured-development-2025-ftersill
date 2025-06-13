#ifndef GRADE_MAPPING_H
# define GRADE_MAPPING_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum {PLUSMINUS, STANDARD, PASSFAIL} GradeMapperType;

typedef struct GradeMapper
{
    GradeMapperType mapper;

} GradeMapper;


void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

#endif