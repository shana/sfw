#!/bin/sh

autoreconf  -i --force --warnings=error
./configure --enable-maintainer-mode $*
