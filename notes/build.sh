#!/bin/bash

for dir in $(find . -type d); do
	pushd $dir
	if [ -f index.tex ]
	then
		tectonic index.tex
	fi
	popd
done