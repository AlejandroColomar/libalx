FROM    debian:testing
RUN     apt-get update \
        && apt-get upgrade --yes \
        && apt-get install gcc g++ make git pkg-config libncurses-dev libbsd-dev libcurl4-openssl-dev libopencv-dev libgmp3-dev libgsl-dev libtesseract-dev libzbar-dev deborphan --yes \
        && apt-get autoremove --purge --yes \
        && apt-get purge $( deborphan ) --yes \
        && apt-get autoclean \
        && apt-get clean

# docker container run --interactive --tty --user $( id -u ):$( id -g ) --volume $PWD:$PWD --rm alejandrocolomar/debian:testing-code bash
