FROM ubuntu:18.04

# Update Repos
RUN apt-get -y update

# C & C++ Compiler & Debugger
RUN apt-get install -y gcc g++ make nano
RUN apt-get install -y gdb ltrace strace

# Python & Utilities
RUN apt-get install -y python python-pip
RUN apt-get install -y python3 python3-pip
RUN apt-get install -y python-dev
RUN pip3 install virtualenv virtualenvwrapper
RUN pip install pwn

ENV VIRTUALENVWRAPPER_PYTHON=/usr/bin/python3
ENV VIRTUALENVWRAPPER_VIRTUALENV=/usr/local/bin/virtualenv
RUN echo "source /usr/local/bin/virtualenvwrapper.sh 1>&2 2>/dev/null" >> /root/.bashrc

# PHP 
ENV TZ="Asia/Kolkata"
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get install -y php

# Utilities
RUN apt-get install -y git curl wget sshpass netcat

# Environment Variables
ENV PATH=/code/:$PATH

# Working Directory
WORKDIR /code
