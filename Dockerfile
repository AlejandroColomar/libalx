FROM	debian:testing
RUN	apt-get update							&& \
	apt-get upgrade --yes						&& \
	apt-get install gcc g++ make git pkg-config libbsd-dev --yes	&& \
	apt-get install libcurl4-openssl-dev libgmp3-dev --yes		&& \
	apt-get install libgsl-dev libncurses-dev libopencv-dev --yes	&& \
	apt-get install libtesseract-dev libzbar-dev deborphan --yes	&& \
	apt-get autoremove --purge --yes				&& \
	apt-get purge $(deborphan) --yes				&& \
	apt-get autoclean						&& \
	apt-get clean

##
## Use the container to build programs that depend on libalx
## (or to build libalx itself).
## These commands need to be called from the pparent directory where libalx
## and any other programs are.
##
# docker container run --user $(id -u):$(id -g) --tty --interactive --volume $PWD:$PWD --workdir $PWD --name code alejandrocolomar/debian:testing-code bash
# docker container start code
# docker container exec --user root --workdir $PWD code make install --directory libalx
# docker container exec --user root --tty --interactive --workdir $PWD code bash
# docker container attach code
