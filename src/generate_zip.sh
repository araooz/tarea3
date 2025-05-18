#!/usr/bin/env bash

project_name='prog3_unit2_standar_library_v2022_1'
source_code='
        p1.h p1.cpp
        p2.h p2.cpp
        p3.h p3.cpp
        p4.h p4.cpp
        p5.h p5.cpp
        p6.h p6.cpp
        p7.h p7.cpp
        p8.h p8.cpp
        p9.h p9.cpp
  '
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}