FROM    debian:testing
RUN     apt-get update \
        && apt-get upgrade --yes \
        && apt-get install gcc g++ make git pkg-config libncurses-dev libbsd-dev libcurl4-openssl-dev libopencv-dev libgmp3-dev libgsl-dev libtesseract-dev libzbar-dev deborphan --yes \
        && apt-get autoremove --purge --yes \
        && apt-get purge $( deborphan ) --yes \
        && apt-get autoclean \
        && apt-get clean

# docker container run --user $( id -u ):$( id -g ) --tty --interactive --volume $PWD:$PWD --workdir $PWD --name code alejandrocolomar/debian:testing-code bash
# docker container start code
# docker container exec --user root --workdir $PWD code make install --directory libalx
# docker container exec --user root --tty --interactive --workdir $PWD code bash
# docker container attach code
