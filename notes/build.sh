#!/bin/bash

mkdir PDFs

for dir in $(find . -type d); do
	pushd $dir
	if [ -f index.tex ]
	then
		tectonic index.tex
		cp index.pdf ../PDFs/${dir}.pdf
	fi
	popd
done