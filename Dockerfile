FROM ubuntu:latest

LABEL maintainer Filippo Valle
LABEL org.opencontainers.image.source https://github.com/fvalle1/fastDiverse

RUN apt update
RUN apt install software-properties-common --yes
RUN apt install libboost-all-dev --yes
RUN apt install g++ make cmake>=1.18 --yes
RUN apt install python3-pip --yes
COPY requirements.txt .
RUN python3 -m pip install --no-cache-dir -U -r requirements.txt

WORKDIR /home

ENTRYPOINT /bin/bash 
CMD [""]
