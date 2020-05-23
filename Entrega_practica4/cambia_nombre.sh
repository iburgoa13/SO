#!/bin/bash

for file in $1/*
do
	mv "$file" "${file}"."$2"
done
