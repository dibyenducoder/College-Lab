#!/bin/bash

echo "The number of disk blocks occupied by the file is:"
stat -c "%b" $1