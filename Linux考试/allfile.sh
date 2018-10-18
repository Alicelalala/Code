#!/bin/bash

rm -rf allpi.log
for i in `seq 0 8`; do
    cat pi$i.log >>allpi.log
done

