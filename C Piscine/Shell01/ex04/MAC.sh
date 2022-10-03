#!/bin/bash
ifconfig | grep "ether" | sed "s/.ether//" | sed "s/        //" | sed "s/ .*//"
